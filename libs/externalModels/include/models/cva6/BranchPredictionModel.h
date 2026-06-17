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

#ifndef CVA6_BRANCH_PREDICTION_MODEL_H
#define CVA6_BRANCH_PREDICTION_MODEL_H

#include <stdbool.h>
#include <array>
#include <cstdint>
#include <string>

#include "PerformanceModel.h"

namespace cva6{

class PredictFsm
{
public:
  PredictFsm(){};
  bool getPrediction(void);
  void update(bool);
private:
  enum state_t {STRONG_NOT_TAKEN, WEAK_NOT_TAKEN, WEAK_TAKEN, STRONG_TAKEN};
  state_t RESET_STATE = STRONG_NOT_TAKEN;
  state_t FLUSH_STATE = WEAK_TAKEN; 
  state_t state = RESET_STATE;
};


struct BranchHistoryEntry
{
  bool valid = false;
  PredictFsm state;
};


class BranchHistoryTable
{
public:
  BranchHistoryTable(){};
  bool getPrediction(uint64_t, uint64_t);
  void update(uint64_t, bool);
private:
  std::array<std::array<BranchHistoryEntry, 64>, 2> tab;
  int getPageIndex(uint64_t pc_) { return ((pc_ & 0x00000002) >> 1); };
  int getRowIndex(uint64_t pc_) { return ((pc_ & 0x000000FC) >> 2); };
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
  std::array<ReturnAddressEntry,2> stack;
};


struct TargetBufferEntry
{
  bool valid = false;
  uint64_t addr = 0;
};

class BranchTargetBuffer
{
public:
  BranchTargetBuffer(){};
  uint64_t getPrediction(uint64_t);
  void update(uint64_t, uint64_t);
private:
  std::array<std::array<TargetBufferEntry,16>,2> tab;
  int getPageIndex(uint64_t pc_) { return ((pc_ & 0x00000002) >> 1); };
  int getRowIndex(uint64_t pc_) { return ((pc_ & 0x0000003C) >> 2); };
};

  
class BranchPredictionModel : public ConnectorModel
{
public:
  BranchPredictionModel(PerformanceModel* parent_) : ConnectorModel("CVA6_BranchPredictionModel", parent_), bht(), ras(), btb() {};
   
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
  //std::string getInfo_predictedTaken(void) { return std::to_string(branchPredictedTaken); };
  //std::string getInfo_pc_pt(void) { return std::to_string(t_pc_pt); };
  //std::string getInfo_pc_mp(void) { return std::to_string(t_pc_mp); };

  uint64_t getTrace_isControl(void) { return trace_isControl ? 1 : 0; };
  uint64_t getTrace_taken(void) { return trace_taken ? 1 : 0; };
  uint64_t getTrace_predictedTaken(void) { return trace_predictedTaken ? 1 : 0; };
  uint64_t getTrace_mispredict(void) { return trace_mispredict ? 1 : 0; };
  uint64_t getTrace_predictedTarget(void) { return trace_predictedTarget; };
  uint64_t getTrace_actualTarget(void) { return trace_actualTarget; };
  std::string getTrace_predictorComponent(void) { return trace_predictorComponent; };
  uint64_t getTrace_redirectSourcePc(void) { return trace_redirectSourcePc; };
  uint64_t getTrace_redirectSourceTypeId(void) { return trace_redirectSourceTypeId; };
  std::string getTrace_redirectSourceComponent(void) { return trace_redirectSourceComponent; };
  void clearTraceInfo(void);
  
  // Trace values
  uint64_t* pc_ptr;
  uint64_t* brTarget_ptr;
  uint64_t* imm_ptr;
  uint64_t* rs1_ptr;
  uint64_t* rd_ptr;
  uint64_t* typeId_ptr;
  
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

  bool trace_isControl = false;
  bool trace_taken = false;
  bool trace_predictedTaken = false;
  bool trace_mispredict = false;
  uint64_t trace_predictedTarget = 0;
  uint64_t trace_actualTarget = 0;
  std::string trace_predictorComponent = "none";

  uint64_t trace_redirectSourcePc = 0;
  uint64_t trace_redirectSourceTypeId = 0;
  std::string trace_redirectSourceComponent = "none";

  uint64_t pendingSourcePc = 0;
  uint64_t pendingSourceTypeId = 0;
  std::string pendingSourceComponent = "none";
  
  bool isCall(void) { return ( (rd_ptr[getInstrIndex()] == 1) | (rd_ptr[getInstrIndex()] == 5) ); };
  bool isReturn(void) {return ( (rs1_ptr[getInstrIndex()] != rd_ptr[getInstrIndex()]) & ((rs1_ptr[getInstrIndex()] == 1) | (rs1_ptr[getInstrIndex()] == 5)) ); };
  
  // TODO: Use for model evaluation. DELETE!
  uint64_t pc_pt = 0;
  
};

} // namespace cva6
  
#endif //CVA6_BRANCH_PREDICTION_MODEL_H
