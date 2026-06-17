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

#include "LAMP_PerformanceModel.h"

namespace LAMP{

SchedulingFunctionSet* LAMP_SchedulingFunctionSet = new SchedulingFunctionSet("LAMP_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "_def",
  0,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID = n_Decoder;
perfModel->ID = n_ID;

  }
);

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "auipc",
  1,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "lui",
  2,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "csrrsi",
  3,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "csrrci",
  4,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "addi",
  5,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "xori",
  6,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "ori",
  7,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "andi",
  8,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "slti",
  9,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "sltiu",
  10,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "slli",
  11,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "srli",
  12,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "srai",
  13,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "csrrw",
  14,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "csrrs",
  15,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "csrrc",
  16,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "add",
  17,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "sub",
  18,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "xor",
  19,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "or",
  20,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "and",
  21,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "slt",
  22,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "sltu",
  23,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "sll",
  24,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "srl",
  25,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "sra",
  26,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "beq",
  27,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
// Branch_ALU
uint64_t n_Branch_ALU;
n_Branch_ALU = n_ID + 1;
perfModel->dyBranchPredModel.setPc_np(n_Branch_ALU);
// EX
uint64_t n_EX;
n_EX = std::max({n_Branch_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM = n_PCUpdater;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "bne",
  28,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
// Branch_ALU
uint64_t n_Branch_ALU;
n_Branch_ALU = n_ID + 1;
perfModel->dyBranchPredModel.setPc_np(n_Branch_ALU);
// EX
uint64_t n_EX;
n_EX = std::max({n_Branch_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM = n_PCUpdater;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "blt",
  29,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
// Branch_ALU
uint64_t n_Branch_ALU;
n_Branch_ALU = n_ID + 1;
perfModel->dyBranchPredModel.setPc_np(n_Branch_ALU);
// EX
uint64_t n_EX;
n_EX = std::max({n_Branch_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM = n_PCUpdater;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "bge",
  30,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
// Branch_ALU
uint64_t n_Branch_ALU;
n_Branch_ALU = n_ID + 1;
perfModel->dyBranchPredModel.setPc_np(n_Branch_ALU);
// EX
uint64_t n_EX;
n_EX = std::max({n_Branch_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM = n_PCUpdater;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "bltu",
  31,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
// Branch_ALU
uint64_t n_Branch_ALU;
n_Branch_ALU = n_ID + 1;
perfModel->dyBranchPredModel.setPc_np(n_Branch_ALU);
// EX
uint64_t n_EX;
n_EX = std::max({n_Branch_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM = n_PCUpdater;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "bgeu",
  32,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
// Branch_ALU
uint64_t n_Branch_ALU;
n_Branch_ALU = n_ID + 1;
perfModel->dyBranchPredModel.setPc_np(n_Branch_ALU);
// EX
uint64_t n_EX;
n_EX = std::max({n_Branch_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM = n_PCUpdater;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "jal",
  33,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_PCUpdater, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "jalr",
  34,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// PCUpdater
uint64_t n_PCUpdater;
uint64_t n_PCUpdater_max;
n_PCUpdater_max = std::max({n_EX, perfModel->dyBranchPredModel.getPc()});
n_PCUpdater = n_PCUpdater_max + 1;
perfModel->dyBranchPredModel.setPc_np(n_PCUpdater);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_PCUpdater, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "mul",
  35,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "mulh",
  36,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "mulhu",
  37,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "mulhsu",
  38,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "div",
  39,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "rem",
  40,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "divu",
  41,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
  LAMP_SchedulingFunctionSet,
  "remu",
  42,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "lh",
  43,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + perfModel->dMemModel.getDelay();
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
  LAMP_SchedulingFunctionSet,
  "lhu",
  44,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + perfModel->dMemModel.getDelay();
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

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "lb",
  45,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + perfModel->dMemModel.getDelay();
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
  LAMP_SchedulingFunctionSet,
  "lbu",
  46,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + perfModel->dMemModel.getDelay();
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
  LAMP_SchedulingFunctionSet,
  "lw",
  47,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_R
uint64_t n_DPort_R;
n_DPort_R = n_EX + perfModel->dMemModel.getDelay();
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

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "sb",
  48,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + perfModel->dMemModel.getDelay();
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "sh",
  49,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + perfModel->dMemModel.getDelay();
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  LAMP_SchedulingFunctionSet,
  "sw",
  50,
  [](PerformanceModel* perfModel_){
  LAMP_PerformanceModel* perfModel = static_cast<LAMP_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// IPort_R
uint64_t n_IPort_R;
uint64_t n_IPort_R_max;
n_IPort_R_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_IPort_R = n_IPort_R_max + perfModel->iMemModel.getDelay();
// PCGen
uint64_t n_PCGen;
uint64_t n_PCGen_max;
n_PCGen_max = std::max({n_Enter, perfModel->dyBranchPredModel.getPc()});
n_PCGen = n_PCGen_max + 1;
perfModel->dyBranchPredModel.setPc_p(n_PCGen);
// IF
uint64_t n_IF;
n_IF = std::max({n_IPort_R, n_PCGen, perfModel->ID});
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
n_EX = std::max({n_LSU, perfModel->MEM});
perfModel->EX = n_EX;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX + perfModel->dMemModel.getDelay();
// MEM
uint64_t n_MEM = n_DPort_W;
perfModel->MEM = n_MEM;

  }
);


} // namespace LAMP