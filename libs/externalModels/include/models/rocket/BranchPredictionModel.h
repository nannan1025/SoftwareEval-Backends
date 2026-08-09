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
#include <string>

#include "PerformanceModel.h"

namespace rocket{

enum ControlFlowKind : uint64_t
{
  CF_NONE = 0,
  CF_BRANCH = 1,
  CF_JAL = 2,
  CF_JALR = 3,
  CF_CALL = 4,
  CF_RETURN = 5
};

struct BranchHistoryEntry
{
  // Target RocketConfig uses 1-bit prediction entries.
  bool prediction = false;
};


class BranchHistoryTable
{
public:
  BranchHistoryTable(){};
  bool getPrediction(uint64_t, uint64_t);
  void update(uint64_t, bool);
  int getLastIndex(void) const { return lastIndex; };
private:
  static constexpr int ENTRIES = 512;
  static constexpr int HISTORY_LENGTH = 8;
  static constexpr int HISTORY_BITS = 3;
  std::array<BranchHistoryEntry, ENTRIES> tab;
  uint8_t history = 0;
  int lastIndex = 0;
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
  uint64_t kind = CF_NONE;
};

class BranchTargetBuffer
{
public:
  BranchTargetBuffer(){};
  uint64_t getPrediction(uint64_t);
  void update(uint64_t, uint64_t, uint64_t);
  bool getLastHit(void) const { return lastHit; };
private:
  static constexpr int ENTRIES = 28;
  std::array<TargetBufferEntry, ENTRIES> tab;
  int nextRepl = 0;
  bool lastHit = false;
};

  
class BranchPredictionModel : public ConnectorModel
{
public:
  BranchPredictionModel(PerformanceModel* parent_) : ConnectorModel("Rocket_BranchPredictionModel", parent_), bht(), btb(), ras() {};
   
  // API
  void setPc_p(uint64_t);
  void setPc_p_j(uint64_t);
  void setPc_p_jr(uint64_t);
  void setPc_c(uint64_t pc_c_) { t_pc_mp = pc_c_ + 1; };
  uint64_t getPc_mp(void);
  uint64_t getPc_pt(void);

  // Used for model evaluation TODO: Delete?
  std::string getInfo_mispredict(void) { return std::to_string(isMispredict); };
  std::string getInfo_taken(void) { return std::to_string(isTaken); };
  bool getMispredict(void) const { return isMispredict; };
  //std::string getInfo_predictedTaken(void) { return std::to_string(branchPredictedTaken); };
  //std::string getInfo_pc_pt(void) { return std::to_string(t_pc_pt); };
  //std::string getInfo_pc_mp(void) { return std::to_string(t_pc_mp); };

  uint64_t getTrace_isControl(void) const { return trace_isControl ? 1 : 0; };
  uint64_t getTrace_taken(void) const { return trace_taken ? 1 : 0; };
  uint64_t getTrace_predictedTaken(void) const { return trace_predictedTaken ? 1 : 0; };
  uint64_t getTrace_directionMispredict(void) const { return trace_directionMispredict ? 1 : 0; };
  uint64_t getTrace_targetMispredict(void) const { return trace_targetMispredict ? 1 : 0; };
  uint64_t getTrace_mispredict(void) const { return trace_mispredict ? 1 : 0; };
  uint64_t getTrace_predictedTarget(void) const { return trace_predictedTarget; };
  uint64_t getTrace_actualTarget(void) const { return trace_actualTarget; };
  std::string getTrace_predictorComponent(void) const { return trace_predictorComponent; };
  uint64_t getTrace_redirectSourcePc(void) const { return trace_redirectSourcePc; };
  std::string getTrace_redirectSourceComponent(void) const { return trace_redirectSourceComponent; };
  uint64_t getTrace_btbHit(void) const { return trace_btbHit ? 1 : 0; };
  uint64_t getTrace_bhtIndex(void) const { return trace_bhtIndex; };
  uint64_t getTrace_rasUsed(void) const { return trace_rasUsed ? 1 : 0; };
  void clearTraceInfo(void);
  
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
  uint64_t branchPredictedTarget = 0;
  bool branchBtbHit = false;
  uint64_t branchBhtIndex = 0;

  bool jump_flag = false;

  bool jumpR_flag = false;
  bool return_flag = false;
  bool jumpR_btb_hit = false;
  bool jumpR_ras_used = false;
  bool jumpR_call = false;
  
  uint64_t t_pc_pt = 0; // predicted and taken
  uint64_t t_pc_mp = 0; // mispredicted

  bool isMispredict = false;
  bool isTaken = false;
  bool isDirectionMispredict = false;
  bool isTargetMispredict = false;

  bool trace_isControl = false;
  bool trace_taken = false;
  bool trace_predictedTaken = false;
  bool trace_directionMispredict = false;
  bool trace_targetMispredict = false;
  bool trace_mispredict = false;
  uint64_t trace_predictedTarget = 0;
  uint64_t trace_actualTarget = 0;
  std::string trace_predictorComponent = "none";
  uint64_t trace_redirectSourcePc = 0;
  std::string trace_redirectSourceComponent = "none";
  bool trace_btbHit = false;
  uint64_t trace_bhtIndex = 0;
  bool trace_rasUsed = false;

  uint64_t pendingSourcePc = 0;
  std::string pendingSourceComponent = "none";
  
  bool isCall(void) { return ( (rd_ptr[getInstrIndex()] == 1) | (rd_ptr[getInstrIndex()] == 5) ); };
  bool isReturn(void) {return ( (rs1_ptr[getInstrIndex()] != rd_ptr[getInstrIndex()]) & ((rs1_ptr[getInstrIndex()] == 1) | (rs1_ptr[getInstrIndex()] == 5)) ); };
  
  // TODO: Use for model evaluation. DELETE!
  uint64_t pc_pt = 0;
  
};

} // namespace rocket
  
#endif // ROCKET_BRANCH_PREDICTION_MODEL_H
