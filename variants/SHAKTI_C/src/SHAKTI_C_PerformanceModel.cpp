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


#include "SHAKTI_C_PerformanceModel.h"

#include <stdbool.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "Channel.h"

#include "SHAKTI_C_Channel.h"

#include "models/common/DynamicBranchPredictModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/cv32e40p/DividerModel.h"
#include "models/cv32e40p/DividerUnsignedModel.h"

namespace SHAKTI_C{

void SHAKTI_C_PerformanceModel::connectChannel(Channel* channel_)
{
  SHAKTI_C_Channel* channel = static_cast<SHAKTI_C_Channel*>(channel_);

  dyBranchPredModel.pc_ptr = channel->pc;
  dyBranchPredModel.brTarget_ptr = channel->brTarget;

  regModel.rs1_ptr = channel->rs1;
  regModel.rs2_ptr = channel->rs2;
  regModel.rd_ptr = channel->rd;

  divider.rs2_data_ptr = channel->rs2_data;

  divider_u.rs2_data_ptr = channel->rs2_data;

}

uint64_t SHAKTI_C_PerformanceModel::getCycleCount(void)
{
  
  return std::max({
    PCGEN 
    ,IF
    ,ID
    ,EX
    ,MEM
    ,WB
  });
}

std::string SHAKTI_C_PerformanceModel::getPipelineStream(void)
{
  std::stringstream ret_strs;
  
  ret_strs << PCGEN; 
  ret_strs << "," << IF;
  ret_strs << "," << ID;
  ret_strs << "," << EX;
  ret_strs << "," << MEM;
  ret_strs << "," << WB;
  ret_strs << std::endl;
  return ret_strs.str();
}

std::string SHAKTI_C_PerformanceModel::getPrintHeader(void)
{
  std::stringstream ret_strs;
  
  ret_strs << "PCGEN"; 
  ret_strs << "," << "IF";
  ret_strs << "," << "ID";
  ret_strs << "," << "EX";
  ret_strs << "," << "MEM";
  ret_strs << "," << "WB";
  ret_strs << std::endl;
  return ret_strs.str();
}

} // namespace SHAKTI_C