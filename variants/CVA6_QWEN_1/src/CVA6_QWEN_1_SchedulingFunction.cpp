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

#include "CVA6_QWEN_1_PerformanceModel.h"

namespace CVA6_QWEN_1{

SchedulingFunctionSet* CVA6_QWEN_1_SchedulingFunctionSet = new SchedulingFunctionSet("CVA6_QWEN_1_SchedulingFunctionSet");

static SchedulingFunction *schedulingFunction__def = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "_def",
  0,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_auipc = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "auipc",
  1,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lui = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lui",
  2,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_csrrwi = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "csrrwi",
  3,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_csrrsi = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "csrrsi",
  4,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_csrrci = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "csrrci",
  5,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_addi = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "addi",
  6,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_xori = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "xori",
  7,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_ori = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "ori",
  8,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_andi = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "andi",
  9,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_slti = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "slti",
  10,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sltiu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sltiu",
  11,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_slli = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "slli",
  12,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_srli = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "srli",
  13,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_srai = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "srai",
  14,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_csrrw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "csrrw",
  15,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_csrrs = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "csrrs",
  16,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_csrrc = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "csrrc",
  17,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_addiw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "addiw",
  18,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_slliw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "slliw",
  19,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sraiw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sraiw",
  20,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_srliw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "srliw",
  21,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_add = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "add",
  22,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sub = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sub",
  23,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_xor = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "xor",
  24,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_or = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "or",
  25,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_and = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "and",
  26,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_slt = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "slt",
  27,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sltu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sltu",
  28,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sll = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sll",
  29,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_srl = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "srl",
  30,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sra = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sra",
  31,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_subw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "subw",
  32,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_addw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "addw",
  33,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_beq = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "beq",
  34,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_bne = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "bne",
  35,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_blt = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "blt",
  36,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_bge = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "bge",
  37,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_bltu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "bltu",
  38,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_bgeu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "bgeu",
  39,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_jal = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "jal",
  40,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p_j(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_jalr = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "jalr",
  41,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
perfModel->dynBranchPredModel.setPc_p_jr(n_Realigner);
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_ALU_substage, perfModel->EX_MUL_substage_1, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// ALU
uint64_t n_ALU;
n_ALU = n_Issue_stage + 1;
perfModel->regModel.setXd(n_ALU);
perfModel->dynBranchPredModel.setPc_c(n_ALU);
// EX_ALU_substage
uint64_t n_EX_ALU_substage = n_ALU;
perfModel->EX_ALU_substage = n_EX_ALU_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_ALU_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_mul = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "mul",
  42,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_MUL_substage_0, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// MUL_I
uint64_t n_MUL_I;
n_MUL_I = n_Issue_stage + 1;
// EX_MUL_substage_0
uint64_t n_EX_MUL_substage_0;
n_EX_MUL_substage_0 = std::max({n_MUL_I, perfModel->EX_MUL_substage_1});
perfModel->EX_MUL_substage_0 = n_EX_MUL_substage_0;
// MUL_O
uint64_t n_MUL_O;
n_MUL_O = n_EX_MUL_substage_0 + 1;
perfModel->regModel.setXd(n_MUL_O);
// EX_MUL_substage_1
uint64_t n_EX_MUL_substage_1 = n_MUL_O;
perfModel->EX_MUL_substage_1 = n_EX_MUL_substage_1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_MUL_substage_1, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_mulh = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "mulh",
  43,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_MUL_substage_0, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// MUL_I
uint64_t n_MUL_I;
n_MUL_I = n_Issue_stage + 1;
// EX_MUL_substage_0
uint64_t n_EX_MUL_substage_0;
n_EX_MUL_substage_0 = std::max({n_MUL_I, perfModel->EX_MUL_substage_1});
perfModel->EX_MUL_substage_0 = n_EX_MUL_substage_0;
// MUL_O
uint64_t n_MUL_O;
n_MUL_O = n_EX_MUL_substage_0 + 1;
perfModel->regModel.setXd(n_MUL_O);
// EX_MUL_substage_1
uint64_t n_EX_MUL_substage_1 = n_MUL_O;
perfModel->EX_MUL_substage_1 = n_EX_MUL_substage_1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_MUL_substage_1, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_mulhu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "mulhu",
  44,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_MUL_substage_0, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// MUL_I
uint64_t n_MUL_I;
n_MUL_I = n_Issue_stage + 1;
// EX_MUL_substage_0
uint64_t n_EX_MUL_substage_0;
n_EX_MUL_substage_0 = std::max({n_MUL_I, perfModel->EX_MUL_substage_1});
perfModel->EX_MUL_substage_0 = n_EX_MUL_substage_0;
// MUL_O
uint64_t n_MUL_O;
n_MUL_O = n_EX_MUL_substage_0 + 1;
perfModel->regModel.setXd(n_MUL_O);
// EX_MUL_substage_1
uint64_t n_EX_MUL_substage_1 = n_MUL_O;
perfModel->EX_MUL_substage_1 = n_EX_MUL_substage_1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_MUL_substage_1, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_mulhsu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "mulhsu",
  45,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_MUL_substage_0, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// MUL_I
uint64_t n_MUL_I;
n_MUL_I = n_Issue_stage + 1;
// EX_MUL_substage_0
uint64_t n_EX_MUL_substage_0;
n_EX_MUL_substage_0 = std::max({n_MUL_I, perfModel->EX_MUL_substage_1});
perfModel->EX_MUL_substage_0 = n_EX_MUL_substage_0;
// MUL_O
uint64_t n_MUL_O;
n_MUL_O = n_EX_MUL_substage_0 + 1;
perfModel->regModel.setXd(n_MUL_O);
// EX_MUL_substage_1
uint64_t n_EX_MUL_substage_1 = n_MUL_O;
perfModel->EX_MUL_substage_1 = n_EX_MUL_substage_1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_MUL_substage_1, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_mulw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "mulw",
  46,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_MUL_substage_0, perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// MUL_I
uint64_t n_MUL_I;
n_MUL_I = n_Issue_stage + 1;
// EX_MUL_substage_0
uint64_t n_EX_MUL_substage_0;
n_EX_MUL_substage_0 = std::max({n_MUL_I, perfModel->EX_MUL_substage_1});
perfModel->EX_MUL_substage_0 = n_EX_MUL_substage_0;
// MUL_O
uint64_t n_MUL_O;
n_MUL_O = n_EX_MUL_substage_0 + 1;
perfModel->regModel.setXd(n_MUL_O);
// EX_MUL_substage_1
uint64_t n_EX_MUL_substage_1 = n_MUL_O;
perfModel->EX_MUL_substage_1 = n_EX_MUL_substage_1;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_MUL_substage_1, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_div = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "div",
  47,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIV
uint64_t n_DIV;
n_DIV = n_Issue_stage + perfModel->divider.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIV;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_rem = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "rem",
  48,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIV
uint64_t n_DIV;
n_DIV = n_Issue_stage + perfModel->divider.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIV;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_divw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "divw",
  49,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIV
uint64_t n_DIV;
n_DIV = n_Issue_stage + perfModel->divider.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIV;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_remw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "remw",
  50,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIV
uint64_t n_DIV;
n_DIV = n_Issue_stage + perfModel->divider.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIV;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_divu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "divu",
  51,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIVU
uint64_t n_DIVU;
n_DIVU = n_Issue_stage + perfModel->divider_u.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIVU;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_remu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "remu",
  52,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIVU
uint64_t n_DIVU;
n_DIVU = n_Issue_stage + perfModel->divider_u.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIVU;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_divuw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "divuw",
  53,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIVU
uint64_t n_DIVU;
n_DIVU = n_Issue_stage + perfModel->divider_u.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIVU;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_remuw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "remuw",
  54,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_DIV_substage});
