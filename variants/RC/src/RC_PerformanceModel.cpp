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


#include "RC_PerformanceModel.h"

#include <stdbool.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "Channel.h"

#include "RC_Channel.h"

#include "models/rocket/BranchPredictionModel.h"
#include "models/rocket/RocketMulRegisterModel.h"
#include "models/rocket/ICacheModel.h"
#include "models/rocket/DCacheModel.h"

namespace RC{

void RC_PerformanceModel::connectChannel(Channel* channel_)
{
  RC_Channel* channel = static_cast<RC_Channel*>(channel_);

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

uint64_t RC_PerformanceModel::getCycleCount(void)
{
  
  return std::max({
    IF 
    ,ID
    ,EX
    ,MEM
    ,WB
  });
}

std::string RC_PerformanceModel::getPipelineStream(void)
{
  std::stringstream ret_strs;
  
  ret_strs << IF; 
  ret_strs << "," << ID;
  ret_strs << "," << EX;
  ret_strs << "," << MEM;
  ret_strs << "," << WB;
  ret_strs << std::endl;
  return ret_strs.str();
}

std::string RC_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "IF"; 
  ret_strs << "," << "ID";
  ret_strs << "," << "EX";
  ret_strs << "," << "MEM";
  ret_strs << "," << "WB";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace RC