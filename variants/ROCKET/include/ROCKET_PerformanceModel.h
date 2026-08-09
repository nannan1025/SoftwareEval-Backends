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
#include <map>
#include <vector>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/rocket/BranchPredictionModel.h"
#include "models/rocket/RocketMulRegisterModel.h"
#include "models/rocket/ICacheModel.h"
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
    ,dCacheModel(this)
  {};

  // Single-Element Timing Variables
  uint64_t IF = 0;
  uint64_t ID = 0;
  uint64_t EX = 0;
  uint64_t MEM = 0;
  uint64_t WB = 0;


  // External Resource Models
  rocket::BranchPredictionModel dynBranchPredModel;
  rocket::RocketMulRegisterModel regModel;
  rocket::ICacheModel iCacheModel;
  rocket::DCacheModel dCacheModel;

  uint64_t* pc_ptr = nullptr;
  uint64_t* rd_ptr = nullptr;
  uint64_t* rs1_ptr = nullptr;
  uint64_t* rs2_ptr = nullptr;
  uint64_t* imm_ptr = nullptr;
  uint64_t* rs1_data_ptr = nullptr;
  uint64_t* rs2_data_ptr = nullptr;

  std::string trace_instr = "unknown";
  bool trace_used_rs1 = false;
  bool trace_used_rs2 = false;
  bool trace_used_rd = false;
  bool trace_has_rd_ready_cycle = false;
  uint64_t trace_rd_ready_cycle = 0;
  bool trace_icache_miss = false;
  bool trace_dcache_miss = false;
  uint64_t trace_icache_delay_cycles = 0;
  uint64_t trace_dcache_delay_cycles = 0;
  uint64_t trace_sim_misprediction = 0;
  std::map<std::string, uint64_t> trace_sched_vars;

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);

  static const std::vector<std::string>& getSchedTraceColumns(void);
  std::string getSchedTraceValue(const std::string&) const;
  std::string getChannelValue(uint64_t*, int) const;
  std::string csvEscape(const std::string&) const;
  void setInstructionInfo(const std::string&, bool, bool, bool);
  void recordSchedVar(const std::string&, uint64_t);
  void setICacheInstrumentation(uint64_t, bool);
  void setDCacheInstrumentation(uint64_t, bool);
  void setSimMisprediction(uint64_t);
  void setRdReadyCycle(uint64_t);
  void resetTraceState(void);

};

} // namespace ROCKET

#endif // SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H
