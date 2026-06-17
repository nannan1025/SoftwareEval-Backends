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


#ifndef SWEVAL_BACKENDS_CVA6_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_CVA6_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <cstdint>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/common/StandardRegisterModel.h"
#include "models/cva6/BranchPredictionModel.h"
#include "models/cva6/ClobberModel.h"
#include "models/cva6/ICacheModel.h"
#include "models/cva6/DividerModel.h"
#include "models/cva6/DividerUnsignedModel.h"
#include "models/cva6/DCacheModel.h"

namespace CVA6{

extern SchedulingFunctionSet* CVA6_SchedulingFunctionSet;

class CVA6_PerformanceModel : public PerformanceModel
{
public:

  CVA6_PerformanceModel() : PerformanceModel("CVA6", CVA6_SchedulingFunctionSet)
    ,IF_stage(3,0)
    ,IQ_stage(7,0)
    ,EX_stage(8,0)
    ,COM_stage(2,0)
    ,regModel(this)
    ,dynBranchPredModel(this)
    ,clobberModel(this)
    ,iCacheModel(this)
    ,divider(this)
    ,divider_u(this)
    ,dCacheModel(this)
  {};

  // Single-Element Timing Variables
  uint64_t PC_stage = 0;
  uint64_t IF_substage_0 = 0;
  uint64_t IF_substage_1 = 0;
  uint64_t IF_substage_2 = 0;
  uint64_t ID_stage = 0;
  uint64_t IS_stage = 0;
  uint64_t EX_substage_alu = 0;
  uint64_t EX_substage_mul_i = 0;
  uint64_t EX_substage_mul_o = 0;
  uint64_t EX_substage_div = 0;
  uint64_t EX_substage_lCtrl = 0;
  uint64_t EX_substage_dCache = 0;
  uint64_t EX_substage_lUnit = 0;
  uint64_t EX_substage_sCtrl = 0;
  uint64_t EX_substage_sUnit = 0;

  // Multi-Element Timing Variables
  MultiElementTimingVariable IF_stage;
  MultiElementTimingVariable IQ_stage;
  MultiElementTimingVariable EX_stage;
  MultiElementTimingVariable COM_stage;

  // External Resource Models
  common::StandardRegisterModel regModel;
  cva6::BranchPredictionModel dynBranchPredModel;
  cva6::ClobberModel clobberModel;
  cva6::ICacheModel iCacheModel;
  cva6::DividerModel divider;
  cva6::DividerUnsignedModel divider_u;
  cva6::DCacheModel dCacheModel;

  // Timing trace identity fields
  uint64_t* typeId_ptr = nullptr;
  uint64_t* rs1_ptr = nullptr;
  uint64_t* rs2_ptr = nullptr;
  uint64_t* rd_ptr = nullptr;
  uint64_t* pc_ptr = nullptr;
  uint64_t* brTarget_ptr = nullptr;
  uint64_t* imm_ptr = nullptr;
  uint64_t* rs1_data_ptr = nullptr;
  uint64_t* rs2_data_ptr = nullptr;
  uint64_t* addr_ptr = nullptr;
  uint64_t instr_id = 0;
  uint64_t divider_delay_cycles = 0;
  uint64_t divider_extra_cycles = 0;
  uint64_t icache_miss = 0;
  uint64_t icache_delay_cycles = 0;
  uint64_t icache_extra_cycles = 0;
  uint64_t frontend_wait_cycles = 0;
  uint64_t frontend_extra_cycles = 0;
  std::string frontend_wait_type = "none";
  uint64_t dcache_miss = 0;
  uint64_t dcache_not_cacheable = 0;
  uint64_t dcache_delay_cycles = 0;
  uint64_t dcache_extra_cycles = 0;
  uint64_t memory_wait_cycles = 0;
  uint64_t branch_is_control = 0;
  uint64_t branch_taken = 0;
  uint64_t branch_predicted_taken = 0;
  uint64_t branch_mispredict = 0;
  uint64_t branch_predicted_target = 0;
  uint64_t branch_actual_target = 0;
  uint64_t branch_redirect_cycles = 0;
  uint64_t branch_predict_path_cycles = 0;
  std::string branch_predictor_component = "none";
  uint64_t branch_redirect_source_pc = 0;
  uint64_t branch_redirect_source_type_id = 0;
  std::string branch_redirect_source_component = "none";
  uint64_t raw_wait_cycles = 0;
  int64_t raw_blocking_reg = -1;
  uint64_t raw_blocking_ready_cycle = 0;
  std::string raw_blocking_operand = "none";
  uint64_t ex_subpipe_wait_cycles = 0;
  std::string ex_subpipe_kind = "none";
  std::string ex_blocking_resource = "none";
  uint64_t ex_blocking_ready_cycle = 0;
  uint64_t clobber_wait_cycles = 0;
  int64_t clobber_blocking_reg = -1;
  uint64_t clobber_blocking_ready_cycle = 0;
  uint64_t commit_backpressure_wait_cycles = 0;
  uint64_t commit_capacity_wait_cycles = 0;
  uint64_t commit_wait_cycles = 0;
  std::string commit_wait_kind = "none";
  uint64_t commit_blocking_ready_cycle = 0;
  uint64_t commit_base_cycle = 0;

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);
  void setDividerInstrumentation(uint64_t rawDelayCycles);
  void setICacheInstrumentation(bool isMiss, uint64_t rawDelayCycles, uint64_t frontendWaitCycles, const std::string& frontendWaitType);
  void setDCacheInstrumentation(bool isMiss, bool isNotCacheable, uint64_t rawDelayCycles);
  void setBranchInstrumentation(uint64_t typeId, int streamInstrIndex);
  void setBranchRedirectWait(uint64_t waitCycles);
  void recordRawReady(uint64_t readyCycle, uint64_t baseCycle, uint64_t reg, const std::string& operand);
  uint64_t getRawReadyA(uint64_t baseCycle);
  uint64_t getRawReadyB(uint64_t baseCycle);
  void setEXSubpipeInstrumentation(uint64_t waitCycles, const std::string& kind, const std::string& blockingResource, uint64_t blockingReadyCycle);
  void recordEXSubpipeReady(uint64_t issueReadyBase, uint64_t readyCycle, const std::string& kind, const std::string& blockingResource);
  uint64_t getClobberReady(uint64_t baseCycle);
  void recordCommitBackpressure(uint64_t baseCycle, uint64_t readyCycle);
  void recordCommitCapacity(uint64_t baseCycle, uint64_t readyCycle);
  bool isDCacheAddressNotCacheable(void);

};

} // namespace CVA6

#endif // SWEVAL_BACKENDS_CVA6_PERFORMANCE_MODEL_H
