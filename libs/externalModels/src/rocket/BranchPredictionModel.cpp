/*
 * Copyright 2022 Chair of EDA, Technical University of Munich
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// TODO: Proof-of-concept model, taken from Robert (more or less)!

#include "models/rocket/BranchPredictionModel.h"

#include <cstdint>

namespace rocket{

// TODO: Find a better way to define this constant!?
#define INVALID_BRANCH_ADDRESS 0xFFFFFFFFFFFFFFFF

uint8_t BranchHistoryTable::hashHistory(void)
{
  return (uint8_t)((((uint16_t)222 * history) >> (HISTORY_LENGTH - HISTORY_BITS)) & ((1 << HISTORY_BITS) - 1));
}

int BranchHistoryTable::getIndex(uint64_t pc_)
{
  uint64_t hi = pc_ >> 2;
  uint64_t hashAddr = (hi & (ENTRIES - 1)) ^ ((hi >> 9) & 0x3);
  return (int)((hashAddr ^ ((uint64_t)hashHistory() << (9 - HISTORY_BITS))) & (ENTRIES - 1));
}

void BranchHistoryTable::advanceHistory(bool taken_)
{
  history = (uint8_t)(((taken_ ? 1 : 0) << (HISTORY_LENGTH - 1)) | (history >> 1));
}

bool BranchHistoryTable::getPrediction(uint64_t pc_, uint64_t imm_)
{
  (void)imm_;
  return tab[getIndex(pc_)].counter == 3;
}

void BranchHistoryTable::update(uint64_t pc_, bool taken_)
{  
  auto& counter = tab[getIndex(pc_)].counter;
  if (taken_) {
    if (counter < 3) {
      counter++;
    }
  } else if (counter > 0) {
    counter--;
  }
  advanceHistory(taken_);
}

void ReturnAddressStack::push(uint64_t ra_)
{
  if (count < ENTRIES) {
    count++;
  }
  pos = (pos + 1) % ENTRIES;
  stack[pos].addr = ra_;
  stack[pos].valid = true;
}

uint64_t ReturnAddressStack::pop(void)
{
  uint64_t ret = (count > 0 && stack[pos].valid) ? stack[pos].addr : INVALID_BRANCH_ADDRESS;

  if (count > 0) {
    stack[pos].valid = false;
    count--;
    pos = (pos == 0) ? ENTRIES - 1 : pos - 1;
  }
  
  return ret;
}

uint64_t BranchTargetBuffer::getPrediction(uint64_t pc_)
{
  for (const auto& entry : tab) {
    if(entry.valid && entry.pc == pc_)
    {
      return entry.addr;
    }
  }
  return INVALID_BRANCH_ADDRESS;
}

void BranchTargetBuffer::update(uint64_t pc_, uint64_t taddr_)
{
  int index = -1;
  for (int i = 0; i < ENTRIES; ++i) {
    if (tab[i].valid && tab[i].pc == pc_) {
      index = i;
      break;
    }
    if (!tab[i].valid && index == -1) {
      index = i;
    }
  }
  if (index == -1) {
    index = nextRepl;
    nextRepl = (nextRepl + 1) % ENTRIES;
  }
  tab[index].valid = true;
  tab[index].pc = pc_;
  tab[index].addr = taddr_;
}


void BranchPredictionModel::setPc_p(uint64_t pc_p_)
{
  branch_flag = true;
  branchPc = pc_ptr[getInstrIndex()];
  branchTarget = brTarget_ptr[getInstrIndex()];
  branchPredictedTaken = bht.getPrediction(branchPc, imm_ptr[getInstrIndex()]);
  t_pc_pt = pc_p_;  
}

void BranchPredictionModel::setPc_p_j(uint64_t pc_p_)
{
  jump_flag = true;

  if(isCall())
  {
    // TODO: Different handling for compressed
    ras.push(pc_ptr[getInstrIndex()] + 4);
  }

  t_pc_pt = pc_p_;
}

void BranchPredictionModel::setPc_p_jr(uint64_t pc_p_)
{
  jumpR_flag = true;

  if(isCall() | isReturn())
  {
    branchTarget = INVALID_BRANCH_ADDRESS;
    
    if(isReturn())
    {
      return_flag = true;
      branchTarget = ras.pop();
    }
          
    if(isCall())
    {
      // TODO: Different handling for compressed
      ras.push(pc_ptr[getInstrIndex()] + 4);
    }
  }

  // JumpR if not call or return
  else
  {
    branchPc = pc_ptr[getInstrIndex()];
    branchTarget = btb.getPrediction(branchPc);
  }

  t_pc_pt = pc_p_;
}

// Return t_pc_mp in case of mispredict, else 0
// Do evalutation and updates here, as this function is always called before getPc_pt
uint64_t BranchPredictionModel::getPc_mp(void)
{
  isMispredict = false;
  isTaken = false;
  
  // Check if previous instr was a branch
  if(branch_flag)
  {
    // Determine if branch was taken
    uint64_t curPc = pc_ptr[getInstrIndex()];
    isTaken = (curPc == branchTarget);
    
    // Determine if branch was mispredicted
    isMispredict = branchPredictedTaken != isTaken;
    
    // Update BHT/history for every resolved conditional branch.
    bht.update(branchPc, isTaken);
    
    // In case of mispredict: Return time when corrected address is available (t_pc_mp)
    if(isMispredict)
    {
      return t_pc_mp;
    }
  }

  // Check if previous instr was jump with immediate base
  else if(jump_flag)
  {
    isTaken = true; // used for info prints
  }
  
  // Check if previous instr was jump with register base
  else if(jumpR_flag)
  {
    // For a jump, branch is always taken
    isTaken = true; // Used for info print
    
    // Determine if branch was mispredicted
    uint64_t curPc = pc_ptr[getInstrIndex()];
    isMispredict = (curPc != branchTarget);

    // Update BTB
    if(isMispredict & !return_flag)
    {
      btb.update(branchPc, curPc);
    }
    
    // On mispredict: Return time when corrected address is available (t_pc_mp)
    if(isMispredict)
    {
      return t_pc_mp;
    }
  }
  
  // Default: Branch/Jump was not mispredicted
  return 0; // Use 0 to disregard the pc_mp connector in any max operation
}

// Return t_pc_pt in case of a correctly predicted taken branch / jump, else 0
// Clear all flags here, as it is always called after getPc_mp
uint64_t BranchPredictionModel::getPc_pt(void)
{
  // In case of branch: Check if corretly predicted and taken
  if(branch_flag)
  {
    branch_flag = false;
    if(!isMispredict & isTaken)
    {
      pc_pt = t_pc_pt;
      return t_pc_pt;
    }   
  }

  // In case of (only imm-dependent) jump: Always taken
  if(jump_flag)
  {
    jump_flag = false;
    pc_pt = t_pc_pt;
    return t_pc_pt;
  }

  // In case of register-base jump
  if(jumpR_flag)
  {
    jumpR_flag = false;
    return_flag = false;
    if(!isMispredict)
    {
      pc_pt = t_pc_pt;
      return t_pc_pt;
    }
  }
  
  // Default: Branch/Jump was not correctly predicted
  pc_pt = 0;
  return 0; // Use 0 to disregard the pc_pt connector in any max operation
}

} // namespace rocket
