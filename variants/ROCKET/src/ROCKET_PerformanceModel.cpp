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
  
  ret_strs << IF; 
  ret_strs << "," << ID;
  ret_strs << "," << EX;
  ret_strs << "," << MEM;
  ret_strs << "," << WB;
  ret_strs << std::endl;
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
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace ROCKET