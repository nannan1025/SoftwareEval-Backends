/*
* Copyright 2026 Chair of EDA, Technical University of Munich
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

/********************* AUTO GENERATE FILE (create by M2-ISA-R-Perf) *********************/


#ifndef SWEVAL_BACKENDS_CV32E40P_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_CV32E40P_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <cstdint>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/common/StandardRegisterModel.h"
#include "models/common/StaticBranchPredictModel.h"
#include "models/cv32e40p/DividerModel.h"
#include "models/cv32e40p/DividerUnsignedModel.h"

namespace CV32E40P{

extern SchedulingFunctionSet* CV32E40P_SchedulingFunctionSet;

class CV32E40P_PerformanceModel : public PerformanceModel
{
public:

  CV32E40P_PerformanceModel() : PerformanceModel("CV32E40P", CV32E40P_SchedulingFunctionSet)
    ,regModel(this)
    ,staBranchPredModel(this)
    ,divider(this)
    ,divider_u(this)
  {};

  // Single-Element Timing Variables
  uint64_t IF_stage = 0;
  uint64_t ID_stage = 0;
  uint64_t EX_stage = 0;
  uint64_t WB_stage = 0;

  // Trace identity fields for timing trace attribution
  uint64_t* typeId_ptr = nullptr;
  uint64_t* rs1_ptr = nullptr;
  uint64_t* rs2_ptr = nullptr;
  uint64_t* rd_ptr = nullptr;
  uint64_t* pc_ptr = nullptr;
  uint64_t* brTarget_ptr = nullptr;
  uint64_t* rs2_data_ptr = nullptr;
  uint64_t* branch_taken_actual_ptr = nullptr;
  uint64_t instr_id = 0;
  uint64_t divider_delay_cycles = 0;
  uint64_t multiplier_delay_cycles = 0;
  uint64_t raw_wait_cycles = 0;
  int64_t raw_blocking_reg = -1;
  uint64_t raw_blocking_ready_cycle = 0;
  uint64_t branch_is_control = 0;
  uint64_t branch_taken = 0;
  uint64_t branch_mispredict = 0;
  uint64_t branch_redirect_cycles = 0;
  uint64_t memory_port_wait_cycles = 0;
  std::string memory_port_kind = "none";


  // External Resource Models
  common::StandardRegisterModel regModel;
  common::StaticBranchPredictModel staBranchPredModel;
  cv32e40p::DividerModel divider;
  cv32e40p::DividerUnsignedModel divider_u;

  void setDividerDelay(uint64_t delay) { divider_delay_cycles = delay; };
  void setMultiplierDelay(uint64_t delay) { multiplier_delay_cycles = delay; };
  void setBranchInstrumentation(bool isControl, bool taken, bool mispredict, uint64_t redirectCycles)
  {
    branch_is_control = isControl ? 1 : 0;
    branch_taken = taken ? 1 : 0;
    branch_mispredict = mispredict ? 1 : 0;
    branch_redirect_cycles = redirectCycles;
  };
  void setMemoryPortInstrumentation(uint64_t waitCycles, const std::string& kind)
  {
    memory_port_wait_cycles = waitCycles;
    memory_port_kind = kind;
  };
  uint64_t getRawReadyA(uint64_t baseCycle);
  uint64_t getRawReadyB(uint64_t baseCycle);

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);

};

} // namespace CV32E40P

#endif // SWEVAL_BACKENDS_CV32E40P_PERFORMANCE_MODEL_H