perfModel->Issue_stage = n_Issue_stage;
// DIVU
uint64_t n_DIVU;
n_DIVU = n_Issue_stage + perfModel->divider_u.getDelay();
// EX_DIV_substage
uint64_t n_EX_DIV_substage = n_DIVU;
perfModel->EX_DIV_substage = n_EX_DIV_substage;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_DIV_substage, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lw",
  55,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lh = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lh",
  56,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lhu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lhu",
  57,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lb = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lb",
  58,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lbu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lbu",
  59,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_ld = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "ld",
  60,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_lwu = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "lwu",
  61,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_Clobber
uint64_t n_uA_Clobber;
n_uA_Clobber = std::max({n_ID_stage, perfModel->clobberModel.getCb_out()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_Clobber, perfModel->EX_stage.get(8), perfModel->EX_substage_lCtrl});
perfModel->Issue_stage = n_Issue_stage;
// LCtrl
uint64_t n_LCtrl;
n_LCtrl = n_Issue_stage + 1;
// EX_substage_lCtrl
uint64_t n_EX_substage_lCtrl;
n_EX_substage_lCtrl = std::max({n_LCtrl, perfModel->EX_substage_dCache});
perfModel->EX_substage_lCtrl = n_EX_substage_lCtrl;
// DCache
uint64_t n_DCache;
n_DCache = n_EX_substage_lCtrl + perfModel->dCacheModel.getDelay();
// EX_substage_dCache
uint64_t n_EX_substage_dCache;
n_EX_substage_dCache = std::max({n_DCache, perfModel->EX_substage_lUnit});
perfModel->EX_substage_dCache = n_EX_substage_dCache;
// LUnit
uint64_t n_LUnit;
n_LUnit = n_EX_substage_dCache + 1;
perfModel->regModel.setXd(n_LUnit);
// EX_substage_lUnit
uint64_t n_EX_substage_lUnit = n_LUnit;
perfModel->EX_substage_lUnit = n_EX_substage_lUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_lUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
perfModel->clobberModel.setCb_in(n_Commit);
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sb = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sb",
  62,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_substage_sCtrl});
