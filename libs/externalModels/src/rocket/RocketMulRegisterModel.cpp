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

#include "models/rocket/RocketMulRegisterModel.h"

#include <algorithm>

namespace rocket {

RocketMulRegisterModel::RocketMulRegisterModel(PerformanceModel* parent_)
  : ConnectorModel("RocketMulRegisterModel", parent_)
{
  reset();
}

void RocketMulRegisterModel::reset(void)
{
  std::fill(std::begin(register_ready), std::end(register_ready), 0);
  muldiv_unit_next_issue_cycle = 0;
  last_mul_issue_cycle = 0;
  last_mul_result_ready_cycle = 0;
  last_div_issue_cycle = 0;
  last_div_result_ready_cycle = 0;
}

uint64_t RocketMulRegisterModel::getRegisterReady(uint64_t reg) const
{
  if (reg == 0 || reg >= NUM_REGISTERS) {
    return 0;
  }
  return register_ready[reg];
}

uint64_t RocketMulRegisterModel::getXa(void)
{
  return getRegisterReady(rs1_ptr[getInstrIndex()]);
}

uint64_t RocketMulRegisterModel::getXb(void)
{
  return getRegisterReady(rs2_ptr[getInstrIndex()]);
}

uint64_t RocketMulRegisterModel::getMulReady(void)
{
  return getMulDivReady();
}

uint64_t RocketMulRegisterModel::getDivReady(void)
{
  return getMulDivReady();
}

uint64_t RocketMulRegisterModel::getMulDivReady(void) const
{
  if (muldiv_unit_next_issue_cycle == 0) {
    return 0;
  }

  /*
   * The generated scheduler adds the node delay after taking max(...).
   * Return one cycle before the real issue availability so the generated
   * MUL/DIV node becomes exactly muldiv_unit_next_issue_cycle.
   */
  return muldiv_unit_next_issue_cycle - 1;
}

void RocketMulRegisterModel::setXd(uint64_t xd_)
{
  uint64_t rd = rd_ptr[getInstrIndex()];
  if (rd == 0 || rd >= NUM_REGISTERS) {
    return;
  }
  register_ready[rd] = xd_;
}

void RocketMulRegisterModel::setMulIssue(uint64_t issueCycle)
{
  setMulDivIssue(issueCycle, MUL_LATENCY_CYCLES, false);
}

void RocketMulRegisterModel::setDivIssue(uint64_t issueCycle)
{
  setMulDivIssue(issueCycle, DIV_LATENCY_CYCLES, true);
}

void RocketMulRegisterModel::setMulDivIssue(uint64_t issueCycle, uint64_t latencyCycles, bool isDivide)
{
  uint64_t readyCycle = issueCycle + latencyCycles;
  muldiv_unit_next_issue_cycle = readyCycle;
  if (isDivide) {
    last_div_issue_cycle = issueCycle;
    last_div_result_ready_cycle = readyCycle;
  } else {
    last_mul_issue_cycle = issueCycle;
    last_mul_result_ready_cycle = readyCycle;
  }

  uint64_t rd = rd_ptr[getInstrIndex()];
  if (rd == 0 || rd >= NUM_REGISTERS) {
    return;
  }
  register_ready[rd] = readyCycle;
}

} // namespace rocket
