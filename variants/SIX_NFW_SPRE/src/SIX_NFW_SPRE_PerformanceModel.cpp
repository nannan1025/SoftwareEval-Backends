/*
* Copyright 2025 Chair of EDA, Technical University of Munich
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


#include "SIX_NFW_SPRE_PerformanceModel.h"

#include <stdbool.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "Channel.h"

#include "SIX_NFW_SPRE_Channel.h"

#include "models/common/StaticBranchPredictModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/common/DummyMemoryModel.h"
#include "models/common/DummyMemoryModel.h"

namespace SIX_NFW_SPRE{

void SIX_NFW_SPRE_PerformanceModel::connectChannel(Channel* channel_)
{
  SIX_NFW_SPRE_Channel* channel = static_cast<SIX_NFW_SPRE_Channel*>(channel_);

  staticBranchPredModel.pc_ptr = channel->pc;
  staticBranchPredModel.brTarget_ptr = channel->brTarget;

  regModel.rs1_ptr = channel->rs1;
  regModel.rs2_ptr = channel->rs2;
  regModel.rd_ptr = channel->rd;



}

uint64_t SIX_NFW_SPRE_PerformanceModel::getCycleCount(void)
{
  
  return std::max({
    IF_stage 
    ,ID_stage
    ,IS_stage
    ,EX_stage
    ,MEM_stage
    ,WB_stage
  });
}

std::string SIX_NFW_SPRE_PerformanceModel::getPipelineStream(void)
{
  std::stringstream ret_strs;
  
  ret_strs << IF_stage; 
  ret_strs << "," << ID_stage;
  ret_strs << "," << IS_stage;
  ret_strs << "," << EX_stage;
  ret_strs << "," << MEM_stage;
  ret_strs << "," << WB_stage;
  ret_strs << std::endl;
  return ret_strs.str();
}

std::string SIX_NFW_SPRE_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "IF_stage"; 
  ret_strs << "," << "ID_stage";
  ret_strs << "," << "IS_stage";
  ret_strs << "," << "EX_stage";
  ret_strs << "," << "MEM_stage";
  ret_strs << "," << "WB_stage";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace SIX_NFW_SPRE