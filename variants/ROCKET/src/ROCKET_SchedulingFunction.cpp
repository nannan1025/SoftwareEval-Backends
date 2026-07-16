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
  perfModel->setInstructionInfo("add", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
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
  perfModel->setInstructionInfo("sub", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "xor",
  2,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("xor", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "or",
  3,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("or", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "and",
  4,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("and", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slt",
  5,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("slt", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sltu",
  6,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sltu", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sll",
  7,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sll", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srl",
  8,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("srl", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sra",
  9,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sra", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_addw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "addw",
  10,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("addw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_subw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "subw",
  11,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("subw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "addi",
  12,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("addi", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "xori",
  13,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("xori", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "ori",
  14,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("ori", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "andi",
  15,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("andi", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slti",
  16,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("slti", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sltiu",
  17,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sltiu", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slli",
  18,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("slli", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srli",
  19,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("srli", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srai",
  20,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("srai", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_addiw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "addiw",
  21,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("addiw", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_slliw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "slliw",
  22,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("slliw", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sraiw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sraiw",
  23,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sraiw", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_srliw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "srliw",
  24,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("srliw", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "auipc",
  25,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("auipc", false, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lui",
  26,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lui", false, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mul",
  27,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("mul", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MUL
uint64_t n_MUL;
n_MUL = n_ID + 1;
perfModel->recordSchedVar("EX_n_MUL", n_MUL);
perfModel->setRegWriteReady(n_MUL);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_MUL, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulw",
  28,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("mulw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MUL
uint64_t n_MUL;
n_MUL = n_ID + 1;
perfModel->recordSchedVar("EX_n_MUL", n_MUL);
perfModel->setRegWriteReady(n_MUL);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_MUL, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulh",
  29,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("mulh", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MUL
uint64_t n_MUL;
n_MUL = n_ID + 1;
perfModel->recordSchedVar("EX_n_MUL", n_MUL);
perfModel->setRegWriteReady(n_MUL);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_MUL, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulhu",
  30,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("mulhu", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MUL
uint64_t n_MUL;
n_MUL = n_ID + 1;
perfModel->recordSchedVar("EX_n_MUL", n_MUL);
perfModel->setRegWriteReady(n_MUL);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_MUL, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "mulhsu",
  31,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("mulhsu", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// MUL
uint64_t n_MUL;
n_MUL = n_ID + 1;
perfModel->recordSchedVar("EX_n_MUL", n_MUL);
perfModel->setRegWriteReady(n_MUL);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_MUL, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_div = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "div",
  32,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("div", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIV
uint64_t n_DIV;
uint64_t n_DIVDelay;
n_DIVDelay = perfModel->divider.getDelay();
perfModel->recordSchedVar("EX_n_DIVDelay", n_DIVDelay);
n_DIV = n_ID + n_DIVDelay;
perfModel->recordSchedVar("EX_n_DIV", n_DIV);
perfModel->setDividerDelay(n_DIVDelay > 0 ? n_DIVDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIV);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_rem = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "rem",
  33,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("rem", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIV
uint64_t n_DIV;
uint64_t n_DIVDelay;
n_DIVDelay = perfModel->divider.getDelay();
perfModel->recordSchedVar("EX_n_DIVDelay", n_DIVDelay);
n_DIV = n_ID + n_DIVDelay;
perfModel->recordSchedVar("EX_n_DIV", n_DIV);
perfModel->setDividerDelay(n_DIVDelay > 0 ? n_DIVDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIV);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_divw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "divw",
  34,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("divw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIV
uint64_t n_DIV;
uint64_t n_DIVDelay;
n_DIVDelay = perfModel->divider.getDelay();
perfModel->recordSchedVar("EX_n_DIVDelay", n_DIVDelay);
n_DIV = n_ID + n_DIVDelay;
perfModel->recordSchedVar("EX_n_DIV", n_DIV);
perfModel->setDividerDelay(n_DIVDelay > 0 ? n_DIVDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIV);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_remw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "remw",
  35,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("remw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIV
uint64_t n_DIV;
uint64_t n_DIVDelay;
n_DIVDelay = perfModel->divider.getDelay();
perfModel->recordSchedVar("EX_n_DIVDelay", n_DIVDelay);
n_DIV = n_ID + n_DIVDelay;
perfModel->recordSchedVar("EX_n_DIV", n_DIV);
perfModel->setDividerDelay(n_DIVDelay > 0 ? n_DIVDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIV);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIV, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_divu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "divu",
  36,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("divu", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIVU
uint64_t n_DIVU;
uint64_t n_DIVUDelay;
n_DIVUDelay = perfModel->divider_u.getDelay();
perfModel->recordSchedVar("EX_n_DIVUDelay", n_DIVUDelay);
n_DIVU = n_ID + n_DIVUDelay;
perfModel->recordSchedVar("EX_n_DIVU", n_DIVU);
perfModel->setDividerDelay(n_DIVUDelay > 0 ? n_DIVUDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIVU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_remu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "remu",
  37,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("remu", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIVU
uint64_t n_DIVU;
uint64_t n_DIVUDelay;
n_DIVUDelay = perfModel->divider_u.getDelay();
perfModel->recordSchedVar("EX_n_DIVUDelay", n_DIVUDelay);
n_DIVU = n_ID + n_DIVUDelay;
perfModel->recordSchedVar("EX_n_DIVU", n_DIVU);
perfModel->setDividerDelay(n_DIVUDelay > 0 ? n_DIVUDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIVU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_divuw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "divuw",
  38,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("divuw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIVU
uint64_t n_DIVU;
uint64_t n_DIVUDelay;
n_DIVUDelay = perfModel->divider_u.getDelay();
perfModel->recordSchedVar("EX_n_DIVUDelay", n_DIVUDelay);
n_DIVU = n_ID + n_DIVUDelay;
perfModel->recordSchedVar("EX_n_DIVU", n_DIVU);
perfModel->setDividerDelay(n_DIVUDelay > 0 ? n_DIVUDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIVU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_remuw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "remuw",
  39,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("remuw", true, true, true, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// DIVU
uint64_t n_DIVU;
uint64_t n_DIVUDelay;
n_DIVUDelay = perfModel->divider_u.getDelay();
perfModel->recordSchedVar("EX_n_DIVUDelay", n_DIVUDelay);
n_DIVU = n_ID + n_DIVUDelay;
perfModel->recordSchedVar("EX_n_DIVU", n_DIVU);
perfModel->setDividerDelay(n_DIVUDelay > 0 ? n_DIVUDelay - 1 : 0);
perfModel->setRegWriteReady(n_DIVU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_DIVU, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrw",
  40,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("csrrw", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->recordSchedVar("WB_n_CSR", n_CSR);
perfModel->setRegWriteReady(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrs",
  41,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("csrrs", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->recordSchedVar("WB_n_CSR", n_CSR);
perfModel->setRegWriteReady(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrc",
  42,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("csrrc", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->recordSchedVar("WB_n_CSR", n_CSR);
perfModel->setRegWriteReady(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrwi",
  43,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("csrrwi", false, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->recordSchedVar("WB_n_CSR", n_CSR);
perfModel->setRegWriteReady(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrsi",
  44,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("csrrsi", false, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->recordSchedVar("WB_n_CSR", n_CSR);
perfModel->setRegWriteReady(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "csrrci",
  45,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("csrrci", false, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// CSR
uint64_t n_CSR;
n_CSR = n_MEM + 1;
perfModel->recordSchedVar("WB_n_CSR", n_CSR);
perfModel->setRegWriteReady(n_CSR);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_CSR, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sb",
  46,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sb", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
perfModel->recordSchedVar("MEM_n_StoreCommit", n_StoreCommit);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sh",
  47,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sh", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
perfModel->recordSchedVar("MEM_n_StoreCommit", n_StoreCommit);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sw",
  48,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sw", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
perfModel->recordSchedVar("MEM_n_StoreCommit", n_StoreCommit);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_sd = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "sd",
  49,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("sd", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// StoreCommit
uint64_t n_StoreCommit;
n_StoreCommit = n_EX + 1;
perfModel->recordSchedVar("MEM_n_StoreCommit", n_StoreCommit);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, n_StoreCommit, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lb",
  50,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lb", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lbu",
  51,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lbu", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lh",
  52,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lh", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lhu",
  53,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lhu", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lw",
  54,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lw", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_ld = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "ld",
  55,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("ld", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_lwu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "lwu",
  56,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("lwu", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// DTLB
uint64_t n_DTLB;
n_DTLB = n_ID + 1;
perfModel->recordSchedVar("EX_n_DTLB", n_DTLB);
// LSUReq
uint64_t n_LSUReq;
n_LSUReq = n_ID + 1;
perfModel->recordSchedVar("EX_n_LSUReq", n_LSUReq);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, n_DTLB, n_LSUReq, perfModel->MEM});
perfModel->EX = n_EX;
// DCache
uint64_t n_DCache;
uint64_t n_DCacheDelay;
n_DCacheDelay = perfModel->dCacheModel.getDelay();
perfModel->recordSchedVar("MEM_n_DCacheDelay", n_DCacheDelay);
n_DCache = n_EX + n_DCacheDelay;
perfModel->recordSchedVar("MEM_n_DCache", n_DCache);
perfModel->setDCacheInstrumentation(n_DCacheDelay > 0 ? n_DCacheDelay - 1 : 0, perfModel->dCacheModel.getMiss());
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_DCache, perfModel->WB});
perfModel->MEM = n_MEM;
// LoadWB
uint64_t n_LoadWB;
n_LoadWB = n_MEM + 1;
perfModel->recordSchedVar("WB_n_LoadWB", n_LoadWB);
perfModel->setRegWriteReady(n_LoadWB);
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB;
n_WB = std::max({n_LoadWB, n_Reg});
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "beq",
  57,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("beq", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bne",
  58,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("bne", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "blt",
  59,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("blt", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bge",
  60,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("bge", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bltu",
  61,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("bltu", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "bgeu",
  62,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("bgeu", true, true, false, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// uA_OF_B
uint64_t n_uA_OF_B;
n_uA_OF_B = std::max({n_IF, perfModel->getRawReadyB(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_B", n_uA_OF_B);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, n_uA_OF_B, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "jal",
  63,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("jal", false, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p_j(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "jalr",
  64,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("jalr", true, false, true, true);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// BPU
uint64_t n_BPU;
n_BPU = n_Enter + 1;
perfModel->recordSchedVar("IF_n_BPU", n_BPU);
perfModel->dynBranchPredModel.setPc_p_jr(n_BPU);
perfModel->setBranchInstrumentation(true, false, 0);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, n_BPU, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// uA_OF_A
uint64_t n_uA_OF_A;
n_uA_OF_A = std::max({n_IF, perfModel->getRawReadyA(n_Decoder)});
perfModel->recordSchedVar("ID_n_uA_OF_A", n_uA_OF_A);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, n_uA_OF_A, perfModel->EX});
perfModel->ID = n_ID;
// ALU
uint64_t n_ALU;
n_ALU = n_ID + 1;
perfModel->recordSchedVar("EX_n_ALU", n_ALU);
perfModel->setRegWriteReady(n_ALU);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_ALU, perfModel->MEM});
perfModel->EX = n_EX;
// Branch
uint64_t n_Branch;
n_Branch = n_EX + 1;
perfModel->recordSchedVar("MEM_n_Branch", n_Branch);
perfModel->dynBranchPredModel.setPc_c(n_Branch);
// FlushMem
uint64_t n_FlushMem;
n_FlushMem = n_EX + 1;
perfModel->recordSchedVar("MEM_n_FlushMem", n_FlushMem);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_Branch, n_FlushMem, perfModel->WB});
perfModel->MEM = n_MEM;
// Reg
uint64_t n_Reg;
n_Reg = n_MEM + 1;
perfModel->recordSchedVar("WB_n_Reg", n_Reg);
// WB
uint64_t n_WB = n_Reg;
perfModel->WB = n_WB;

  }
);

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  ROCKET_SchedulingFunctionSet,
  "_def",
  65,
  [](PerformanceModel* perfModel_){
  ROCKET_PerformanceModel* perfModel = static_cast<ROCKET_PerformanceModel*>(perfModel_);
  perfModel->setInstructionInfo("_def", false, false, false, false);
  // Enter
uint64_t n_Enter = perfModel->IF;
perfModel->recordSchedVar("IF_n_Enter", n_Enter);
// PC_Gen
uint64_t n_PC_Gen;
n_PC_Gen = n_Enter + 1;
perfModel->recordSchedVar("IF_n_PC_Gen", n_PC_Gen);
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
uint64_t n_ext_Pc_mp;
n_ext_Pc_mp = perfModel->dynBranchPredModel.getPc_mp();
perfModel->recordSchedVar("IF_ext_Pc_mp", n_ext_Pc_mp);
n_uA_PcCorrect = std::max({n_Enter, n_ext_Pc_mp});
perfModel->recordSchedVar("IF_n_uA_PcCorrect", n_uA_PcCorrect);
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
uint64_t n_ext_Ic_out;
n_ext_Ic_out = perfModel->iCacheModel.getIc_out();
perfModel->recordSchedVar("IF_ext_Ic_out", n_ext_Ic_out);
n_uA_CacheBlock = std::max({n_Enter, n_ext_Ic_out});
perfModel->recordSchedVar("IF_n_uA_CacheBlock", n_uA_CacheBlock);
// uA_PcPredict
uint64_t n_uA_PcPredict;
uint64_t n_ext_Pc_pt;
n_ext_Pc_pt = perfModel->dynBranchPredModel.getPc_pt();
perfModel->recordSchedVar("IF_ext_Pc_pt", n_ext_Pc_pt);
n_uA_PcPredict = std::max({n_Enter, n_ext_Pc_pt});
perfModel->recordSchedVar("IF_n_uA_PcPredict", n_uA_PcPredict);
// ITLB
uint64_t n_ITLB;
n_ITLB = n_Enter + 1;
perfModel->recordSchedVar("IF_n_ITLB", n_ITLB);
// ICache
uint64_t n_ICache;
uint64_t n_ICacheDelay;
n_ICacheDelay = perfModel->iCacheModel.getDelay();
perfModel->recordSchedVar("IF_n_ICacheDelay", n_ICacheDelay);
n_ICache = n_Enter + n_ICacheDelay;
perfModel->recordSchedVar("IF_n_ICache", n_ICache);
perfModel->setICacheInstrumentation(n_ICacheDelay > 0 ? n_ICacheDelay - 1 : 0, perfModel->iCacheModel.getMiss());
perfModel->iCacheModel.setIc_in(n_ICache);
// IF
uint64_t n_IF;
perfModel->recordSchedVar("IF_prev_ID", perfModel->ID);
n_IF = std::max({n_PC_Gen, n_uA_PcCorrect, n_uA_CacheBlock, n_uA_PcPredict, n_ITLB, n_ICache, perfModel->ID});
perfModel->IF = n_IF;
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IF + 1;
perfModel->recordSchedVar("ID_n_Decoder", n_Decoder);
// ID
uint64_t n_ID;
perfModel->recordSchedVar("ID_prev_EX", perfModel->EX);
n_ID = std::max({n_Decoder, perfModel->EX});
perfModel->ID = n_ID;
// EXPass
uint64_t n_EXPass;
n_EXPass = n_ID + 1;
perfModel->recordSchedVar("EX_n_EXPass", n_EXPass);
// EX
uint64_t n_EX;
perfModel->recordSchedVar("EX_prev_MEM", perfModel->MEM);
n_EX = std::max({n_EXPass, perfModel->MEM});
perfModel->EX = n_EX;
// MEMPass
uint64_t n_MEMPass;
n_MEMPass = n_EX + 1;
perfModel->recordSchedVar("MEM_n_MEMPass", n_MEMPass);
// MEM
uint64_t n_MEM;
perfModel->recordSchedVar("MEM_prev_WB", perfModel->WB);
n_MEM = std::max({n_MEMPass, perfModel->WB});
perfModel->MEM = n_MEM;
// WBPass
uint64_t n_WBPass;
n_WBPass = n_MEM + 1;
perfModel->recordSchedVar("WB_n_WBPass", n_WBPass);
// WB
uint64_t n_WB = n_WBPass;
perfModel->WB = n_WB;

  }
);


} // namespace ROCKET