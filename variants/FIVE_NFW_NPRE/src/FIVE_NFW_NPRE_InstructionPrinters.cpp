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

#include "FIVE_NFW_NPRE_Printer.h"

#include <sstream>
#include <string>
#include <iomanip>

InstructionPrinterSet *FIVE_NFW_NPRE_InstrPrinterSet = new InstructionPrinterSet("FIVE_NFW_NPRE_InstrPrinterSet");

static InstructionPrinter *instrPrinter__def = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "_def",
  0,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_auipc = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "auipc",
  1,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lui = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "lui",
  2,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrsi = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "csrrsi",
  3,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrci = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "csrrci",
  4,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addi = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "addi",
  5,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xori = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "xori",
  6,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_ori = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "ori",
  7,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_andi = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "andi",
  8,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slti = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "slti",
  9,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltiu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sltiu",
  10,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slli = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "slli",
  11,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srli = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "srli",
  12,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srai = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "srai",
  13,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrw = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "csrrw",
  14,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrs = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "csrrs",
  15,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrc = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "csrrc",
  16,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_add = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "add",
  17,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sub = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sub",
  18,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xor = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "xor",
  19,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_or = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "or",
  20,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_and = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "and",
  21,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slt = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "slt",
  22,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sltu",
  23,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sll = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sll",
  24,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srl = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "srl",
  25,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sra = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sra",
  26,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mul = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "mul",
  27,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulh = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "mulh",
  28,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "mulhu",
  29,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhsu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "mulhsu",
  30,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lw = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "lw",
  31,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lh = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "lh",
  32,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lhu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "lhu",
  33,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lb = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "lb",
  34,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lbu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "lbu",
  35,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sw = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sw",
  36,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sh = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sh",
  37,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sb = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "sb",
  38,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_beq = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "beq",
  39,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bne = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "bne",
  40,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_blt = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "blt",
  41,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bge = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "bge",
  42,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bltu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "bltu",
  43,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bgeu = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "bgeu",
  44,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jal = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "jal",
  45,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jalr = new InstructionPrinter(
  FIVE_NFW_NPRE_InstrPrinterSet,
  "jalr",
  46,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_NFW_NPRE_Printer* printer = static_cast<FIVE_NFW_NPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
