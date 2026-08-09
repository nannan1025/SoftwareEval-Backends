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

#include "RC_PerformanceModel.h"

namespace RC{

SchedulingFunctionSet* RC_SchedulingFunctionSet = new SchedulingFunctionSet("RC_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "add",
  0,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sub",
  1,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "xor",
  2,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "or",
  3,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "and",
  4,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "slt",
  5,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sltu",
  6,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sll",
  7,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "srl",
  8,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sra",
  9,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_addw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "addw",
  10,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_subw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "subw",
  11,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "addi",
  12,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "xori",
  13,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "ori",
  14,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "andi",
  15,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "slti",
  16,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sltiu",
  17,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "slli",
  18,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "srli",
  19,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "srai",
  20,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_addiw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "addiw",
  21,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_slliw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "slliw",
  22,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_sraiw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sraiw",
  23,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_srliw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "srliw",
  24,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "auipc",
  25,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lui",
  26,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "mul",
  27,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_MUL_max;
n_MUL_max = std::max({n_ID, perfModel->regModel.getMulReady()});
n_MUL = n_MUL_max + 1;
perfModel->regModel.setMulIssue(n_MUL);
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
  RC_SchedulingFunctionSet,
  "mulw",
  28,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_MUL_max;
n_MUL_max = std::max({n_ID, perfModel->regModel.getMulReady()});
n_MUL = n_MUL_max + 1;
perfModel->regModel.setMulIssue(n_MUL);
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

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "mulh",
  29,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_MUL_max;
n_MUL_max = std::max({n_ID, perfModel->regModel.getMulReady()});
n_MUL = n_MUL_max + 1;
perfModel->regModel.setMulIssue(n_MUL);
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

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "mulhu",
  30,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_MUL_max;
n_MUL_max = std::max({n_ID, perfModel->regModel.getMulReady()});
n_MUL = n_MUL_max + 1;
perfModel->regModel.setMulIssue(n_MUL);
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

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "mulhsu",
  31,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_MUL_max;
n_MUL_max = std::max({n_ID, perfModel->regModel.getMulReady()});
n_MUL = n_MUL_max + 1;
perfModel->regModel.setMulIssue(n_MUL);
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

static SchedulingFunction *schedulingFunction_div = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "div",
  32,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIV_max;
n_DIV_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIV = n_DIV_max + 1;
perfModel->regModel.setDivIssue(n_DIV);
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
  RC_SchedulingFunctionSet,
  "rem",
  33,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIV_max;
n_DIV_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIV = n_DIV_max + 1;
perfModel->regModel.setDivIssue(n_DIV);
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
  RC_SchedulingFunctionSet,
  "divw",
  34,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIV_max;
n_DIV_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIV = n_DIV_max + 1;
perfModel->regModel.setDivIssue(n_DIV);
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
  RC_SchedulingFunctionSet,
  "remw",
  35,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIV_max;
n_DIV_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIV = n_DIV_max + 1;
perfModel->regModel.setDivIssue(n_DIV);
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
  RC_SchedulingFunctionSet,
  "divu",
  36,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIVU_max;
n_DIVU_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIVU = n_DIVU_max + 1;
perfModel->regModel.setDivIssue(n_DIVU);
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
  RC_SchedulingFunctionSet,
  "remu",
  37,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIVU_max;
n_DIVU_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIVU = n_DIVU_max + 1;
perfModel->regModel.setDivIssue(n_DIVU);
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
  RC_SchedulingFunctionSet,
  "divuw",
  38,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIVU_max;
n_DIVU_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIVU = n_DIVU_max + 1;
perfModel->regModel.setDivIssue(n_DIVU);
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
  RC_SchedulingFunctionSet,
  "remuw",
  39,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
uint64_t n_DIVU_max;
n_DIVU_max = std::max({n_ID, perfModel->regModel.getDivReady()});
n_DIVU = n_DIVU_max + 1;
perfModel->regModel.setDivIssue(n_DIVU);
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
  RC_SchedulingFunctionSet,
  "csrrw",
  40,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->regModel.setXd(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "csrrs",
  41,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->regModel.setXd(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "csrrc",
  42,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->regModel.setXd(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "csrrwi",
  43,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->regModel.setXd(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "csrrsi",
  44,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->regModel.setXd(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "csrrci",
  45,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->regModel.setXd(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sb",
  46,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sh",
  47,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sw",
  48,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sd = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "sd",
  49,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lb",
  50,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lbu",
  51,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lh",
  52,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lhu",
  53,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lw",
  54,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_ld = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "ld",
  55,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lwu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "lwu",
  56,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
// EX
uint64_t n_EX;
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
n_DCache = n_EX + perfModel->dCacheModel.getDelay();
perfModel->regModel.setXd(n_DCache);
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
// WB
uint64_t n_WB = n_LoadWB;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "beq",
  57,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "bne",
  58,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "blt",
  59,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "bge",
  60,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "bltu",
  61,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "bgeu",
  62,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "jal",
  63,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
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
  RC_SchedulingFunctionSet,
  "jalr",
  64,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
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
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
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
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
// MEM
uint64_t n_MEM;
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  RC_SchedulingFunctionSet,
  "_def",
  65,
  [](PerformanceModel* perfModel_){
  RC_PerformanceModel* perfModel = static_cast<RC_PerformanceModel*>(perfModel_);
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
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
// ICache
uint64_t n_ICache;
n_ICache = n_Enter + perfModel->iCacheModel.getDelay();
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
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


} // namespace RC