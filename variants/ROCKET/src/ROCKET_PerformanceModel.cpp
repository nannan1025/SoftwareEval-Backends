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
#include <vector>

#include "Channel.h"

#include "ROCKET_Channel.h"

#include "models/rocket/BranchPredictionModel.h"
#include "models/rocket/RocketMulRegisterModel.h"
#include "models/rocket/ICacheModel.h"
#include "models/rocket/DCacheModel.h"

namespace ROCKET{

const std::vector<std::string>& ROCKET_PerformanceModel::getSchedTraceColumns(void)
{
  static const std::vector<std::string> columns = {
    "IF_n_Enter",
    "IF_n_PC_Gen",
    "IF_n_uA_PcCorrect",
    "IF_n_uA_CacheBlock",
    "IF_n_uA_PcPredict",
    "IF_n_ITLB",
    "IF_n_ICache",
    "IF_n_BPU",
    "IF_prev_ID",
    "IF_ext_Pc_mp",
    "IF_ext_Pc_pt",
    "IF_ext_Pc_p",
    "IF_ext_Pc_p_j",
    "IF_ext_Pc_p_jr",
    "IF_ext_Ic_out",
    "ID_n_Decoder",
    "ID_rs1_ready_cycle",
    "ID_rs2_ready_cycle",
    "ID_n_uA_OF_A",
    "ID_n_uA_OF_B",
    "ID_prev_EX",
    "EX_n_ALU",
    "EX_ext_MulReady",
    "EX_n_MUL_max",
    "EX_n_MUL",
    "EX_ext_DivReady",
    "EX_n_DIV_max",
    "EX_n_DIV",
    "EX_n_DIVU_max",
    "EX_n_DIVU",
    "EX_n_EXPass",
    "EX_n_DTLB",
    "EX_n_LSUReq",
    "EX_prev_MEM",
    "MEM_n_MEMPass",
    "MEM_n_DCache",
    "MEM_n_StoreCommit",
    "MEM_n_Branch",
    "MEM_n_FlushMem",
    "MEM_prev_WB",
    "MEM_ext_Pc_c",
    "WB_n_Reg",
    "WB_n_CSR",
    "WB_n_WBPass",
    "WB_n_LoadWB"
  };
  return columns;
}

std::string ROCKET_PerformanceModel::getSchedTraceValue(const std::string& name) const
{
  auto iter = trace_sched_vars.find(name);
  if(iter == trace_sched_vars.end())
  {
    return "null";
  }
  return std::to_string(iter->second);
}

std::string ROCKET_PerformanceModel::getChannelValue(uint64_t* ptr, int streamInstrIndex) const
{
  if(ptr == nullptr)
  {
    return "null";
  }
  return std::to_string(ptr[streamInstrIndex]);
}

std::string ROCKET_PerformanceModel::csvEscape(const std::string& value) const
{
  bool needsQuotes = value.find_first_of(",\"\n\r") != std::string::npos;
  if(!needsQuotes)
  {
    return value;
  }
  std::string escaped = "\"";
  for(char c : value)
  {
    if(c == '"')
    {
      escaped += "\"\"";
    }
    else
    {
      escaped += c;
    }
  }
  escaped += "\"";
  return escaped;
}

void ROCKET_PerformanceModel::setInstructionInfo(const std::string& instr, bool usedRs1, bool usedRs2, bool usedRd)
{
  trace_instr = instr;
  trace_used_rs1 = usedRs1;
  trace_used_rs2 = usedRs2;
  trace_used_rd = usedRd;
}

void ROCKET_PerformanceModel::recordSchedVar(const std::string& name, uint64_t value)
{
  trace_sched_vars[name] = value;
}

void ROCKET_PerformanceModel::setICacheInstrumentation(uint64_t delay, bool miss)
{
  trace_icache_delay_cycles = delay;
  trace_icache_miss = miss;
}

void ROCKET_PerformanceModel::setDCacheInstrumentation(uint64_t delay, bool miss)
{
  trace_dcache_delay_cycles = delay;
  trace_dcache_miss = miss;
}

void ROCKET_PerformanceModel::setSimMisprediction(uint64_t misprediction)
{
  trace_sim_misprediction = misprediction;
}

void ROCKET_PerformanceModel::setRdReadyCycle(uint64_t cycle)
{
  trace_has_rd_ready_cycle = true;
  trace_rd_ready_cycle = cycle;
}

void ROCKET_PerformanceModel::resetTraceState(void)
{
  trace_instr = "unknown";
  trace_used_rs1 = false;
  trace_used_rs2 = false;
  trace_used_rd = false;
  trace_has_rd_ready_cycle = false;
  trace_rd_ready_cycle = 0;
  trace_icache_miss = false;
  trace_dcache_miss = false;
  trace_icache_delay_cycles = 0;
  trace_dcache_delay_cycles = 0;
  trace_sim_misprediction = 0;
  trace_sched_vars.clear();
}

void ROCKET_PerformanceModel::connectChannel(Channel* channel_)
{
  ROCKET_Channel* channel = static_cast<ROCKET_Channel*>(channel_);

  pc_ptr = channel->pc;
  rd_ptr = channel->rd;
  rs1_ptr = channel->rs1;
  rs2_ptr = channel->rs2;
  imm_ptr = channel->imm;
  rs1_data_ptr = channel->rs1_data;
  rs2_data_ptr = channel->rs2_data;

  dynBranchPredModel.pc_ptr = channel->pc;
  dynBranchPredModel.brTarget_ptr = channel->brTarget;
  dynBranchPredModel.rs1_ptr = channel->rs1;
  dynBranchPredModel.rd_ptr = channel->rd;
  dynBranchPredModel.imm_ptr = channel->imm;

  regModel.rs1_ptr = channel->rs1;
  regModel.rs2_ptr = channel->rs2;
  regModel.rd_ptr = channel->rd;

  iCacheModel.pc_ptr = channel->pc;

  dCacheModel.addr_ptr = channel->addr;

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
  
  ret_strs << getChannelValue(pc_ptr, streamInstrIndex);
  ret_strs << "," << csvEscape(trace_instr);
  ret_strs << "," << getChannelValue(rd_ptr, streamInstrIndex);
  ret_strs << "," << getChannelValue(rs1_ptr, streamInstrIndex);
  ret_strs << "," << getChannelValue(rs2_ptr, streamInstrIndex);
  ret_strs << "," << getChannelValue(imm_ptr, streamInstrIndex);
  ret_strs << "," << getChannelValue(rs1_data_ptr, streamInstrIndex);
  ret_strs << "," << getChannelValue(rs2_data_ptr, streamInstrIndex);
  ret_strs << "," << IF; 
  ret_strs << "," << ID;
  ret_strs << "," << EX;
  ret_strs << "," << MEM;
  ret_strs << "," << WB;
  for(const auto& column : getSchedTraceColumns())
  {
    ret_strs << "," << getSchedTraceValue(column);
  }
  ret_strs << "," << (trace_used_rs1 ? 1 : 0);
  ret_strs << "," << (trace_used_rs2 ? 1 : 0);
  ret_strs << "," << (trace_used_rd ? 1 : 0);
  ret_strs << "," << (trace_has_rd_ready_cycle ? std::to_string(trace_rd_ready_cycle) : "null");
  ret_strs << "," << (trace_icache_miss ? 1 : 0);
  ret_strs << "," << (trace_dcache_miss ? 1 : 0);
  ret_strs << "," << trace_icache_delay_cycles;
  ret_strs << "," << trace_dcache_delay_cycles;
  ret_strs << "," << trace_sim_misprediction;
  ret_strs << std::endl;
  resetTraceState();
  return ret_strs.str();
}

std::string ROCKET_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "pc";
  ret_strs << "," << "instr";
  ret_strs << "," << "rd";
  ret_strs << "," << "rs1";
  ret_strs << "," << "rs2";
  ret_strs << "," << "imm";
  ret_strs << "," << "rs1_data";
  ret_strs << "," << "rs2_data";
  ret_strs << "," << "IF"; 
  ret_strs << "," << "ID";
  ret_strs << "," << "EX";
  ret_strs << "," << "MEM";
  ret_strs << "," << "WB";
  for(const auto& column : getSchedTraceColumns())
  {
    ret_strs << "," << column;
  }
  ret_strs << "," << "used_rs1";
  ret_strs << "," << "used_rs2";
  ret_strs << "," << "used_rd";
  ret_strs << "," << "rd_ready_cycle";
  ret_strs << "," << "icache_miss";
  ret_strs << "," << "dcache_miss";
  ret_strs << "," << "icache_delay_cycles";
  ret_strs << "," << "dcache_delay_cycles";
  ret_strs << "," << "sim_misprediction";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace ROCKET
