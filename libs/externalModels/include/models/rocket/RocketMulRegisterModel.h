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

#ifndef ROCKET_MUL_REGISTER_MODEL_H
#define ROCKET_MUL_REGISTER_MODEL_H

#include <cstdint>

#include "PerformanceModel.h"

namespace rocket {

class RocketMulRegisterModel : public ConnectorModel
{
public:
  static constexpr uint64_t MUL_LATENCY_CYCLES = 5;
  static constexpr uint64_t DIV_LATENCY_CYCLES = 30;

  RocketMulRegisterModel(PerformanceModel* parent_);

  uint64_t* rs1_ptr = nullptr;
  uint64_t* rs2_ptr = nullptr;
  uint64_t* rd_ptr = nullptr;

  uint64_t getXa(void);
  uint64_t getXb(void);
  uint64_t getMulReady(void);
  uint64_t getDivReady(void);

  void setXd(uint64_t xd_);
  void setMulIssue(uint64_t issueCycle);
  void setDivIssue(uint64_t issueCycle);
  void reset(void);

  uint64_t getLastMulIssueCycle(void) const { return last_mul_issue_cycle; };
  uint64_t getLastMulResultReadyCycle(void) const { return last_mul_result_ready_cycle; };
  uint64_t getLastDivIssueCycle(void) const { return last_div_issue_cycle; };
  uint64_t getLastDivResultReadyCycle(void) const { return last_div_result_ready_cycle; };
  uint64_t getMulUnitNextIssueCycle(void) const { return muldiv_unit_next_issue_cycle; };

private:
  static constexpr int NUM_REGISTERS = 64;

  uint64_t register_ready[NUM_REGISTERS] = {0};
  uint64_t muldiv_unit_next_issue_cycle = 0;
  uint64_t last_mul_issue_cycle = 0;
  uint64_t last_mul_result_ready_cycle = 0;
  uint64_t last_div_issue_cycle = 0;
  uint64_t last_div_result_ready_cycle = 0;

  uint64_t getRegisterReady(uint64_t reg) const;
  uint64_t getMulDivReady(void) const;
  void setMulDivIssue(uint64_t issueCycle, uint64_t latencyCycles, bool isDivide);
};

} // namespace rocket

#endif // ROCKET_MUL_REGISTER_MODEL_H
