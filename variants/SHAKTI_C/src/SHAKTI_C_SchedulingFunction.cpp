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

#include "SHAKTI_C_PerformanceModel.h"

namespace SHAKTI_C{

SchedulingFunctionSet* SHAKTI_C_SchedulingFunctionSet = new SchedulingFunctionSet("SHAKTI_C_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "add",
  0,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "sub",
  1,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "xor",
  2,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "or",
  3,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "and",
  4,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "slt",
  5,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "sltu",
  6,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "sll",
  7,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "srl",
  8,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "sra",
  9,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_addw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "addw",
  10,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_subw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "subw",
  11,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sllw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sllw",
  12,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_srlw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "srlw",
  13,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sraw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sraw",
  14,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "addi",
  15,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "xori",
  16,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "ori",
  17,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "andi",
  18,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "slti",
  19,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "sltiu",
  20,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "slli",
  21,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "srli",
  22,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "srai",
  23,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_addiw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "addiw",
  24,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_slliw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "slliw",
  25,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_srliw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "srliw",
  26,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sraiw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sraiw",
  27,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "auipc",
  28,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "lui",
  29,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "mul",
  30,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_mulw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "mulw",
  31,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "mulh",
  32,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "mulhu",
  33,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "mulhsu",
  34,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_div = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "div",
  35,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "rem",
  36,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_divw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "divw",
  37,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_remw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "remw",
  38,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "divu",
  39,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "remu",
  40,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_divuw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "divuw",
  41,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_remuw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "remuw",
  42,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
  SHAKTI_C_SchedulingFunctionSet,
  "csrrw",
  43,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "csrrs",
  44,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "csrrc",
  45,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "csrrwi",
  46,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "csrrsi",
  47,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "csrrci",
  48,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sb",
  49,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sh",
  50,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sw",
  51,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_sd = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "sd",
  52,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + 1;
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "lb",
  53,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "lbu",
  54,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "lh",
  55,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "lhu",
  56,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "lw",
  57,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lwu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "lwu",
  58,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_ld = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "ld",
  59,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
// LSU
uint64_t n_LSU;
n_LSU = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + 1;
perfModel->regModel.setXd(n_DPort_R);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DPort_R, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "beq",
  60,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
perfModel->dyBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "bne",
  61,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
perfModel->dyBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "blt",
  62,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
perfModel->dyBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "bge",
  63,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
perfModel->dyBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "bltu",
  64,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
perfModel->dyBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "bgeu",
  65,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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
perfModel->dyBranchPredModel.setPc_np(n_ALU);
// EX
uint64_t n_EX = n_ALU;
perfModel->EX = n_EX;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "jal",
  66,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "jalr",
  67,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
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

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  SHAKTI_C_SchedulingFunctionSet,
  "_def",
  68,
  [](PerformanceModel* perfModel_){
  SHAKTI_C_PerformanceModel* perfModel = static_cast<SHAKTI_C_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PCGEN;
// PC_Gen
uint64_t n_PC_Gen;
uint64_t n_PC_Gen_max;
n_PC_Gen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PC_Gen = n_PC_Gen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PC_Gen);
// PCGEN
uint64_t n_PCGEN;
n_PCGEN = std::max({n_PC_Gen, perfModel->IF});
perfModel->PCGEN = n_PCGEN;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_PCGEN, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + 1;
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID = n_Decoder;
perfModel->ID = n_ID;

  }
);


} // namespace SHAKTI_C