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

#include "SIX_NFW_SPRE_PerformanceModel.h"

namespace SIX_NFW_SPRE{

SchedulingFunctionSet* SIX_NFW_SPRE_SchedulingFunctionSet = new SchedulingFunctionSet("SIX_NFW_SPRE_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "_def",
  0,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "auipc",
  1,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lui",
  2,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "addi",
  3,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "xori",
  4,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "ori",
  5,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "andi",
  6,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "slti",
  7,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sltiu",
  8,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "slli",
  9,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "srli",
  10,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "srai",
  11,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_addiw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "addiw",
  12,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slliw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "slliw",
  13,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srliw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "srliw",
  14,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sraiw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sraiw",
  15,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "add",
  16,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sub",
  17,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "xor",
  18,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "or",
  19,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "and",
  20,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "slt",
  21,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sltu",
  22,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sll",
  23,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "srl",
  24,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sra",
  25,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_addw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "addw",
  26,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_subw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "subw",
  27,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sllw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sllw",
  28,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_srlw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "srlw",
  29,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_sraw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sraw",
  30,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "mul",
  31,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "mulw",
  32,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "mulh",
  33,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "mulhu",
  34,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "mulhsu",
  35,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// MUL
uint64_t n_MUL;
n_MUL = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_MUL;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "csrrw",
  36,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// CSR
uint64_t n_CSR;
n_CSR = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_CSR;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "csrrs",
  37,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// CSR
uint64_t n_CSR;
n_CSR = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_CSR;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "csrrc",
  38,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// CSR
uint64_t n_CSR;
n_CSR = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_CSR;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "csrrwi",
  39,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// CSR
uint64_t n_CSR;
n_CSR = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_CSR;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "csrrsi",
  40,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// CSR
uint64_t n_CSR;
n_CSR = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_CSR;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "csrrci",
  41,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// CSR
uint64_t n_CSR;
n_CSR = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage = n_CSR;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lb",
  42,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lbu",
  43,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lh",
  44,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lhu",
  45,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lw",
  46,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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

static SchedulingFunction *schedulingFunction_lwu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "lwu",
  47,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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

static SchedulingFunction *schedulingFunction_ld = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "ld",
  48,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sb",
  49,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sh",
  50,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sw",
  51,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
perfModel->EX_stage = n_EX_stage;
// DPort_W
uint64_t n_DPort_W;
n_DPort_W = n_EX_stage + perfModel->dMemModel.getDelay();
// MEM_stage
uint64_t n_MEM_stage = n_DPort_W;
perfModel->MEM_stage = n_MEM_stage;

  }
);

static SchedulingFunction *schedulingFunction_sd = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "sd",
  52,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_ALU, perfModel->MEM_stage});
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
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "beq",
  53,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "bne",
  54,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "blt",
  55,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "bge",
  56,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "bltu",
  57,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "bgeu",
  58,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_OperandFetch_B
uint64_t n_uA_OperandFetch_B;
n_uA_OperandFetch_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_uA_OperandFetch_B, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "jal",
  59,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  SIX_NFW_SPRE_SchedulingFunctionSet,
  "jalr",
  60,
  [](PerformanceModel* perfModel_){
  SIX_NFW_SPRE_PerformanceModel* perfModel = static_cast<SIX_NFW_SPRE_PerformanceModel*>(perfModel_);
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
n_ID_stage = std::max({n_Decoder, perfModel->IS_stage});
perfModel->ID_stage = n_ID_stage;
// uA_OperandFetch_A
uint64_t n_uA_OperandFetch_A;
n_uA_OperandFetch_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// Instruction_Issue
uint64_t n_Instruction_Issue;
n_Instruction_Issue = n_ID_stage + 1;
// IS_stage
uint64_t n_IS_stage;
n_IS_stage = std::max({n_uA_OperandFetch_A, n_Instruction_Issue, perfModel->EX_stage});
perfModel->IS_stage = n_IS_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_IS_stage + 1;
perfModel->staticBranchPredModel.setPc_np(n_ALU);
// EX_stage
uint64_t n_EX_stage = n_ALU;
perfModel->EX_stage = n_EX_stage;

  }
);


} // namespace SIX_NFW_SPRE