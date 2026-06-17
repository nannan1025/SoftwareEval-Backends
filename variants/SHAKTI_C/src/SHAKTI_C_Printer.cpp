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

/********************* AUTO GENERATE FILE (create by M2-ISA-R::Trace-Generator) *********************/


#include "SHAKTI_C_Printer.h"

#include "Printer.h"

#include "SHAKTI_C_Channel.h"

#include <iostream>
#include <iomanip>

extern InstructionPrinterSet* SHAKTI_C_InstrPrinterSet;

SHAKTI_C_Printer::SHAKTI_C_Printer(): Printer("SHAKTI_C_Printer", SHAKTI_C_InstrPrinterSet)
{}

void SHAKTI_C_Printer::connectChannel(Channel* ch_)
{
  SHAKTI_C_Channel* channel = static_cast<SHAKTI_C_Channel*>(ch_);
  
  pc_ptr = channel->pc;
  brTarget_ptr = channel->brTarget;
  rs1_ptr = channel->rs1;
  rs2_ptr = channel->rs2;
  rd_ptr = channel->rd;
  rs2_data_ptr = channel->rs2_data;
}

std::string SHAKTI_C_Printer::getPrintHeader(void)
{
  std::stringstream caption_strs;	
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "pc" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "brTarget" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rs1" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rs2" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rd" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rs2_data" << " | ";

  return caption_strs.str();
}