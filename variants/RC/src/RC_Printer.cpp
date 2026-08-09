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

/********************* AUTO GENERATE FILE (create by M2-ISA-R::Trace-Generator) *********************/


#include "RC_Printer.h"

#include "Printer.h"

#include "RC_Channel.h"

#include <iostream>
#include <iomanip>

extern InstructionPrinterSet* RC_InstrPrinterSet;

RC_Printer::RC_Printer(): Printer("RC_Printer", RC_InstrPrinterSet)
{}

void RC_Printer::connectChannel(Channel* ch_)
{
  RC_Channel* channel = static_cast<RC_Channel*>(ch_);
  
  pc_ptr = channel->pc;
  brTarget_ptr = channel->brTarget;
  rs1_ptr = channel->rs1;
  rd_ptr = channel->rd;
  imm_ptr = channel->imm;
  rs2_ptr = channel->rs2;
  addr_ptr = channel->addr;
}

std::string RC_Printer::getPrintHeader(void)
{
  std::stringstream caption_strs;	
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "pc" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "brTarget" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rs1" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rd" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "imm" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "rs2" << " | ";
  caption_strs << std::setfill(' ') << std::setw(18) << std::left << "addr" << " | ";

  return caption_strs.str();
}