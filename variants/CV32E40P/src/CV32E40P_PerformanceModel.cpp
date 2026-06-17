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


#include "CV32E40P_PerformanceModel.h"

#include <stdbool.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "Channel.h"

#include "CV32E40P_Channel.h"

#include "models/common/StandardRegisterModel.h"
#include "models/common/StaticBranchPredictModel.h"
#include "models/cv32e40p/DividerModel.h"
#include "models/cv32e40p/DividerUnsignedModel.h"

namespace CV32E40P{

namespace {

bool has_rs1(uint64_t typeId)
{
  return (typeId <= 18)
    || (typeId >= 21 && typeId <= 31)
    || (typeId >= 35 && typeId <= 48)
    || (typeId == 51);
}

bool has_rs2(uint64_t typeId)
{
  return (typeId <= 9)
    || (typeId >= 21 && typeId <= 28)
    || (typeId >= 35 && typeId <= 37)
    || (typeId >= 43 && typeId <= 48);
}

bool has_rd(uint64_t typeId)
{
  return (typeId <= 34)
    || (typeId >= 38 && typeId <= 42)
    || (typeId >= 50 && typeId <= 51);
}

bool has_brTarget(uint64_t typeId)
{
  return (typeId >= 43 && typeId <= 48)
    || (typeId >= 50 && typeId <= 51);
}

bool has_rs2_data(uint64_t typeId)
{
  return typeId >= 25 && typeId <= 28;
}

} // namespace

void CV32E40P_PerformanceModel::connectChannel(Channel* channel_)
{
  CV32E40P_Channel* channel = static_cast<CV32E40P_Channel*>(channel_);

  typeId_ptr = channel->typeId;
  rs1_ptr = channel->rs1;
  rs2_ptr = channel->rs2;
  rd_ptr = channel->rd;
  pc_ptr = channel->pc;
  brTarget_ptr = channel->brTarget;
  rs2_data_ptr = channel->rs2_data;
  branch_taken_actual_ptr = channel->branch_taken_actual;

  regModel.rs1_ptr = channel->rs1;
  regModel.rs2_ptr = channel->rs2;
  regModel.rd_ptr = channel->rd;

  staBranchPredModel.pc_ptr = channel->pc;
  staBranchPredModel.brTarget_ptr = channel->brTarget;

  divider.rs2_data_ptr = channel->rs2_data;

  divider_u.rs2_data_ptr = channel->rs2_data;

}

uint64_t CV32E40P_PerformanceModel::getRawReadyA(uint64_t baseCycle)
{
  uint64_t readyCycle = regModel.getXa();
  uint64_t waitCycles = readyCycle > baseCycle ? readyCycle - baseCycle : 0;
  if(waitCycles > raw_wait_cycles)
  {
    raw_wait_cycles = waitCycles;
    raw_blocking_reg = rs1_ptr[instrIndex];
    raw_blocking_ready_cycle = readyCycle;
  }
  return readyCycle;
}

uint64_t CV32E40P_PerformanceModel::getRawReadyB(uint64_t baseCycle)
{
  uint64_t readyCycle = regModel.getXb();
  uint64_t waitCycles = readyCycle > baseCycle ? readyCycle - baseCycle : 0;
  if(waitCycles > raw_wait_cycles)
  {
    raw_wait_cycles = waitCycles;
    raw_blocking_reg = rs2_ptr[instrIndex];
    raw_blocking_ready_cycle = readyCycle;
  }
  return readyCycle;
}

uint64_t CV32E40P_PerformanceModel::getCycleCount(void)
{
  
  return std::max({
    IF_stage 
    ,ID_stage
    ,EX_stage
    ,WB_stage
  });
}

std::string CV32E40P_PerformanceModel::getPipelineStream(void)
{
  std::stringstream ret_strs;
  const int streamInstrIndex = instrIndex > 0 ? instrIndex - 1 : instrIndex;
  const uint64_t typeId = typeId_ptr[streamInstrIndex];
  uint64_t streamBranchTaken = branch_taken;
  uint64_t streamBranchMispredict = branch_mispredict;
  uint64_t streamBranchRedirectCycles = branch_redirect_cycles;
  if(typeId >= 43 && typeId <= 48)
  {
    streamBranchTaken = branch_taken_actual_ptr[streamInstrIndex] ? 1 : 0;
    streamBranchMispredict = streamBranchTaken;
    streamBranchRedirectCycles = streamBranchTaken ? branch_redirect_cycles : 0;
  }
  
  ret_strs << IF_stage; 
  ret_strs << "," << ID_stage;
  ret_strs << "," << EX_stage;
  ret_strs << "," << WB_stage;
  ret_strs << "," << instr_id;
  ret_strs << "," << typeId;
  ret_strs << "," << pc_ptr[streamInstrIndex];
  ret_strs << "," << (has_rs1(typeId) ? rs1_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rs2(typeId) ? rs2_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rd(typeId) ? rd_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_brTarget(typeId) ? brTarget_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (has_rs2_data(typeId) ? rs2_data_ptr[streamInstrIndex] : 0);
  ret_strs << "," << divider_delay_cycles;
  ret_strs << "," << multiplier_delay_cycles;
  ret_strs << "," << (has_rs1(typeId) ? 1 : 0);
  ret_strs << "," << (has_rs2(typeId) ? 1 : 0);
  ret_strs << "," << (has_rd(typeId) ? 1 : 0);
  ret_strs << "," << raw_wait_cycles;
  ret_strs << "," << raw_blocking_reg;
  ret_strs << "," << raw_blocking_ready_cycle;
  ret_strs << "," << branch_is_control;
  ret_strs << "," << streamBranchTaken;
  ret_strs << "," << streamBranchMispredict;
  ret_strs << "," << streamBranchRedirectCycles;
  ret_strs << "," << memory_port_wait_cycles;
  ret_strs << "," << memory_port_kind;
  ret_strs << std::endl;
  instr_id++;
  divider_delay_cycles = 0;
  multiplier_delay_cycles = 0;
  raw_wait_cycles = 0;
  raw_blocking_reg = -1;
  raw_blocking_ready_cycle = 0;
  branch_is_control = 0;
  branch_taken = 0;
  branch_mispredict = 0;
  branch_redirect_cycles = 0;
  memory_port_wait_cycles = 0;
  memory_port_kind = "none";
  return ret_strs.str();
}

std::string CV32E40P_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "IF_stage"; 
  ret_strs << "," << "ID_stage";
  ret_strs << "," << "EX_stage";
  ret_strs << "," << "WB_stage";
  ret_strs << "," << "instr_id";
  ret_strs << "," << "type_id";
  ret_strs << "," << "pc";
  ret_strs << "," << "rs1";
  ret_strs << "," << "rs2";
  ret_strs << "," << "rd";
  ret_strs << "," << "brTarget";
  ret_strs << "," << "rs2_data";
  ret_strs << "," << "divider_delay_cycles";
  ret_strs << "," << "multiplier_delay_cycles";
  ret_strs << "," << "uses_rs1";
  ret_strs << "," << "uses_rs2";
  ret_strs << "," << "uses_rd";
  ret_strs << "," << "raw_wait_cycles";
  ret_strs << "," << "raw_blocking_reg";
  ret_strs << "," << "raw_blocking_ready_cycle";
  ret_strs << "," << "branch_is_control";
  ret_strs << "," << "branch_taken";
  ret_strs << "," << "branch_mispredict";
  ret_strs << "," << "branch_redirect_cycles";
  ret_strs << "," << "memory_port_wait_cycles";
  ret_strs << "," << "memory_port_kind";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace CV32E40P
