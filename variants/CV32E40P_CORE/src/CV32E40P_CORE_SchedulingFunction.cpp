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


#include <algorithm>
#include <cstdint>

#include "PerformanceModel.h"

#include "CV32E40P_CORE_PerformanceModel.h"

namespace CV32E40P_CORE{

SchedulingFunctionSet* CV32E40P_CORE_SchedulingFunctionSet = new SchedulingFunctionSet("CV32E40P_CORE_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "add",
  0,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sub",
  1,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "xor",
  2,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "or",
  3,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "and",
  4,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "slt",
  5,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sltu",
  6,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sll",
  7,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "srl",
  8,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sra",
  9,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "addi",
  10,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "xori",
  11,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "ori",
  12,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "andi",
  13,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "slti",
  14,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sltiu",
  15,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "slli",
  16,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "srli",
  17,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "srai",
  18,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "auipc",
  19,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "lui",
  20,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "mul",
  21,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MUL
uint64_t n_MUL;
n_MUL = n_ID + 1;
perfModel->regModel.setXd(n_MUL);
// EX
uint64_t n_EX = n_MUL;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "mulh",
  22,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MULH
uint64_t n_MULH;
n_MULH = n_ID + 5;
perfModel->regModel.setXd(n_MULH);
// EX
uint64_t n_EX = n_MULH;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "mulhu",
  23,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MULH
uint64_t n_MULH;
n_MULH = n_ID + 5;
perfModel->regModel.setXd(n_MULH);
// EX
uint64_t n_EX = n_MULH;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "mulhsu",
  24,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MULH
uint64_t n_MULH;
n_MULH = n_ID + 5;
perfModel->regModel.setXd(n_MULH);
// EX
uint64_t n_EX = n_MULH;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_div = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "div",
  25,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIV
uint64_t n_DIV;
n_DIV = n_ID + perfModel->divider.getDelay();
perfModel->regModel.setXd(n_DIV);
// EX
uint64_t n_EX = n_DIV;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_rem = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "rem",
  26,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIV
uint64_t n_DIV;
n_DIV = n_ID + perfModel->divider.getDelay();
perfModel->regModel.setXd(n_DIV);
// EX
uint64_t n_EX = n_DIV;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_divu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "divu",
  27,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIVU
uint64_t n_DIVU;
n_DIVU = n_ID + perfModel->divider_u.getDelay();
perfModel->regModel.setXd(n_DIVU);
// EX
uint64_t n_EX = n_DIVU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_remu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "remu",
  28,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIVU
uint64_t n_DIVU;
n_DIVU = n_ID + perfModel->divider_u.getDelay();
perfModel->regModel.setXd(n_DIVU);
// EX
uint64_t n_EX = n_DIVU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "csrrw",
  29,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// CSR
uint64_t n_CSR;
n_CSR = n_ID + 1;
perfModel->regModel.setXd(n_CSR);
// EX
uint64_t n_EX = n_CSR;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "csrrs",
  30,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// CSR
uint64_t n_CSR;
n_CSR = n_ID + 1;
perfModel->regModel.setXd(n_CSR);
// EX
uint64_t n_EX = n_CSR;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "csrrc",
  31,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// CSR
uint64_t n_CSR;
n_CSR = n_ID + 1;
perfModel->regModel.setXd(n_CSR);
// EX
uint64_t n_EX = n_CSR;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "csrrwi",
  32,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// CSR
uint64_t n_CSR;
n_CSR = n_ID + 1;
perfModel->regModel.setXd(n_CSR);
// EX
uint64_t n_EX = n_CSR;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "csrrsi",
  33,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// CSR
uint64_t n_CSR;
n_CSR = n_ID + 1;
perfModel->regModel.setXd(n_CSR);
// EX
uint64_t n_EX = n_CSR;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "csrrci",
  34,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// CSR
uint64_t n_CSR;
n_CSR = n_ID + 1;
perfModel->regModel.setXd(n_CSR);
// EX
uint64_t n_EX = n_CSR;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sb",
  35,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// WB
uint64_t n_WB = n_DPort_W;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sh",
  36,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// WB
uint64_t n_WB = n_DPort_W;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "sw",
  37,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// WB
uint64_t n_WB = n_DPort_W;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "lw",
  38,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// WB
uint64_t n_WB = n_DPort_R;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "lh",
  39,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// WB
uint64_t n_WB = n_DPort_R;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "lhu",
  40,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// WB
uint64_t n_WB = n_DPort_R;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "lb",
  41,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// WB
uint64_t n_WB = n_DPort_R;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "lbu",
  42,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_LSU, perfModel->WB});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// WB
uint64_t n_WB = n_DPort_R;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "beq",
  43,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "bne",
  44,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "blt",
  45,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "bge",
  46,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "bltu",
  47,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "bgeu",
  48,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->regModel.getXa()});
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->regModel.getXb()});
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->staBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "_def",
  49,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen});
perfModel->IF = n_IF;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "jal",
  50,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// JumpDecoder
uint64_t n_JumpDecoder;
n_JumpDecoder = n_IF + 1;
perfModel->staBranchPredModel.setPc_np(n_JumpDecoder);
// ID
uint64_t n_ID;
n_ID = std::max({n_JumpDecoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  CV32E40P_CORE_SchedulingFunctionSet,
  "jalr",
  51,
  [](PerformanceModel* perfModel_){
  CV32E40P_CORE_PerformanceModel* perfModel = static_cast<CV32E40P_CORE_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->staBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->staBranchPredModel.setPc_p(n_PC_Gen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PC_Gen, perfModel->ID});
perfModel->IF = n_IF;
// JumpDecoder
uint64_t n_JumpDecoder;
uint64_t n_JumpDecoder_max;
n_JumpDecoder_max = std::max({n_IF, perfModel->regModel.getXa()});
n_JumpDecoder = n_JumpDecoder_max + 1;
perfModel->staBranchPredModel.setPc_np(n_JumpDecoder);
// ID
uint64_t n_ID;
n_ID = std::max({n_JumpDecoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->regModel.setXd(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);


} // namespace CV32E40P_CORE