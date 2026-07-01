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


#include "ROCKET_PerformanceModel.h"

#include <stdbool.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "Channel.h"

#include "ROCKET_Channel.h"

#include "models/rocket/BranchPredictionModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/rocket/ICacheModel.h"
#include "models/rocket/DividerModel.h"
#include "models/rocket/DividerUnsignedModel.h"
#include "models/rocket/DCacheModel.h"

namespace ROCKET{

void ROCKET_PerformanceModel::connectChannel(Channel* channel_)
{
  ROCKET_Channel* channel = static_cast<ROCKET_Channel*>(channel_);

  pc_ptr = channel->pc;
  rs1_ptr = channel->rs1;
  rs2_ptr = channel->rs2;
  rd_ptr = channel->rd;

  dynBranchPredModel.pc_ptr = channel->pc;
  dynBranchPredModel.brTarget_ptr = channel->brTarget;
  dynBranchPredModel.rs1_ptr = channel->rs1;
  dynBranchPredModel.rd_ptr = channel->rd;
  dynBranchPredModel.imm_ptr = channel->imm;

  regModel.rs1_ptr = channel->rs1;
  regModel.rs2_ptr = channel->rs2;
  regModel.rd_ptr = channel->rd;

  iCacheModel.pc_ptr = channel->pc;

  divider.rs1_data_ptr = channel->rs1_data;
  divider.rs2_data_ptr = channel->rs2_data;

  divider_u.rs1_data_ptr = channel->rs1_data;
  divider_u.rs2_data_ptr = channel->rs2_data;

  dCacheModel.addr_ptr = channel->addr;

}

uint64_t ROCKET_PerformanceModel::getRawReadyA(uint64_t baseCycle)
{
  uses_rs1 = 1;
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

uint64_t ROCKET_PerformanceModel::getRawReadyB(uint64_t baseCycle)
{
  uses_rs2 = 1;
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

uint64_t ROCKET_PerformanceModel::getCycleCount(void)
{
  
  return std::max({
    IF 
    ,ID
    ,EX
    ,MEM
    ,WB
  });
}

std::string ROCKET_PerformanceModel::getPipelineStream(void)
{
  std::stringstream ret_strs;
  const int streamInstrIndex = instrIndex > 0 ? instrIndex - 1 : instrIndex;
  const uint64_t stage_gap_if_id = ID > IF ? ID - IF : 0;
  const uint64_t stage_gap_id_ex = EX > ID ? EX - ID : 0;
  const uint64_t stage_gap_ex_mem = MEM > EX ? MEM - EX : 0;
  const uint64_t stage_gap_mem_wb = WB > MEM ? WB - MEM : 0;
  
  ret_strs << IF; 
  ret_strs << "," << ID;
  ret_strs << "," << EX;
  ret_strs << "," << MEM;
  ret_strs << "," << WB;
  ret_strs << "," << instr_id;
  ret_strs << "," << pc_ptr[streamInstrIndex];
  ret_strs << "," << (uses_rs1 ? rs1_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (uses_rs2 ? rs2_ptr[streamInstrIndex] : 0);
  ret_strs << "," << (uses_rd ? rd_ptr[streamInstrIndex] : 0);
  ret_strs << "," << uses_rs1;
  ret_strs << "," << uses_rs2;
  ret_strs << "," << uses_rd;
  ret_strs << "," << stage_gap_if_id;
  ret_strs << "," << stage_gap_id_ex;
  ret_strs << "," << stage_gap_ex_mem;
  ret_strs << "," << stage_gap_mem_wb;
  ret_strs << "," << raw_wait_cycles;
  ret_strs << "," << raw_blocking_reg;
  ret_strs << "," << raw_blocking_ready_cycle;
  ret_strs << "," << icache_delay_cycles;
  ret_strs << "," << icache_miss;
  ret_strs << "," << dcache_delay_cycles;
  ret_strs << "," << dcache_miss;
  ret_strs << "," << branch_is_control;
  ret_strs << "," << branch_mispredict;
  ret_strs << "," << branch_redirect_cycles;
  ret_strs << "," << divider_delay_cycles;
  ret_strs << std::endl;
  instr_id++;
  uses_rs1 = 0;
  uses_rs2 = 0;
  uses_rd = 0;
  raw_wait_cycles = 0;
  raw_blocking_reg = -1;
  raw_blocking_ready_cycle = 0;
  icache_delay_cycles = 0;
  icache_miss = 0;
  dcache_delay_cycles = 0;
  dcache_miss = 0;
  branch_is_control = 0;
  branch_mispredict = 0;
  branch_redirect_cycles = 0;
  divider_delay_cycles = 0;
  return ret_strs.str();
}

std::string ROCKET_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "IF"; 
  ret_strs << "," << "ID";
  ret_strs << "," << "EX";
  ret_strs << "," << "MEM";
  ret_strs << "," << "WB";
  ret_strs << "," << "instr_id";
  ret_strs << "," << "pc";
  ret_strs << "," << "rs1";
  ret_strs << "," << "rs2";
  ret_strs << "," << "rd";
  ret_strs << "," << "uses_rs1";
  ret_strs << "," << "uses_rs2";
  ret_strs << "," << "uses_rd";
  ret_strs << "," << "stage_gap_if_id";
  ret_strs << "," << "stage_gap_id_ex";
  ret_strs << "," << "stage_gap_ex_mem";
  ret_strs << "," << "stage_gap_mem_wb";
  ret_strs << "," << "raw_wait_cycles";
  ret_strs << "," << "raw_blocking_reg";
  ret_strs << "," << "raw_blocking_ready_cycle";
  ret_strs << "," << "icache_delay_cycles";
  ret_strs << "," << "icache_miss";
  ret_strs << "," << "dcache_delay_cycles";
  ret_strs << "," << "dcache_miss";
  ret_strs << "," << "branch_is_control";
  ret_strs << "," << "branch_mispredict";
  ret_strs << "," << "branch_redirect_cycles";
  ret_strs << "," << "divider_delay_cycles";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace ROCKET
