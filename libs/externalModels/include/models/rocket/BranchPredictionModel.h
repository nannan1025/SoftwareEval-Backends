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

#ifndef ROCKET_BRANCH_PREDICTION_MODEL_H
#define ROCKET_BRANCH_PREDICTION_MODEL_H

#include <stdbool.h>
#include <array>
#include <cstdint>

#include "PerformanceModel.h"

namespace rocket{

struct BranchHistoryEntry
{
  // 2-bit saturating counter: 0/1 predict not-taken, 2/3 predict taken.
  uint8_t counter = 1;
};


class BranchHistoryTable
{
public:
  BranchHistoryTable(){};
  bool getPrediction(uint64_t, uint64_t);
  void update(uint64_t, bool);
private:
  static constexpr int ENTRIES = 512;
  static constexpr int HISTORY_LENGTH = 8;
  static constexpr int HISTORY_BITS = 3;
  std::array<BranchHistoryEntry, ENTRIES> tab;
  uint8_t history = 0;
  int getIndex(uint64_t);
  uint8_t hashHistory(void);
  void advanceHistory(bool);
};


struct ReturnAddressEntry
{
  bool valid = false;
  uint64_t addr = 0;
};


class ReturnAddressStack
{
public:
  ReturnAddressStack(){};
  void push(uint64_t);
  uint64_t pop(void);
private:
  static constexpr int ENTRIES = 6;
  std::array<ReturnAddressEntry, ENTRIES> stack;
  int count = 0;
  int pos = 0;
};


struct TargetBufferEntry
{
  bool valid = false;
  uint64_t pc = 0;
  uint64_t addr = 0;
};

class BranchTargetBuffer
{
public:
  BranchTargetBuffer(){};
  uint64_t getPrediction(uint64_t);
  void update(uint64_t, uint64_t);
private:
  static constexpr int ENTRIES = 28;
  std::array<TargetBufferEntry, ENTRIES> tab;
  int nextRepl = 0;
};

  
class BranchPredictionModel : public ConnectorModel
{
public:
  BranchPredictionModel(PerformanceModel* parent_) : ConnectorModel("Rocket_BranchPredictionModel", parent_), bht(), ras(), btb() {};
   
  // API
  void setPc_p(uint64_t);
  void setPc_p_j(uint64_t);
  void setPc_p_jr(uint64_t);
  void setPc_c(uint64_t pc_c_) { t_pc_mp = pc_c_; };
  uint64_t getPc_mp(void);
  uint64_t getPc_pt(void);

  // Used for model evaluation TODO: Delete?
  std::string getInfo_mispredict(void) { return std::to_string(isMispredict); };
  std::string getInfo_taken(void) { return std::to_string(isTaken); };
  bool getMispredict(void) const { return isMispredict; };
  //std::string getInfo_predictedTaken(void) { return std::to_string(branchPredictedTaken); };
  //std::string getInfo_pc_pt(void) { return std::to_string(t_pc_pt); };
  //std::string getInfo_pc_mp(void) { return std::to_string(t_pc_mp); };
  
  // Trace values
  uint64_t* pc_ptr;
  uint64_t* brTarget_ptr;
  uint64_t* imm_ptr;
  uint64_t* rs1_ptr;
  uint64_t* rd_ptr;
  
private:
  BranchHistoryTable bht;
  BranchTargetBuffer btb;
  ReturnAddressStack ras;

  bool branch_flag = false;
  uint64_t branchPc = 0; 
  uint64_t branchTarget = 0;
  bool branchPredictedTaken = false;

  bool jump_flag = false;

  bool jumpR_flag = false;
  bool return_flag = false;
  
  uint64_t t_pc_pt = 0; // predicted and taken
  uint64_t t_pc_mp = 0; // mispredicted

  bool isMispredict = false;
  bool isTaken = false;
  
  bool isCall(void) { return ( (rd_ptr[getInstrIndex()] == 1) | (rd_ptr[getInstrIndex()] == 5) ); };
  bool isReturn(void) {return ( (rs1_ptr[getInstrIndex()] != rd_ptr[getInstrIndex()]) & ((rs1_ptr[getInstrIndex()] == 1) | (rs1_ptr[getInstrIndex()] == 5)) ); };
  
  // TODO: Use for model evaluation. DELETE!
  uint64_t pc_pt = 0;
  
};

} // namespace rocket
  
#endif // ROCKET_BRANCH_PREDICTION_MODEL_H
