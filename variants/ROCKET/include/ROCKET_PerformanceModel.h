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


#ifndef SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <cstdint>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/rocket/BranchPredictionModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/rocket/ICacheModel.h"
#include "models/rocket/DividerModel.h"
#include "models/rocket/DividerUnsignedModel.h"
#include "models/rocket/DCacheModel.h"

namespace ROCKET{

extern SchedulingFunctionSet* ROCKET_SchedulingFunctionSet;

class ROCKET_PerformanceModel : public PerformanceModel
{
public:

  ROCKET_PerformanceModel() : PerformanceModel("ROCKET", ROCKET_SchedulingFunctionSet)
    ,dynBranchPredModel(this)
    ,regModel(this)
    ,iCacheModel(this)
    ,divider(this)
    ,divider_u(this)
    ,dCacheModel(this)
  {};

  // Single-Element Timing Variables
  uint64_t IF = 0;
  uint64_t ID = 0;
  uint64_t EX = 0;
  uint64_t MEM = 0;
  uint64_t WB = 0;

  // Trace identity and temporary timing instrumentation fields
  uint64_t* pc_ptr = nullptr;
  uint64_t* rs1_ptr = nullptr;
  uint64_t* rs2_ptr = nullptr;
  uint64_t* rd_ptr = nullptr;
  uint64_t instr_id = 0;
  uint64_t uses_rs1 = 0;
  uint64_t uses_rs2 = 0;
  uint64_t uses_rd = 0;
  uint64_t raw_wait_cycles = 0;
  int64_t raw_blocking_reg = -1;
  uint64_t raw_blocking_ready_cycle = 0;
  uint64_t icache_delay_cycles = 0;
  uint64_t icache_miss = 0;
  uint64_t dcache_delay_cycles = 0;
  uint64_t dcache_miss = 0;
  uint64_t branch_is_control = 0;
  uint64_t branch_mispredict = 0;
  uint64_t branch_redirect_cycles = 0;
  uint64_t divider_delay_cycles = 0;


  // External Resource Models
  rocket::BranchPredictionModel dynBranchPredModel;
  common::StandardRegisterModel regModel;
  rocket::ICacheModel iCacheModel;
  rocket::DividerModel divider;
  rocket::DividerUnsignedModel divider_u;
  rocket::DCacheModel dCacheModel;

  uint64_t getRawReadyA(uint64_t baseCycle);
  uint64_t getRawReadyB(uint64_t baseCycle);
  void setOperandUse(bool useRs1, bool useRs2, bool useRd)
  {
    uses_rs1 = useRs1 ? 1 : 0;
    uses_rs2 = useRs2 ? 1 : 0;
    uses_rd = useRd ? 1 : 0;
  };
  void setRegWriteReady(uint64_t readyCycle)
  {
    uses_rd = 1;
    regModel.setXd(readyCycle);
  };
  void setICacheInstrumentation(uint64_t extraDelay, bool miss)
  {
    icache_delay_cycles = extraDelay;
    icache_miss = miss ? 1 : 0;
  };
  void setDCacheInstrumentation(uint64_t extraDelay, bool miss)
  {
    dcache_delay_cycles = extraDelay;
    dcache_miss = miss ? 1 : 0;
  };
  void setDividerDelay(uint64_t extraDelay) { divider_delay_cycles = extraDelay; };
  void setBranchInstrumentation(bool isControl, bool mispredict, uint64_t redirectCycles)
  {
    branch_is_control = isControl ? 1 : 0;
    branch_mispredict = mispredict ? 1 : 0;
    branch_redirect_cycles = redirectCycles;
  };

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);

};

} // namespace ROCKET

#endif // SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H
