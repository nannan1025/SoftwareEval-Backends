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


#include "Printer.h"
#include "Channel.h"

#include "SIX_NFW_SPRE_Printer.h"

#include <sstream>
#include <string>
#include <iomanip>

InstructionPrinterSet *SIX_NFW_SPRE_InstrPrinterSet = new InstructionPrinterSet("SIX_NFW_SPRE_InstrPrinterSet");

static InstructionPrinter *instrPrinter__def = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "_def",
  0,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_auipc = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "auipc",
  1,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lui = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lui",
  2,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addi = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "addi",
  3,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xori = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "xori",
  4,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_ori = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "ori",
  5,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_andi = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "andi",
  6,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slti = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "slti",
  7,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltiu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sltiu",
  8,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slli = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "slli",
  9,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srli = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "srli",
  10,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srai = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "srai",
  11,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addiw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "addiw",
  12,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slliw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "slliw",
  13,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srliw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "srliw",
  14,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sraiw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sraiw",
  15,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_add = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "add",
  16,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sub = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sub",
  17,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xor = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "xor",
  18,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_or = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "or",
  19,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_and = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "and",
  20,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slt = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "slt",
  21,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sltu",
  22,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sll = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sll",
  23,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srl = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "srl",
  24,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sra = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sra",
  25,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "addw",
  26,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_subw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "subw",
  27,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sllw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sllw",
  28,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srlw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "srlw",
  29,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sraw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sraw",
  30,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mul = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "mul",
  31,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "mulw",
  32,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulh = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "mulh",
  33,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "mulhu",
  34,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhsu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "mulhsu",
  35,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "csrrw",
  36,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrs = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "csrrs",
  37,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrc = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "csrrc",
  38,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrwi = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "csrrwi",
  39,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrsi = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "csrrsi",
  40,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrci = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "csrrci",
  41,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lb = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lb",
  42,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lbu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lbu",
  43,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lh = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lh",
  44,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lhu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lhu",
  45,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lw",
  46,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lwu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "lwu",
  47,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_ld = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "ld",
  48,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sb = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sb",
  49,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sh = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sh",
  50,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sw = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sw",
  51,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sd = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "sd",
  52,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_beq = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "beq",
  53,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bne = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "bne",
  54,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_blt = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "blt",
  55,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bge = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "bge",
  56,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bltu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "bltu",
  57,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bgeu = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "bgeu",
  58,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jal = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "jal",
  59,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jalr = new InstructionPrinter(
  SIX_NFW_SPRE_InstrPrinterSet,
  "jalr",
  60,
  [](Printer* printer_){
    std::stringstream ret_strs;
    SIX_NFW_SPRE_Printer* printer = static_cast<SIX_NFW_SPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
