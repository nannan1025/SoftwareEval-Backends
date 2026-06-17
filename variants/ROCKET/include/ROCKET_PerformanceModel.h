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


#ifndef SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H
#define SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H

#include <stdbool.h>
#include <string>
#include <cstdint>

#include "PerformanceModel.h"
#include "Channel.h"

#include "models/rocket/BranchPredictionModel.h"
#include "models/common/StandardRegisterModel.h"
#include "models/rocket/ICacheModel.h"
#include "models/rocket/DividerModel.h"
#include "models/rocket/DividerUnsignedModel.h"
#include "models/rocket/DCacheModel.h"

namespace ROCKET{

extern SchedulingFunctionSet* ROCKET_SchedulingFunctionSet;

class ROCKET_PerformanceModel : public PerformanceModel
{
public:

  ROCKET_PerformanceModel() : PerformanceModel("ROCKET", ROCKET_SchedulingFunctionSet)
    ,dynBranchPredModel(this)
    ,regModel(this)
    ,iCacheModel(this)
    ,divider(this)
    ,divider_u(this)
    ,dCacheModel(this)
  {};

  // Single-Element Timing Variables
  uint64_t IF = 0;
  uint64_t ID = 0;
  uint64_t EX = 0;
  uint64_t MEM = 0;
  uint64_t WB = 0;


  // External Resource Models
  rocket::BranchPredictionModel dynBranchPredModel;
  common::StandardRegisterModel regModel;
  rocket::ICacheModel iCacheModel;
  rocket::DividerModel divider;
  rocket::DividerUnsignedModel divider_u;
  rocket::DCacheModel dCacheModel;

  virtual void connectChannel(Channel*);
  virtual uint64_t getCycleCount(void);
  virtual std::string getPipelineStream(void);
  virtual std::string getPrintHeader(void);

};

} // namespace ROCKET

#endif // SWEVAL_BACKENDS_ROCKET_PERFORMANCE_MODEL_H