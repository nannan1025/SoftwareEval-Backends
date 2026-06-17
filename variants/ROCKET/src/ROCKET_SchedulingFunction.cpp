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

#include "ROCKET_PerformanceModel.h"

namespace ROCKET{

SchedulingFunctionSet* ROCKET_SchedulingFunctionSet = new SchedulingFunctionSet("ROCKET_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "add",
  0,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ADD
uint64_t n_ADD;
n_ADD = n_ID + 3;
perfModel->regModel.setXd(n_ADD);
// EX
uint64_t n_EX;
n_EX = std::max({n_ADD, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sub",
  1,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// SUB
uint64_t n_SUB;
n_SUB = n_ID + 3;
perfModel->regModel.setXd(n_SUB);
// EX
uint64_t n_EX;
n_EX = std::max({n_SUB, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sra",
  2,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// SRA
uint64_t n_SRA;
n_SRA = n_ID + 2;
perfModel->regModel.setXd(n_SRA);
// EX
uint64_t n_EX;
n_EX = std::max({n_SRA, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "xor",
  3,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "or",
  4,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "and",
  5,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slt",
  6,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sltu",
  7,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sll",
  8,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srl",
  9,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sraw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sraw",
  10,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_addw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "addw",
  11,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_subw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "subw",
  12,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "addi",
  13,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "xori",
  14,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "ori",
  15,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "andi",
  16,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slti",
  17,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sltiu",
  18,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slli",
  19,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srli",
  20,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srai",
  21,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_addiw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "addiw",
  22,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slliw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slliw",
  23,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sraiw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sraiw",
  24,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srliw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srliw",
  25,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "auipc",
  26,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lui",
  27,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// ALUForward
uint64_t n_ALUForward;
n_ALUForward = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_ALUForward, perfModel->WB});
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
  ROCKET_SchedulingFunctionSet,
  "mul",
  28,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
n_MUL = n_ID + 3;
perfModel->regModel.setXd(n_MUL);
// EX
uint64_t n_EX;
n_EX = std::max({n_MUL, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulw",
  29,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// MULW
uint64_t n_MULW;
n_MULW = n_ID + 3;
perfModel->regModel.setXd(n_MULW);
// EX
uint64_t n_EX;
n_EX = std::max({n_MULW, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulh",
  30,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
n_MULH = n_ID + 4;
perfModel->regModel.setXd(n_MULH);
// EX
uint64_t n_EX;
n_EX = std::max({n_MULH, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulhu",
  31,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
n_MULH = n_ID + 4;
perfModel->regModel.setXd(n_MULH);
// EX
uint64_t n_EX;
n_EX = std::max({n_MULH, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulhsu",
  32,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
n_MULH = n_ID + 4;
perfModel->regModel.setXd(n_MULH);
// EX
uint64_t n_EX;
n_EX = std::max({n_MULH, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_div = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "div",
  33,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_rem = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "rem",
  34,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_divw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "divw",
  35,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_remw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "remw",
  36,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_divu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "divu",
  37,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_remu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "remu",
  38,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_divuw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "divuw",
  39,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_remuw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "remuw",
  40,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
uint64_t n_EX;
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrw",
  41,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->regModel.setXd(n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrs",
  42,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->regModel.setXd(n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrc",
  43,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->regModel.setXd(n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrwi",
  44,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrsi",
  45,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrci",
  46,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
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
  ROCKET_SchedulingFunctionSet,
  "sb",
  47,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sh",
  48,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sw",
  49,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sd = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sd",
  50,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lb",
  51,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lbu",
  52,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lh",
  53,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lhu",
  54,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lw",
  55,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_ld = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "ld",
  56,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lwu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lwu",
  57,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->regModel.setXd(n_LoadWB);
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "beq",
  58,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bne",
  59,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "blt",
  60,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bge",
  61,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bltu",
  62,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bgeu",
  63,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Retire
uint64_t n_Retire;
n_Retire = n_MEM + 1;
// WB
uint64_t n_WB = n_Retire;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "jal",
  64,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p_j(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->regModel.setXd(n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "jalr",
  65,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->dynBranchPredModel.setPc_p_jr(n_BPU);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, n_BPU, perfModel->ID});
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
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->regModel.setXd(n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "_def",
  66,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->IF;
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_mp()});
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_Enter, perfModel->iCacheModel.getIc_out()});
// uA_PcPredict
uint64_t n_uA_PcPredict;
n_uA_PcPredict = std::max({n_Enter, perfModel->dynBranchPredModel.getPc_pt()});
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
// ID
uint64_t n_ID;
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);


} // namespace ROCKET