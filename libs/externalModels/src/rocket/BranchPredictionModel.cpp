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
  lastIndex = getIndex(pc_);
  return tab[lastIndex].prediction;
}

void BranchHistoryTable::update(uint64_t pc_, bool taken_)
{
  lastIndex = getIndex(pc_);
  tab[lastIndex].prediction = taken_;
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
  lastHit = false;
  for (const auto& entry : tab) {
    if(entry.valid && entry.pc == pc_)
    {
      lastHit = true;
      return entry.addr;
    }
  }
  return INVALID_BRANCH_ADDRESS;
}

void BranchTargetBuffer::update(uint64_t pc_, uint64_t taddr_, uint64_t kind_)
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
  tab[index].kind = kind_;
}

void BranchPredictionModel::clearTraceInfo(void)
{
  trace_isControl = false;
  trace_taken = false;
  trace_predictedTaken = false;
  trace_directionMispredict = false;
  trace_targetMispredict = false;
  trace_mispredict = false;
  trace_predictedTarget = 0;
  trace_actualTarget = 0;
  trace_predictorComponent = "none";
  trace_redirectSourcePc = 0;
  trace_redirectSourceComponent = "none";
  trace_btbHit = false;
  trace_bhtIndex = 0;
  trace_rasUsed = false;
}

void BranchPredictionModel::setPc_p(uint64_t pc_p_)
{
  branch_flag = true;
  branchPc = pc_ptr[getInstrIndex()];
  branchTarget = brTarget_ptr[getInstrIndex()];
  branchPredictedTaken = bht.getPrediction(branchPc, imm_ptr[getInstrIndex()]);
  branchBhtIndex = (uint64_t)bht.getLastIndex();

  uint64_t btbTarget = btb.getPrediction(branchPc);
  branchBtbHit = btb.getLastHit();
  branchPredictedTarget = (branchPredictedTaken && branchBtbHit) ? btbTarget : 0;

  trace_isControl = true;
  trace_taken = false;
  trace_predictedTaken = branchPredictedTaken;
  trace_directionMispredict = false;
  trace_targetMispredict = false;
  trace_mispredict = false;
  trace_predictedTarget = branchPredictedTarget;
  trace_actualTarget = 0;
  trace_predictorComponent = branchBtbHit ? "BHT+BTB" : "BHT";
  trace_btbHit = branchBtbHit;
  trace_bhtIndex = branchBhtIndex;
  trace_rasUsed = false;
  pendingSourcePc = branchPc;
  pendingSourceComponent = trace_predictorComponent;
  t_pc_pt = pc_p_;  
}

void BranchPredictionModel::setPc_p_j(uint64_t pc_p_)
{
  jump_flag = true;
  branchPc = pc_ptr[getInstrIndex()];
  branchTarget = brTarget_ptr[getInstrIndex()];
  branchPredictedTaken = true;
  branchPredictedTarget = branchTarget;
  branchBtbHit = true;

  trace_isControl = true;
  trace_taken = true;
  trace_predictedTaken = true;
  trace_directionMispredict = false;
  trace_targetMispredict = false;
  trace_mispredict = false;
  trace_predictedTarget = branchPredictedTarget;
  trace_actualTarget = branchTarget;
  trace_predictorComponent = "JAL";
  trace_btbHit = branchBtbHit;
  trace_bhtIndex = 0;
  trace_rasUsed = false;
  pendingSourcePc = branchPc;
  pendingSourceComponent = trace_predictorComponent;

  if(isCall())
  {
    // TODO: Different handling for compressed instructions.
    ras.push(pc_ptr[getInstrIndex()] + 4);
  }

  t_pc_pt = pc_p_;
}

void BranchPredictionModel::setPc_p_jr(uint64_t pc_p_)
{
  jumpR_flag = true;
  return_flag = false;
  jumpR_ras_used = false;
  jumpR_btb_hit = false;

  branchPc = pc_ptr[getInstrIndex()];
  branchTarget = INVALID_BRANCH_ADDRESS;
  branchPredictedTaken = true;

  const bool call = isCall();
  const bool ret = isReturn();
  jumpR_call = call;

  if(ret)
  {
    return_flag = true;
    jumpR_ras_used = true;
    branchTarget = ras.pop();
    jumpR_btb_hit = (branchTarget != INVALID_BRANCH_ADDRESS);
  }
  else
  {
    branchTarget = btb.getPrediction(branchPc);
    jumpR_btb_hit = btb.getLastHit();
  }

  if(call)
  {
    // TODO: Different handling for compressed instructions.
    ras.push(pc_ptr[getInstrIndex()] + 4);
  }

  branchPredictedTarget = (branchTarget != INVALID_BRANCH_ADDRESS) ? branchTarget : 0;

  trace_isControl = true;
  trace_taken = true;
  trace_predictedTaken = true;
  trace_directionMispredict = false;
  trace_targetMispredict = false;
  trace_mispredict = false;
  trace_predictedTarget = branchPredictedTarget;
  trace_actualTarget = 0;
  trace_predictorComponent = return_flag ? "RAS" : (jumpR_btb_hit ? "BTB" : (call ? "CALL" : "JALR"));
  trace_btbHit = jumpR_btb_hit;
  trace_bhtIndex = 0;
  trace_rasUsed = jumpR_ras_used;
  pendingSourcePc = branchPc;
  pendingSourceComponent = trace_predictorComponent;

  t_pc_pt = pc_p_;
}

