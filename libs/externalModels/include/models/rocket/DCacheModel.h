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

#ifndef ROCKET_D_CACHE_MODEL_H
#define ROCKET_D_CACHE_MODEL_H

#include <stdbool.h>
#include <cstdint>

#include "PerformanceModel.h"

namespace rocket{

struct DCacheEntry
{
  uint64_t tag = 0;
  bool valid = false;
};

class DCacheModel : public ResourceModel
{
public:

  // TODO: Check if delays are matching observations!
  DCacheModel(PerformanceModel* parent_) : ResourceModel("DCacheModel", parent_), CACHE_DELAY(1), MEMORY_DELAY(6), NOT_CACHABLE_DELAY(6) {};
  virtual int getDelay(void);

  // Info print
  std::string getInfo_miss(void) { return std::to_string(isMiss); };
  bool getMiss(void) const { return isMiss; };
  
  // Trace value
  uint64_t* addr_ptr;
  
private:

  // Cache state
  static constexpr int DCACHE_NUM_SETS   = 64;
  static constexpr int DCACHE_NUM_WAYS   = 8;
  static constexpr int DCACHE_LINE_BYTES = 64;
  static constexpr int DCACHE_OFFSET_BITS = 6;
  static constexpr int DCACHE_INDEX_BITS  = 6;

  static constexpr uint64_t MEMORY_BASE = 0x80000000ULL;
  static constexpr uint64_t MEMORY_SIZE = 0x10000000ULL;
  static constexpr uint64_t MEMORY_END  = MEMORY_BASE + MEMORY_SIZE;

  DCacheEntry tag_cache[DCACHE_NUM_WAYS][DCACHE_NUM_SETS];
  
  // Support functions
  bool inCache(uint64_t);
  bool cachable(uint64_t addr_) { return ((MEMORY_BASE <= addr_) && (addr_ < MEMORY_END)) ? true : false; };
  void updateCache(uint64_t, uint64_t);
  int lfsr(void);

  // Miss flag. Currently only used for info print
  bool isMiss = false;
  
  // Constants
  const int CACHE_DELAY;
  const int MEMORY_DELAY;
  const int NOT_CACHABLE_DELAY;

};

} // namespace rocket
  
#endif // ROCKET_D_CACHE_MODEL_H
