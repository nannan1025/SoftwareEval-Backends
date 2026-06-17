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


#ifndef SWEVAL_BACKENDS_SHAKTI_C_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_SHAKTI_C_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <cstdint>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/common/DynamicBranchPredictModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/cv32e40p/DividerModel.h"
#include "models/cv32e40p/DividerUnsignedModel.h"

namespace SHAKTI_C{

extern SchedulingFunctionSet* SHAKTI_C_SchedulingFunctionSet;

class SHAKTI_C_PerformanceModel : public PerformanceModel
{
public:

  SHAKTI_C_PerformanceModel() : PerformanceModel("SHAKTI_C", SHAKTI_C_SchedulingFunctionSet)
    ,dyBranchPredModel(this)
    ,regModel(this)
    ,divider(this)
    ,divider_u(this)
  {};

  // Single-Element Timing Variables
  uint64_t PCGEN = 0;
  uint64_t IF = 0;
  uint64_t ID = 0;
  uint64_t EX = 0;
  uint64_t MEM = 0;
  uint64_t WB = 0;


  // External Resource Models
  common::DynamicBranchPredictModel dyBranchPredModel;
  common::StandardRegisterModel regModel;
  cv32e40p::DividerModel divider;
  cv32e40p::DividerUnsignedModel divider_u;

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);

};

} // namespace SHAKTI_C

#endif // SWEVAL_BACKENDS_SHAKTI_C_PERFORMANCE_MODEL_H