// Return t_pc_mp in case of mispredict, else 0.
// Evaluation and updates happen here because this function is always called before getPc_pt.
uint64_t BranchPredictionModel::getPc_mp(void)
{
  isMispredict = false;
  isTaken = false;
  isDirectionMispredict = false;
  isTargetMispredict = false;
  clearTraceInfo();
  
  // Check if previous instr was a conditional branch.
  if(branch_flag)
  {
    uint64_t curPc = pc_ptr[getInstrIndex()];
    isTaken = (curPc == branchTarget);
    uint64_t actualTarget = isTaken ? branchTarget : curPc;

    isDirectionMispredict = (branchPredictedTaken != isTaken);
    isTargetMispredict = branchPredictedTaken && isTaken && (!branchBtbHit || branchPredictedTarget != actualTarget);
    isMispredict = isDirectionMispredict || isTargetMispredict;

    bht.update(branchPc, isTaken);
    if(isTaken && (!branchBtbHit || branchPredictedTarget != actualTarget))
    {
      btb.update(branchPc, actualTarget, CF_BRANCH);
    }

    trace_isControl = true;
    trace_taken = isTaken;
    trace_predictedTaken = branchPredictedTaken;
    trace_directionMispredict = isDirectionMispredict;
    trace_targetMispredict = isTargetMispredict;
    trace_mispredict = isMispredict;
    trace_predictedTarget = branchPredictedTarget;
    trace_actualTarget = actualTarget;
    trace_predictorComponent = branchBtbHit ? "BHT+BTB" : "BHT";
    trace_btbHit = branchBtbHit;
    trace_bhtIndex = branchBhtIndex;
    trace_rasUsed = false;

    if(isMispredict)
    {
      trace_redirectSourcePc = pendingSourcePc;
      trace_redirectSourceComponent = pendingSourceComponent;
    }
    
    if(isMispredict)
    {
      return t_pc_mp;
    }
  }

  // Check if previous instr was jump with immediate base.
  else if(jump_flag)
  {
    uint64_t actualTarget = branchTarget;
    isTaken = true;
    isDirectionMispredict = false;
    isTargetMispredict = false;
    isMispredict = false;

    trace_isControl = true;
    trace_taken = true;
    trace_predictedTaken = true;
    trace_directionMispredict = false;
    trace_targetMispredict = isTargetMispredict;
    trace_mispredict = isMispredict;
    trace_predictedTarget = branchPredictedTarget;
    trace_actualTarget = actualTarget;
    trace_predictorComponent = "JAL";
    trace_btbHit = branchBtbHit;
    trace_bhtIndex = 0;
    trace_rasUsed = false;

    if(isMispredict)
    {
      return t_pc_mp;
    }
  }
  
  // Check if previous instr was jump with register base.
  else if(jumpR_flag)
  {
    uint64_t curPc = pc_ptr[getInstrIndex()];
    isTaken = true;
    isDirectionMispredict = false;
    isTargetMispredict = (branchPredictedTarget == 0 || curPc != branchPredictedTarget);
    isMispredict = isTargetMispredict;

    if(isTargetMispredict && !return_flag)
    {
      btb.update(branchPc, curPc, jumpR_call ? CF_CALL : CF_JALR);
    }

    trace_isControl = true;
    trace_taken = true;
    trace_predictedTaken = true;
    trace_directionMispredict = false;
    trace_targetMispredict = isTargetMispredict;
    trace_mispredict = isMispredict;
    trace_predictedTarget = branchPredictedTarget;
    trace_actualTarget = curPc;
    trace_predictorComponent = pendingSourceComponent;
    trace_btbHit = jumpR_btb_hit;
    trace_bhtIndex = 0;
    trace_rasUsed = jumpR_ras_used;
    
    if(isMispredict)
    {
      trace_redirectSourcePc = pendingSourcePc;
      trace_redirectSourceComponent = pendingSourceComponent;
    }
    
    if(isMispredict)
    {
      return t_pc_mp;
    }
  }
  
  // Default: Branch/Jump was not mispredicted.
  return 0; // Use 0 to disregard the pc_mp connector in any max operation.
}

// Return t_pc_pt in case of a correctly predicted taken branch / jump, else 0.
// Clear all pending control-flow flags here, as this is always called after getPc_mp.
uint64_t BranchPredictionModel::getPc_pt(void)
{
  if(branch_flag)
  {
    branch_flag = false;
    if(isTaken && !isMispredict)
    {
      pc_pt = t_pc_pt;
      return t_pc_pt;
    }
  }

  if(jump_flag)
  {
    jump_flag = false;
    if(!isMispredict)
    {
      pc_pt = t_pc_pt;
      return t_pc_pt;
    }
  }

  if(jumpR_flag)
  {
    jumpR_flag = false;
    return_flag = false;
    jumpR_ras_used = false;
    jumpR_call = false;
    if(!isMispredict)
    {
      pc_pt = t_pc_pt;
      return t_pc_pt;
    }
  }
  
  pc_pt = 0;
  return 0; // Use 0 to disregard the pc_pt connector in any max operation.
}

} // namespace rocket
