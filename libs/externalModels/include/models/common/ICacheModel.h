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

#ifndef COMMON_I_CACHE_MODEL_H
#define COMMON_I_CACHE_MODEL_H

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "PerformanceModel.h"

namespace common{

struct ICacheConfig
{
  ICacheConfig(std::size_t ways_ = 4,
               std::size_t sets_ = 256,
               std::size_t lineSizeBytes_ = 16,
               int cacheDelay_ = 1,
               int memoryDelay_ = 5,
               uint64_t cacheableBegin_ = 0x80000000,
               uint64_t cacheableEnd_ = 0xC0000000)
    : ways(ways_)
    , sets(sets_)
    , lineSizeBytes(lineSizeBytes_)
    , cacheDelay(cacheDelay_)
    , memoryDelay(memoryDelay_)
    , cacheableBegin(cacheableBegin_)
    , cacheableEnd(cacheableEnd_)
  {};

  std::size_t ways;
  std::size_t sets;
  std::size_t lineSizeBytes;
  int cacheDelay;
  int memoryDelay;
  uint64_t cacheableBegin;
  uint64_t cacheableEnd;
};

struct ICacheEntry
{
  uint64_t tag = 0;
  bool valid = false;
};

class ICacheModel : public ResourceModel
{
public:
  explicit ICacheModel(PerformanceModel* parent_,
                       const ICacheConfig& config_ = ICacheConfig());

  int getDelay(void) override;

  void setIc_in(uint64_t cycle_) { t_ic = isMiss ? cycle_ : 0; };
  uint64_t getIc_out(void) const { return t_ic; };

  std::string getInfo_miss(void) const { return std::to_string(isMiss); };
  const ICacheConfig& getConfig(void) const { return config; };

  // Trace value supplied by the owning performance model.
  uint64_t* pc_ptr = nullptr;

private:
  static bool isPowerOfTwo(std::size_t value);
  static unsigned int log2OfPowerOfTwo(std::size_t value);
  static ICacheConfig validateConfig(const ICacheConfig& config);

  bool inCache(uint64_t pc);
  bool cacheable(uint64_t pc) const;
  void updateCache(uint64_t tag, std::size_t index);
  std::size_t nextReplacementWay(void);

  const ICacheConfig config;
  std::vector<std::vector<ICacheEntry>> tagCache;
  const unsigned int offsetBits;
  const unsigned int indexBits;

  bool isMiss = false;
  uint64_t t_ic = 0;
  uint8_t replacementState = 0;
};

} // namespace common

#endif // COMMON_I_CACHE_MODEL_H
