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

// TODO: Proof-of-concept model, taken from Robert (more or less)!

#ifndef ROCKET_I_CACHE_MODEL_H
#define ROCKET_I_CACHE_MODEL_H

#include <stdbool.h>
#include <cstdint>

#include "PerformanceModel.h"

namespace rocket{

struct ICacheEntry
{
  uint64_t tag = 0;
  bool valid = false;
};

class ICacheModel : public ResourceModel
{
public:

  ICacheModel(PerformanceModel* parent_) : ResourceModel("ICacheModel", parent_), CACHE_DELAY(1), MEMORY_DELAY(22) {};
  virtual int getDelay(void);
  
  void setIc_in(uint64_t c_) { t_ic = isMiss ? c_ : 0; };
  uint64_t getIc_out(void) { return t_ic; };

  std::string getInfo_miss(void) { return std::to_string(isMiss); };
  bool getMiss(void) const { return isMiss; };
  
  // Trace value
  uint64_t* pc_ptr;

private:
  
  // Cache state
  static constexpr int ICACHE_NUM_SETS   = 64;
  static constexpr int ICACHE_NUM_WAYS   = 8;
  static constexpr int ICACHE_LINE_BYTES = 64;
  static constexpr int ICACHE_OFFSET_BITS = 6;
  static constexpr int ICACHE_INDEX_BITS  = 6;

  static constexpr uint64_t MEMORY_BASE = 0x80000000ULL;
  static constexpr uint64_t MEMORY_SIZE = 0x10000000ULL;
  static constexpr uint64_t MEMORY_END  = MEMORY_BASE + MEMORY_SIZE;

  ICacheEntry tag_cache[ICACHE_NUM_WAYS][ICACHE_NUM_SETS];

  bool isMiss = false;

  // Time when ICache relaeses block on miss
  uint64_t t_ic = 0;
  
  // Constants
  const int CACHE_DELAY;
  const int MEMORY_DELAY;

  // Support functions
  bool inCache(uint64_t);
  bool cachable(uint64_t pc_) { return ((MEMORY_BASE <= pc_) && (pc_ < MEMORY_END)) ? true : false; };
  void updateCache(uint64_t, uint64_t);
  int lfsr(void);
};

} // namespace rocket  
  
#endif // ROCKET_I_CACHE_MODEL_H