perfModel->Issue_stage = n_Issue_stage;
// SCtrl
uint64_t n_SCtrl;
n_SCtrl = n_Issue_stage + 1;
// EX_substage_sCtrl
uint64_t n_EX_substage_sCtrl;
n_EX_substage_sCtrl = std::max({n_SCtrl, perfModel->EX_substage_sUnit});
perfModel->EX_substage_sCtrl = n_EX_substage_sCtrl;
// SUnit
uint64_t n_SUnit;
n_SUnit = n_EX_substage_sCtrl + 1;
// EX_substage_sUnit
uint64_t n_EX_substage_sUnit = n_SUnit;
perfModel->EX_substage_sUnit = n_EX_substage_sUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_sUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sh = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sh",
  63,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_substage_sCtrl});
perfModel->Issue_stage = n_Issue_stage;
// SCtrl
uint64_t n_SCtrl;
n_SCtrl = n_Issue_stage + 1;
// EX_substage_sCtrl
uint64_t n_EX_substage_sCtrl;
n_EX_substage_sCtrl = std::max({n_SCtrl, perfModel->EX_substage_sUnit});
perfModel->EX_substage_sCtrl = n_EX_substage_sCtrl;
// SUnit
uint64_t n_SUnit;
n_SUnit = n_EX_substage_sCtrl + 1;
// EX_substage_sUnit
uint64_t n_EX_substage_sUnit = n_SUnit;
perfModel->EX_substage_sUnit = n_EX_substage_sUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_sUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sw = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sw",
  64,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_substage_sCtrl});
perfModel->Issue_stage = n_Issue_stage;
// SCtrl
uint64_t n_SCtrl;
n_SCtrl = n_Issue_stage + 1;
// EX_substage_sCtrl
uint64_t n_EX_substage_sCtrl;
n_EX_substage_sCtrl = std::max({n_SCtrl, perfModel->EX_substage_sUnit});
perfModel->EX_substage_sCtrl = n_EX_substage_sCtrl;
// SUnit
uint64_t n_SUnit;
n_SUnit = n_EX_substage_sCtrl + 1;
// EX_substage_sUnit
uint64_t n_EX_substage_sUnit = n_SUnit;
perfModel->EX_substage_sUnit = n_EX_substage_sUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_sUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);

