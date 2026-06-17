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


#include <algorithm>
#include <cstdint>

#include "PerformanceModel.h"

#include "FIVE_NFW_NPRE_PerformanceModel.h"

namespace FIVE_NFW_NPRE{

SchedulingFunctionSet* FIVE_NFW_NPRE_SchedulingFunctionSet = new SchedulingFunctionSet("FIVE_NFW_NPRE_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "_def",
  0,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen});
perfModel->IF_stage = n_IF_stage;

  }
);

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "auipc",
  1,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "lui",
  2,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "csrrsi",
  3,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "csrrci",
  4,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "addi",
  5,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "xori",
  6,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "ori",
  7,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "andi",
  8,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "slti",
  9,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sltiu",
  10,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "slli",
  11,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "srli",
  12,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "srai",
  13,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "csrrw",
  14,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "csrrs",
  15,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "csrrc",
  16,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "add",
  17,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sub",
  18,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "xor",
  19,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "or",
  20,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "and",
  21,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "slt",
  22,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sltu",
  23,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sll",
  24,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "srl",
  25,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sra",
  26,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "mul",
  27,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "mulh",
  28,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "mulhu",
  29,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "mulhsu",
  30,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "lw",
  31,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "lh",
  32,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "lhu",
  33,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "lb",
  34,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "lbu",
  35,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX_stage + perfModel->dMemModel.getDelay();
perfModel->regModel.setXd(n_DPort_R);
// MEM_stage
uint64_t n_MEM_stage;
n_MEM_stage = std::max({n_DPort_R, perfModel->WB_stage});
perfModel->MEM_stage = n_MEM_stage;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM_stage + 1;
// WB_stage
uint64_t n_WB_stage = n_Reg;
perfModel->WB_stage = n_WB_stage;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sw",
  36,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sh",
  37,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  }
);

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "sb",
  38,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// LSU
uint64_t n_LSU;
n_LSU = n_ID_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_LSU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "beq",
  39,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "bne",
  40,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "blt",
  41,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "bge",
  42,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "bltu",
  43,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "bgeu",
  44,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF_stage, perfModel->regModel.getXb()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "jal",
  45,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  FIVE_NFW_NPRE_SchedulingFunctionSet,
  "jalr",
  46,
  [](PerformanceModel* perfModel_){
  FIVE_NFW_NPRE_PerformanceModel* perfModel = static_cast<FIVE_NFW_NPRE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF_stage;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->staticBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->staticBranchPredModel.setPc_p(n_PCGen);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_IPort_R, n_PCGen, perfModel->ID_stage});
perfModel->IF_stage = n_IF_stage;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF_stage + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF_stage, perfModel->regModel.getXa()});
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, n_uA_OF_A, perfModel->EX_stage});
perfModel->ID_stage = n_ID_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_ID_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);


} // namespace FIVE_NFW_NPRE