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


#ifndef SWEVAL_BACKENDS_FIVE_NFW_NPRE_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_FIVE_NFW_NPRE_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <cstdint>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/common/StaticBranchPredictModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/common/DummyMemoryModel.h"
#include "models/common/DummyMemoryModel.h"

namespace FIVE_NFW_NPRE{

extern SchedulingFunctionSet* FIVE_NFW_NPRE_SchedulingFunctionSet;

class FIVE_NFW_NPRE_PerformanceModel : public PerformanceModel
{
public:

  FIVE_NFW_NPRE_PerformanceModel() : PerformanceModel("FIVE_NFW_NPRE", FIVE_NFW_NPRE_SchedulingFunctionSet)
    ,staticBranchPredModel(this)
    ,regModel(this)
    ,iMemModel(this)
    ,dMemModel(this)
  {};

  // Single-Element Timing Variables
  uint64_t IF_stage = 0;
  uint64_t ID_stage = 0;
  uint64_t EX_stage = 0;
  uint64_t MEM_stage = 0;
  uint64_t WB_stage = 0;


  // External Resource Models
  common::StaticBranchPredictModel staticBranchPredModel;
  common::StandardRegisterModel regModel;
  common::DummyMemoryModel iMemModel;
  common::DummyMemoryModel dMemModel;

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);

};

} // namespace FIVE_NFW_NPRE

#endif // SWEVAL_BACKENDS_FIVE_NFW_NPRE_PERFORMANCE_MODEL_H