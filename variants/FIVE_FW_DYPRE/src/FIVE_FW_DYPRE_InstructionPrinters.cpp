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

#include "FIVE_FW_DYPRE_Printer.h"

#include <sstream>
#include <string>
#include <iomanip>

InstructionPrinterSet *FIVE_FW_DYPRE_InstrPrinterSet = new InstructionPrinterSet("FIVE_FW_DYPRE_InstrPrinterSet");

static InstructionPrinter *instrPrinter__def = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "_def",
  0,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_auipc = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "auipc",
  1,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lui = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "lui",
  2,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrsi = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "csrrsi",
  3,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrci = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "csrrci",
  4,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_addi = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "addi",
  5,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xori = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "xori",
  6,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_ori = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "ori",
  7,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_andi = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "andi",
  8,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slti = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "slti",
  9,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltiu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sltiu",
  10,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slli = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "slli",
  11,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srli = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "srli",
  12,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srai = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "srai",
  13,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrw = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "csrrw",
  14,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrs = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "csrrs",
  15,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_csrrc = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "csrrc",
  16,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_add = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "add",
  17,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sub = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sub",
  18,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_xor = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "xor",
  19,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_or = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "or",
  20,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_and = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "and",
  21,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_slt = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "slt",
  22,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sltu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sltu",
  23,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sll = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sll",
  24,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_srl = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "srl",
  25,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sra = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sra",
  26,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_beq = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "beq",
  27,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bne = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "bne",
  28,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_blt = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "blt",
  29,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bge = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "bge",
  30,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bltu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "bltu",
  31,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_bgeu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "bgeu",
  32,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jal = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "jal",
  33,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_jalr = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "jalr",
  34,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_brTarget() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mul = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "mul",
  35,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulh = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "mulh",
  36,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "mulhu",
  37,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_mulhsu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "mulhsu",
  38,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lh = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "lh",
  39,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lhu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "lhu",
  40,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lb = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "lb",
  41,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_lbu = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "lbu",
  42,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rd() << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sb = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sb",
  43,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
static InstructionPrinter *instrPrinter_sh = new InstructionPrinter(
  FIVE_FW_DYPRE_InstrPrinterSet,
  "sh",
  44,
  [](Printer* printer_){
    std::stringstream ret_strs;
    FIVE_FW_DYPRE_Printer* printer = static_cast<FIVE_FW_DYPRE_Printer*>(printer_);
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_pc() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs1() << " | ";
    ret_strs << "0x" << std::setfill('0') << std::setw(16) << std::right << std::hex << printer->get_rs2() << " | ";
    ret_strs << std::setfill('-') << std::setw(18) << "" << " | ";
    return ret_strs.str();
  }
);