static SchedulingFunction *schedulingFunction_sd = new SchedulingFunction(
  CVA6_QWEN_1_SchedulingFunctionSet,
  "sd",
  65,
  [](PerformanceModel* perfModel_){
  CVA6_QWEN_1_PerformanceModel* perfModel = static_cast<CVA6_QWEN_1_PerformanceModel*>(perfModel_);
  // Enter
uint64_t n_Enter = perfModel->PC_stage;
// PCGen
uint64_t n_PCGen;
n_PCGen = n_Enter + 1;
// PC_stage
uint64_t n_PC_stage;
n_PC_stage = std::max({n_PCGen, perfModel->IF_stage.get(3), perfModel->IF_substage_0});
perfModel->PC_stage = n_PC_stage;
// Instruction_Fetch
uint64_t n_Instruction_Fetch;
n_Instruction_Fetch = n_PC_stage + 1;
// uA_PcCorrect
uint64_t n_uA_PcCorrect;
n_uA_PcCorrect = std::max({n_PC_stage, perfModel->dynBranchPredModel.getPc_mp()});
// IF_substage_0
uint64_t n_IF_substage_0;
n_IF_substage_0 = std::max({n_Instruction_Fetch, n_uA_PcCorrect, perfModel->IF_substage_1});
perfModel->IF_substage_0 = n_IF_substage_0;
// Fetch_FIFO
uint64_t n_Fetch_FIFO;
n_Fetch_FIFO = n_IF_substage_0 + 1;
// uA_CacheBlock
uint64_t n_uA_CacheBlock;
n_uA_CacheBlock = std::max({n_IF_substage_0, perfModel->iCacheModel.getIc_out()});
// IF_substage_1
uint64_t n_IF_substage_1;
n_IF_substage_1 = std::max({n_Fetch_FIFO, n_uA_CacheBlock, perfModel->IF_substage_2});
perfModel->IF_substage_1 = n_IF_substage_1;
// Realigner
uint64_t n_Realigner;
n_Realigner = n_IF_substage_1 + 1;
// IF_stage
uint64_t n_IF_stage;
n_IF_stage = std::max({n_Realigner, perfModel->IF_stage.get(1), perfModel->IQ_stage.get(7)});
perfModel->IF_stage.set(n_IF_stage);
perfModel->IF_substage_2 = n_IF_stage;
// Instr_Queue
uint64_t n_Instr_Queue;
n_Instr_Queue = n_IF_stage + 1;
// IQ_stage
uint64_t n_IQ_stage;
n_IQ_stage = std::max({n_Instr_Queue, perfModel->IQ_stage.get(1), perfModel->ID_stage});
perfModel->IQ_stage.set(n_IQ_stage);
// Decoder
uint64_t n_Decoder;
n_Decoder = n_IQ_stage + 1;
// ID_stage
uint64_t n_ID_stage;
n_ID_stage = std::max({n_Decoder, perfModel->Issue_stage});
perfModel->ID_stage = n_ID_stage;
// Issue
uint64_t n_Issue = n_ID_stage;
// Scoreboard
uint64_t n_Scoreboard;
n_Scoreboard = n_ID_stage + 1;
// uA_RegRead_A
uint64_t n_uA_RegRead_A;
n_uA_RegRead_A = std::max({n_ID_stage, perfModel->regModel.getXa()});
// uA_RegRead_B
uint64_t n_uA_RegRead_B;
n_uA_RegRead_B = std::max({n_ID_stage, perfModel->regModel.getXb()});
// Issue_stage
uint64_t n_Issue_stage;
n_Issue_stage = std::max({n_Issue, n_Scoreboard, n_uA_RegRead_A, n_uA_RegRead_B, perfModel->EX_stage.get(8), perfModel->EX_substage_sCtrl});
perfModel->Issue_stage = n_Issue_stage;
// SCtrl
uint64_t n_SCtrl;
n_SCtrl = n_Issue_stage + 1;
// EX_substage_sCtrl
uint64_t n_EX_substage_sCtrl;
n_EX_substage_sCtrl = std::max({n_SCtrl, perfModel->EX_substage_sUnit});
perfModel->EX_substage_sCtrl = n_EX_substage_sCtrl;
// SUnit
uint64_t n_SUnit;
n_SUnit = n_EX_substage_sCtrl + 1;
// EX_substage_sUnit
uint64_t n_EX_substage_sUnit = n_SUnit;
perfModel->EX_substage_sUnit = n_EX_substage_sUnit;
// EX_stage
uint64_t n_EX_stage;
n_EX_stage = std::max({n_EX_substage_sUnit, perfModel->EX_stage.get(1), perfModel->COM_stage.get(2)});
perfModel->EX_stage.set(n_EX_stage);
// Commit
uint64_t n_Commit;
n_Commit = n_EX_stage + 1;
// COM_stage
uint64_t n_COM_stage;
n_COM_stage = std::max({n_Commit, perfModel->COM_stage.get(1)});
perfModel->COM_stage.set(n_COM_stage);

  }
);


} // namespace CVA6_QWEN_1