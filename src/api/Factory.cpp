
/*
 * Copyright 2022 Chair of EDA, Technical University of Munich
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

#include "Factory.h"

#include "Channel.h"
#include "Backend.h"

#include "PerformanceEstimator.h"
#include "PerformanceModel.h"
#include "TracePrinter.h"
#include "Printer.h"

#include "SIX_NFW_SPRE_PerformanceModel.h"
#include "SIX_NFW_SPRE_Channel.h"
#include "SIX_NFW_SPRE_Printer.h"

#include "SHAKTI_C_Channel.h"
#include "SHAKTI_C_Printer.h"
#include "SHAKTI_C_PerformanceModel.h"

#include "ROCKET_PerformanceModel.h"
#include "ROCKET_Printer.h"
#include "ROCKET_Channel.h"

#include "CV32E40P_CORE_Printer.h"
#include "CV32E40P_CORE_PerformanceModel.h"
#include "CV32E40P_CORE_Channel.h"

#include "CVA6_Printer.h"
#include "CVA6_PerformanceModel.h"
#include "CVA6_Channel.h"

#include "AssemblyTrace_Channel.h"
#include "AssemblyTrace_Printer.h"

#include "CVA6_QWEN_1_Printer.h"
#include "CVA6_QWEN_1_PerformanceModel.h"
#include "CVA6_QWEN_1_Channel.h"

#include "LAMP_PerformanceModel.h"
#include "LAMP_Channel.h"
#include "LAMP_Printer.h"

#include "FOUR_NFW_NOPRE_Channel.h"
#include "FOUR_NFW_NOPRE_Printer.h"
#include "FOUR_NFW_NOPRE_PerformanceModel.h"

#include "CV32E40P_LLM_PerformanceModel.h"
#include "CV32E40P_LLM_Printer.h"
#include "CV32E40P_LLM_Channel.h"

#include "FIVE_NFW_NPRE_PerformanceModel.h"
#include "FIVE_NFW_NPRE_Printer.h"
#include "FIVE_NFW_NPRE_Channel.h"

#include "FIVE_FW_DYPRE_PerformanceModel.h"
#include "FIVE_FW_DYPRE_Printer.h"
#include "FIVE_FW_DYPRE_Channel.h"

#include "RC_Channel.h"
#include "RC_Printer.h"
#include "RC_PerformanceModel.h"

#include "CV32E40P_QWEN_1_Channel.h"
#include "CV32E40P_QWEN_1_PerformanceModel.h"
#include "CV32E40P_QWEN_1_Printer.h"

#include "CVA62_PerformanceModel.h"
#include "CVA62_Printer.h"
#include "CVA62_Channel.h"

#include "InstructionTrace_RV64_Channel.h"
#include "InstructionTrace_RV64_Printer.h"

#include "CV32E40P_Channel.h"
#include "CV32E40P_PerformanceModel.h"
#include "CV32E40P_Printer.h"


namespace SwEvalBackends
{

int Factory::getVariantHandle(std::string varName_)
{
    	if(varName_ == "SIX_NFW_SPRE"){ return SIX_NFW_SPRE; }
	if(varName_ == "SHAKTI_C"){ return SHAKTI_C; }
	if(varName_ == "ROCKET"){ return ROCKET; }
	if(varName_ == "CV32E40P_CORE"){ return CV32E40P_CORE; }
	if(varName_ == "CVA6"){ return CVA6; }
	if(varName_ == "AssemblyTrace"){ return AssemblyTrace; }
	if(varName_ == "CVA6_QWEN_1"){ return CVA6_QWEN_1; }
	if(varName_ == "LAMP"){ return LAMP; }
	if(varName_ == "FOUR_NFW_NOPRE"){ return FOUR_NFW_NOPRE; }
	if(varName_ == "CV32E40P_LLM"){ return CV32E40P_LLM; }
	if(varName_ == "FIVE_NFW_NPRE"){ return FIVE_NFW_NPRE; }
	if(varName_ == "FIVE_FW_DYPRE"){ return FIVE_FW_DYPRE; }
	if(varName_ == "RC"){ return RC; }
	if(varName_ == "CV32E40P_QWEN_1"){ return CV32E40P_QWEN_1; }
	if(varName_ == "CVA62"){ return CVA62; }
	if(varName_ == "InstructionTrace_RV64"){ return InstructionTrace_RV64; }
	if(varName_ == "CV32E40P"){ return CV32E40P; }

    return -1;
}

Channel* Factory::getChannel(int var_)
{
  switch((var_t)var_)
  {
    	case SIX_NFW_SPRE: return new SIX_NFW_SPRE_Channel();
	case SHAKTI_C: return new SHAKTI_C_Channel();
	case ROCKET: return new ROCKET_Channel();
	case CV32E40P_CORE: return new CV32E40P_CORE_Channel();
	case CVA6: return new CVA6_Channel();
	case AssemblyTrace: return new AssemblyTrace_Channel();
	case CVA6_QWEN_1: return new CVA6_QWEN_1_Channel();
	case LAMP: return new LAMP_Channel();
	case FOUR_NFW_NOPRE: return new FOUR_NFW_NOPRE_Channel();
	case CV32E40P_LLM: return new CV32E40P_LLM_Channel();
	case FIVE_NFW_NPRE: return new FIVE_NFW_NPRE_Channel();
	case FIVE_FW_DYPRE: return new FIVE_FW_DYPRE_Channel();
	case RC: return new RC_Channel();
	case CV32E40P_QWEN_1: return new CV32E40P_QWEN_1_Channel();
	case CVA62: return new CVA62_Channel();
	case InstructionTrace_RV64: return new InstructionTrace_RV64_Channel();
	case CV32E40P: return new CV32E40P_Channel();

    default: return nullptr;
  }
}

Backend* Factory::getPerformanceEstimator(int var_)
{
  // Get performance model
  PerformanceModel* perfModel;
  switch((var_t)var_)
  {
    	case SIX_NFW_SPRE:
		perfModel = new SIX_NFW_SPRE::SIX_NFW_SPRE_PerformanceModel();
		break;
	case SHAKTI_C:
		perfModel = new SHAKTI_C::SHAKTI_C_PerformanceModel();
		break;
	case ROCKET:
		perfModel = new ROCKET::ROCKET_PerformanceModel();
		break;
	case CV32E40P_CORE:
		perfModel = new CV32E40P_CORE::CV32E40P_CORE_PerformanceModel();
		break;
	case CVA6:
		perfModel = new CVA6::CVA6_PerformanceModel();
		break;
	case CVA6_QWEN_1:
		perfModel = new CVA6_QWEN_1::CVA6_QWEN_1_PerformanceModel();
		break;
	case LAMP:
		perfModel = new LAMP::LAMP_PerformanceModel();
		break;
	case FOUR_NFW_NOPRE:
		perfModel = new FOUR_NFW_NOPRE::FOUR_NFW_NOPRE_PerformanceModel();
		break;
	case CV32E40P_LLM:
		perfModel = new CV32E40P_LLM::CV32E40P_LLM_PerformanceModel();
		break;
	case FIVE_NFW_NPRE:
		perfModel = new FIVE_NFW_NPRE::FIVE_NFW_NPRE_PerformanceModel();
		break;
	case FIVE_FW_DYPRE:
		perfModel = new FIVE_FW_DYPRE::FIVE_FW_DYPRE_PerformanceModel();
		break;
	case RC:
		perfModel = new RC::RC_PerformanceModel();
		break;
	case CV32E40P_QWEN_1:
		perfModel = new CV32E40P_QWEN_1::CV32E40P_QWEN_1_PerformanceModel();
		break;
	case CVA62:
		perfModel = new CVA62::CVA62_PerformanceModel();
		break;
	case CV32E40P:
		perfModel = new CV32E40P::CV32E40P_PerformanceModel();
		break;

    default: perfModel = nullptr;
  }

  // Create PerformanceEstimator
  if(perfModel != nullptr)
  {
    return new PerformanceEstimator(perfModel);
  }
  else
  {
    return nullptr;
  }
}

Backend* Factory::getTracePrinter(int var_)
{
  // Get variant specific printer
  Printer* printer;
  switch((var_t)var_)
  {
    	case SIX_NFW_SPRE:
		printer = new SIX_NFW_SPRE_Printer();
		break;
	case SHAKTI_C:
		printer = new SHAKTI_C_Printer();
		break;
	case ROCKET:
		printer = new ROCKET_Printer();
		break;
	case CV32E40P_CORE:
		printer = new CV32E40P_CORE_Printer();
		break;
	case CVA6:
		printer = new CVA6_Printer();
		break;
	case AssemblyTrace:
		printer = new AssemblyTrace_Printer();
		break;
	case CVA6_QWEN_1:
		printer = new CVA6_QWEN_1_Printer();
		break;
	case LAMP:
		printer = new LAMP_Printer();
		break;
	case FOUR_NFW_NOPRE:
		printer = new FOUR_NFW_NOPRE_Printer();
		break;
	case CV32E40P_LLM:
		printer = new CV32E40P_LLM_Printer();
		break;
	case FIVE_NFW_NPRE:
		printer = new FIVE_NFW_NPRE_Printer();
		break;
	case FIVE_FW_DYPRE:
		printer = new FIVE_FW_DYPRE_Printer();
		break;
	case RC:
		printer = new RC_Printer();
		break;
	case CV32E40P_QWEN_1:
		printer = new CV32E40P_QWEN_1_Printer();
		break;
	case CVA62:
		printer = new CVA62_Printer();
		break;
	case InstructionTrace_RV64:
		printer = new InstructionTrace_RV64_Printer();
		break;
	case CV32E40P:
		printer = new CV32E40P_Printer();
		break;

    default: printer = nullptr;
  }

  // Create TracePrinter
  if(printer != nullptr)
  {
    return new TracePrinter(printer);
  }
  else
  {
    return nullptr;
  }
}

} // namespace SwEvalBackends
