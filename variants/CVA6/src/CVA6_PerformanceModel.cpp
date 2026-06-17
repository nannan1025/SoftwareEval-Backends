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


#include "CVA6_PerformanceModel.h"

#include <stdbool.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "Channel.h"

#include "CVA6_Channel.h"

#include "models/common/StandardRegisterModel.h"
#include "models/cva6/BranchPredictionModel.h"
#include "models/cva6/ClobberModel.h"
#include "models/cva6/ICacheModel.h"
#include "models/cva6/DividerModel.h"
#include "models/cva6/DividerUnsignedModel.h"
#include "models/cva6/DCacheModel.h"

namespace CVA6{

bool has_rs1(uint64_t typeId)
{
  return (typeId >= 6 && typeId <= 33)
    || (typeId >= 34 && typeId <= 39)
    || typeId == 41
    || (typeId >= 42 && typeId <= 65);
}

bool has_rs2(uint64_t typeId)
{
  return (typeId >= 22 && typeId <= 39)
    || (typeId >= 42 && typeId <= 54)
    || (typeId >= 62 && typeId <= 65);
}

bool has_rd(uint64_t typeId)
{
  return (typeId >= 1 && typeId <= 33)
    || (typeId >= 40 && typeId <= 61);
}

bool has_brTarget(uint64_t typeId)
{
  return (typeId >= 34 && typeId <= 41);
}

bool has_imm(uint64_t typeId)
{
  return (typeId >= 34 && typeId <= 41);
}

bool has_rs1_data(uint64_t typeId)
{
  return (typeId >= 47 && typeId <= 54);
}

bool has_rs2_data(uint64_t typeId)
{
  return (typeId >= 47 && typeId <= 54);
}

bool has_addr(uint64_t typeId)
{
  return (typeId >= 55 && typeId <= 65);
}

void CVA6_PerformanceModel::connectChannel(Channel* channel_)
{
  CVA6_Channel* channel = static_cast<CVA6_Channel*>(channel_);

  typeId_ptr = channel->typeId;
  rs1_ptr = channel->rs1;
  rs2_ptr = channel->rs2;
  rd_ptr = channel->rd;
  pc_ptr = channel->pc;
  brTarget_ptr = channel->brTarget;
  imm_ptr = channel->imm;
  rs1_data_ptr = channel->rs1_data;
  rs2_data_ptr = channel->rs2_data;
  addr_ptr = channel->addr;

  regModel.rs1_ptr = channel->rs1;
  regModel.rs2_ptr = channel->rs2;
  regModel.rd_ptr = channel->rd;

  dynBranchPredModel.pc_ptr = channel->pc;
  dynBranchPredModel.brTarget_ptr = channel->brTarget;
  dynBranchPredModel.rs1_ptr = channel->rs1;
  dynBranchPredModel.rd_ptr = channel->rd;
  dynBranchPredModel.imm_ptr = channel->imm;
  dynBranchPredModel.typeId_ptr = channel->typeId;

  clobberModel.rd_ptr = channel->rd;

  iCacheModel.pc_ptr = channel->pc;

  divider.rs1_data_ptr = channel->rs1_data;
  divider.rs2_data_ptr = channel->rs2_data;

  divider_u.rs1_data_ptr = channel->rs1_data;
  divider_u.rs2_data_ptr = channel->rs2_data;

  dCacheModel.addr_ptr = channel->addr;

}

uint64_t CVA6_PerformanceModel::getCycleCount(void)
{
  
  return std::max({
    PC_stage 
    ,IF_stage.get(1)
    ,IF_substage_0
    ,IF_substage_1
    ,IF_substage_2
    ,IQ_stage.get(1)
    ,ID_stage
    ,IS_stage
    ,EX_stage.get(1)
    ,EX_substage_alu
    ,EX_substage_mul_i
    ,EX_substage_mul_o
    ,EX_substage_div
    ,EX_substage_lCtrl
    ,EX_substage_dCache
    ,EX_substage_lUnit
    ,EX_substage_sCtrl
    ,EX_substage_sUnit
    ,COM_stage.get(1)
  });
}

void CVA6_PerformanceModel::setDividerInstrumentation(uint64_t rawDelayCycles)
{
  divider_delay_cycles = rawDelayCycles;
  divider_extra_cycles = rawDelayCycles > 0 ? rawDelayCycles - 1 : 0;
}

void CVA6_PerformanceModel::setICacheInstrumentation(bool isMiss, uint64_t rawDelayCycles, uint64_t frontendWaitCycles, const std::string& frontendWaitType)
{
  icache_miss = isMiss ? 1 : 0;
  icache_delay_cycles = rawDelayCycles;
  icache_extra_cycles = rawDelayCycles > 0 ? rawDelayCycles - 1 : 0;
  frontend_wait_cycles = frontendWaitCycles;
  frontend_extra_cycles = frontendWaitCycles > 0 ? frontendWaitCycles - 1 : 0;
  frontend_wait_type = frontendWaitCycles > 0 ? frontendWaitType : "none";
}

void CVA6_PerformanceModel::setDCacheInstrumentation(bool isMiss, bool isNotCacheable, uint64_t rawDelayCycles)
{
  dcache_miss = isMiss ? 1 : 0;
  dcache_not_cacheable = isNotCacheable ? 1 : 0;
  dcache_delay_cycles = rawDelayCycles;
  dcache_extra_cycles = rawDelayCycles > 0 ? rawDelayCycles - 1 : 0;
  memory_wait_cycles = dcache_extra_cycles;
}

bool CVA6_PerformanceModel::isDCacheAddressNotCacheable(void)
{
  uint64_t addr = addr_ptr[instrIndex];
  return !((0x80000000 <= addr) && (addr < 0xC0000000));
}

void CVA6_PerformanceModel::setBranchRedirectWait(uint64_t waitCycles)
{
  branch_redirect_cycles = waitCycles;
  if(waitCycles > 0)
  {
    branch_redirect_source_pc = dynBranchPredModel.getTrace_redirectSourcePc();
    branch_redirect_source_type_id = dynBranchPredModel.getTrace_redirectSourceTypeId();
    branch_redirect_source_component = dynBranchPredModel.getTrace_redirectSourceComponent();
  }
}

void CVA6_PerformanceModel::recordRawReady(uint64_t readyCycle, uint64_t baseCycle, uint64_t reg, const std::string& operand)
{
  if(reg == 0)
  {
    return;
  }

  uint64_t waitCycles = readyCycle > baseCycle ? readyCycle - baseCycle : 0;
  if(waitCycles > raw_wait_cycles)
  {
    raw_wait_cycles = waitCycles;
    raw_blocking_reg = static_cast<int64_t>(reg);
    raw_blocking_ready_cycle = waitCycles > 0 ? readyCycle : 0;
    raw_blocking_operand = waitCycles > 0 ? operand : "none";
  }
}

uint64_t CVA6_PerformanceModel::getRawReadyA(uint64_t baseCycle)
{
  uint64_t readyCycle = regModel.getXa();
  recordRawReady(readyCycle, baseCycle, rs1_ptr[instrIndex], "rs1");
  return readyCycle;
}

uint64_t CVA6_PerformanceModel::getRawReadyB(uint64_t baseCycle)
{
  uint64_t readyCycle = regModel.getXb();
  recordRawReady(readyCycle, baseCycle, rs2_ptr[instrIndex], "rs2");
  return readyCycle;
}

void CVA6_PerformanceModel::setEXSubpipeInstrumentation(uint64_t waitCycles, const std::string& kind, const std::string& blockingResource, uint64_t blockingReadyCycle)
{
  if(waitCycles > ex_subpipe_wait_cycles)
  {
    ex_subpipe_wait_cycles = waitCycles;
    ex_subpipe_kind = waitCycles > 0 ? kind : "none";
    ex_blocking_resource = waitCycles > 0 ? blockingResource : "none";
    ex_blocking_ready_cycle = waitCycles > 0 ? blockingReadyCycle : 0;
  }
}

void CVA6_PerformanceModel::recordEXSubpipeReady(uint64_t issueReadyBase, uint64_t readyCycle, const std::string& kind, const std::string& blockingResource)
{
  uint64_t waitCycles = readyCycle > issueReadyBase ? readyCycle - issueReadyBase : 0;
  setEXSubpipeInstrumentation(waitCycles, kind, blockingResource, readyCycle);
}

uint64_t CVA6_PerformanceModel::getClobberReady(uint64_t baseCycle)
{
  uint64_t readyCycle = clobberModel.getCb_out();
  uint64_t waitCycles = readyCycle > baseCycle ? readyCycle - baseCycle : 0;
  if(waitCycles > clobber_wait_cycles)
  {
    clobber_wait_cycles = waitCycles;
    clobber_blocking_reg = waitCycles > 0 ? static_cast<int64_t>(rd_ptr[instrIndex]) : -1;
    clobber_blocking_ready_cycle = waitCycles > 0 ? readyCycle : 0;
  }
  return readyCycle;
}

void CVA6_PerformanceModel::recordCommitBackpressure(uint64_t baseCycle, uint64_t readyCycle)
{
  commit_backpressure_wait_cycles = readyCycle > baseCycle ? readyCycle - baseCycle : 0;
  commit_wait_cycles = commit_backpressure_wait_cycles + commit_capacity_wait_cycles;
  const bool hasBackpressure = commit_backpressure_wait_cycles > 0;
  const bool hasCapacity = commit_capacity_wait_cycles > 0;
  commit_wait_kind = hasBackpressure && hasCapacity ? "backpressure+capacity" : (hasBackpressure ? "backpressure" : (hasCapacity ? "capacity" : "none"));
  if(hasBackpressure && commit_backpressure_wait_cycles >= commit_capacity_wait_cycles)
  {
    commit_blocking_ready_cycle = readyCycle;
    commit_base_cycle = baseCycle;
  }
}

void CVA6_PerformanceModel::recordCommitCapacity(uint64_t baseCycle, uint64_t readyCycle)
{
  commit_capacity_wait_cycles = readyCycle > baseCycle ? readyCycle - baseCycle : 0;
  commit_wait_cycles = commit_backpressure_wait_cycles + commit_capacity_wait_cycles;
  const bool hasBackpressure = commit_backpressure_wait_cycles > 0;
  const bool hasCapacity = commit_capacity_wait_cycles > 0;
  commit_wait_kind = hasBackpressure && hasCapacity ? "backpressure+capacity" : (hasBackpressure ? "backpressure" : (hasCapacity ? "capacity" : "none"));
  if(hasCapacity && commit_capacity_wait_cycles > commit_backpressure_wait_cycles)
  {
    commit_blocking_ready_cycle = readyCycle;
    commit_base_cycle = baseCycle;
  }
}

void CVA6_PerformanceModel::setBranchInstrumentation(uint64_t typeId, int streamInstrIndex)
{
  if(typeId < 34 || typeId > 41)
  {
    return;
  }

  const uint64_t nextPc = pc_ptr[streamInstrIndex + 1];
  const uint64_t target = brTarget_ptr[streamInstrIndex];
  branch_is_control = 1;
  branch_predicted_taken = dynBranchPredModel.getTrace_predictedTaken();
  branch_predicted_target = dynBranchPredModel.getTrace_predictedTarget();
  branch_predictor_component = dynBranchPredModel.getTrace_predictorComponent();

  if(typeId >= 34 && typeId <= 39)
  {
    branch_taken = nextPc == target ? 1 : 0;
    branch_actual_target = branch_taken ? target : pc_ptr[streamInstrIndex] + 4;
    branch_mispredict = branch_predicted_taken != branch_taken ? 1 : 0;
  }
  else if(typeId == 40)
  {
    branch_taken = 1;
    branch_predicted_taken = 1;
    branch_mispredict = 0;
    branch_predicted_target = target;
    branch_actual_target = target;
    branch_predictor_component = "JAL";
  }
  else
  {
    branch_taken = 1;
    branch_actual_target = target;
    branch_mispredict = branch_predicted_target != branch_actual_target ? 1 : 0;
  }

  branch_predict_path_cycles = branch_taken && !branch_mispredict && IF_stage.get(1) > PC_stage ? IF_stage.get(1) - PC_stage : 0;
}

std::string CVA6_PerformanceModel::getPipelineStream(void)
{
  std::stringstream ret_strs;
  const int streamInstrIndex = instrIndex > 0 ? instrIndex - 1 : instrIndex;
  const uint64_t typeId = typeId_ptr[streamInstrIndex];
  setBranchInstrumentation(typeId, streamInstrIndex);
  
  ret_strs << PC_stage; 
  ret_strs << "," << IF_stage.get(1);
  ret_strs << "," << IQ_stage.get(1);
  ret_strs << "," << ID_stage;
  ret_strs << "," << IS_stage;
  ret_strs << "," << EX_stage.get(1);
  ret_strs << "," << COM_stage.get(1);
  ret_strs << "," << instr_id;
  ret_strs << "," << typeId;
  ret_strs << "," << pc_ptr[streamInstrIndex];
  ret_strs << "," << (has_rs1(typeId) ? rs1_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rs2(typeId) ? rs2_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rd(typeId) ? rd_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_brTarget(typeId) ? brTarget_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_imm(typeId) ? imm_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rs1_data(typeId) ? rs1_data_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rs2_data(typeId) ? rs2_data_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_addr(typeId) ? addr_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rs1(typeId) ? 1 : 0);
  ret_strs << "," << (has_rs2(typeId) ? 1 : 0);
  ret_strs << "," << (has_rd(typeId) ? 1 : 0);
  ret_strs << "," << divider_delay_cycles;
  ret_strs << "," << divider_extra_cycles;
  ret_strs << "," << icache_miss;
  ret_strs << "," << icache_delay_cycles;
  ret_strs << "," << icache_extra_cycles;
  ret_strs << "," << frontend_wait_cycles;
  ret_strs << "," << frontend_extra_cycles;
  ret_strs << "," << frontend_wait_type;
  ret_strs << "," << dcache_miss;
  ret_strs << "," << dcache_not_cacheable;
  ret_strs << "," << dcache_delay_cycles;
  ret_strs << "," << dcache_extra_cycles;
  ret_strs << "," << memory_wait_cycles;
  ret_strs << "," << branch_is_control;
  ret_strs << "," << branch_taken;
  ret_strs << "," << branch_predicted_taken;
  ret_strs << "," << branch_mispredict;
  ret_strs << "," << branch_predicted_target;
  ret_strs << "," << branch_actual_target;
  ret_strs << "," << branch_redirect_cycles;
  ret_strs << "," << branch_predict_path_cycles;
  ret_strs << "," << branch_predictor_component;
  ret_strs << "," << branch_redirect_source_pc;
  ret_strs << "," << branch_redirect_source_type_id;
  ret_strs << "," << branch_redirect_source_component;
  ret_strs << "," << raw_wait_cycles;
  ret_strs << "," << raw_blocking_reg;
  ret_strs << "," << raw_blocking_ready_cycle;
  ret_strs << "," << raw_blocking_operand;
  ret_strs << "," << ex_subpipe_wait_cycles;
  ret_strs << "," << ex_subpipe_kind;
  ret_strs << "," << ex_blocking_resource;
  ret_strs << "," << ex_blocking_ready_cycle;
  ret_strs << "," << clobber_wait_cycles;
  ret_strs << "," << clobber_blocking_reg;
  ret_strs << "," << clobber_blocking_ready_cycle;
  ret_strs << "," << commit_backpressure_wait_cycles;
  ret_strs << "," << commit_capacity_wait_cycles;
  ret_strs << "," << commit_wait_cycles;
  ret_strs << "," << commit_wait_kind;
  ret_strs << "," << commit_blocking_ready_cycle;
  ret_strs << "," << commit_base_cycle;
  ret_strs << std::endl;
  instr_id++;
  divider_delay_cycles = 0;
  divider_extra_cycles = 0;
  icache_miss = 0;
  icache_delay_cycles = 0;
  icache_extra_cycles = 0;
  frontend_wait_cycles = 0;
  frontend_extra_cycles = 0;
  frontend_wait_type = "none";
  dcache_miss = 0;
  dcache_not_cacheable = 0;
  dcache_delay_cycles = 0;
  dcache_extra_cycles = 0;
  memory_wait_cycles = 0;
  branch_is_control = 0;
  branch_taken = 0;
  branch_predicted_taken = 0;
  branch_mispredict = 0;
  branch_predicted_target = 0;
  branch_actual_target = 0;
  branch_redirect_cycles = 0;
  branch_predict_path_cycles = 0;
  branch_predictor_component = "none";
  branch_redirect_source_pc = 0;
  branch_redirect_source_type_id = 0;
  branch_redirect_source_component = "none";
  raw_wait_cycles = 0;
  raw_blocking_reg = -1;
  raw_blocking_ready_cycle = 0;
  raw_blocking_operand = "none";
  ex_subpipe_wait_cycles = 0;
  ex_subpipe_kind = "none";
  ex_blocking_resource = "none";
  ex_blocking_ready_cycle = 0;
  clobber_wait_cycles = 0;
  clobber_blocking_reg = -1;
  clobber_blocking_ready_cycle = 0;
  commit_backpressure_wait_cycles = 0;
  commit_capacity_wait_cycles = 0;
  commit_wait_cycles = 0;
  commit_wait_kind = "none";
  commit_blocking_ready_cycle = 0;
  commit_base_cycle = 0;
  dynBranchPredModel.clearTraceInfo();
  return ret_strs.str();
}

std::string CVA6_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "PC_stage"; 
  ret_strs << "," << "IF_stage";
  ret_strs << "," << "IQ_stage";
  ret_strs << "," << "ID_stage";
  ret_strs << "," << "IS_stage";
  ret_strs << "," << "EX_stage";
  ret_strs << "," << "COM_stage";
  ret_strs << "," << "instr_id";
  ret_strs << "," << "type_id";
  ret_strs << "," << "pc";
  ret_strs << "," << "rs1";
  ret_strs << "," << "rs2";
  ret_strs << "," << "rd";
  ret_strs << "," << "brTarget";
  ret_strs << "," << "imm";
  ret_strs << "," << "rs1_data";
  ret_strs << "," << "rs2_data";
  ret_strs << "," << "addr";
  ret_strs << "," << "uses_rs1";
  ret_strs << "," << "uses_rs2";
  ret_strs << "," << "uses_rd";
  ret_strs << "," << "divider_delay_cycles";
  ret_strs << "," << "divider_extra_cycles";
  ret_strs << "," << "icache_miss";
  ret_strs << "," << "icache_delay_cycles";
  ret_strs << "," << "icache_extra_cycles";
  ret_strs << "," << "frontend_wait_cycles";
  ret_strs << "," << "frontend_extra_cycles";
  ret_strs << "," << "frontend_wait_type";
  ret_strs << "," << "dcache_miss";
  ret_strs << "," << "dcache_not_cacheable";
  ret_strs << "," << "dcache_delay_cycles";
  ret_strs << "," << "dcache_extra_cycles";
  ret_strs << "," << "memory_wait_cycles";
  ret_strs << "," << "branch_is_control";
  ret_strs << "," << "branch_taken";
  ret_strs << "," << "branch_predicted_taken";
  ret_strs << "," << "branch_mispredict";
  ret_strs << "," << "branch_predicted_target";
  ret_strs << "," << "branch_actual_target";
  ret_strs << "," << "branch_redirect_cycles";
  ret_strs << "," << "branch_predict_path_cycles";
  ret_strs << "," << "branch_predictor_component";
  ret_strs << "," << "branch_redirect_source_pc";
  ret_strs << "," << "branch_redirect_source_type_id";
  ret_strs << "," << "branch_redirect_source_component";
  ret_strs << "," << "raw_wait_cycles";
  ret_strs << "," << "raw_blocking_reg";
  ret_strs << "," << "raw_blocking_ready_cycle";
  ret_strs << "," << "raw_blocking_operand";
  ret_strs << "," << "ex_subpipe_wait_cycles";
  ret_strs << "," << "ex_subpipe_kind";
  ret_strs << "," << "ex_blocking_resource";
  ret_strs << "," << "ex_blocking_ready_cycle";
  ret_strs << "," << "clobber_wait_cycles";
  ret_strs << "," << "clobber_blocking_reg";
  ret_strs << "," << "clobber_blocking_ready_cycle";
  ret_strs << "," << "commit_backpressure_wait_cycles";
  ret_strs << "," << "commit_capacity_wait_cycles";
  ret_strs << "," << "commit_wait_cycles";
  ret_strs << "," << "commit_wait_kind";
  ret_strs << "," << "commit_blocking_ready_cycle";
  ret_strs << "," << "commit_base_cycle";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace CVA6
