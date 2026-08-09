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

#include "models/common/ICacheModel.h"

#include <limits>
#include <stdexcept>

namespace common{

ICacheModel::ICacheModel(PerformanceModel* parent_, const ICacheConfig& config_)
  : ResourceModel("ICacheModel", parent_)
  , config(validateConfig(config_))
  , tagCache(config.ways, std::vector<ICacheEntry>(config.sets))
  , offsetBits(log2OfPowerOfTwo(config.lineSizeBytes))
  , indexBits(log2OfPowerOfTwo(config.sets))
{}

int ICacheModel::getDelay(void)
{
  if(pc_ptr == nullptr)
  {
    throw std::logic_error("ICacheModel pc trace is not connected");
  }

  const uint64_t pc = pc_ptr[getInstrIndex()];

  // An uncached instruction fetch uses memory latency and blocks subsequent
  // fetches, but it must not allocate or evict a cache line.
  if(!cacheable(pc))
  {
    isMiss = true;
    return config.memoryDelay;
  }

  isMiss = !inCache(pc);
  return isMiss ? config.memoryDelay : config.cacheDelay;
}

bool ICacheModel::inCache(uint64_t pc)
{
  const std::size_t index = static_cast<std::size_t>(
      (pc >> offsetBits) & static_cast<uint64_t>(config.sets - 1));
  const uint64_t tag = pc >> (offsetBits + indexBits);

  for(std::size_t way = 0; way < config.ways; ++way)
  {
    const ICacheEntry& entry = tagCache[way][index];
    if(entry.valid && entry.tag == tag)
    {
      return true;
    }
  }

  updateCache(tag, index);
  return false;
}

bool ICacheModel::cacheable(uint64_t pc) const
{
  return config.cacheableBegin <= pc && pc < config.cacheableEnd;
}

void ICacheModel::updateCache(uint64_t tag, std::size_t index)
{
  std::size_t way = config.ways;

  for(std::size_t candidate = 0; candidate < config.ways; ++candidate)
  {
    if(!tagCache[candidate][index].valid)
    {
      way = candidate;
      break;
    }
  }

  if(way == config.ways)
  {
    way = nextReplacementWay();
  }

  tagCache[way][index].tag = tag;
  tagCache[way][index].valid = true;
}

std::size_t ICacheModel::nextReplacementWay(void)
{
  const uint8_t shiftIn = static_cast<uint8_t>(~(
      ((replacementState & 0x80) >> 7) ^
      ((replacementState & 0x08) >> 3) ^
      ((replacementState & 0x04) >> 2) ^
      ((replacementState & 0x02) >> 1))) & 0x01;
  replacementState = static_cast<uint8_t>((replacementState << 1) | shiftIn);
  return static_cast<std::size_t>(replacementState) % config.ways;
}

bool ICacheModel::isPowerOfTwo(std::size_t value)
{
  return value != 0 && (value & (value - 1)) == 0;
}

unsigned int ICacheModel::log2OfPowerOfTwo(std::size_t value)
{
  unsigned int result = 0;
  while(value > 1)
  {
    value >>= 1;
    ++result;
  }
  return result;
}

ICacheConfig ICacheModel::validateConfig(const ICacheConfig& candidate)
{
  if(candidate.ways == 0 || candidate.ways > 256)
  {
    throw std::invalid_argument("ICacheModel ways must be in the range [1, 256]");
  }
  if(!isPowerOfTwo(candidate.sets))
  {
    throw std::invalid_argument("ICacheModel sets must be a non-zero power of two");
  }
  if(!isPowerOfTwo(candidate.lineSizeBytes))
  {
    throw std::invalid_argument("ICacheModel line size must be a non-zero power of two");
  }
  if(candidate.ways > std::numeric_limits<std::size_t>::max() / candidate.sets)
  {
    throw std::invalid_argument("ICacheModel entry count overflows size_t");
  }
  if(log2OfPowerOfTwo(candidate.sets) +
         log2OfPowerOfTwo(candidate.lineSizeBytes) >= 64)
  {
    throw std::invalid_argument(
        "ICacheModel offset and index require fewer than 64 address bits");
  }
  if(candidate.cacheDelay < 0 || candidate.memoryDelay < candidate.cacheDelay)
  {
    throw std::invalid_argument(
        "ICacheModel delays must satisfy 0 <= cacheDelay <= memoryDelay");
  }
  if(candidate.cacheableBegin >= candidate.cacheableEnd)
  {
    throw std::invalid_argument("ICacheModel cacheable range must be non-empty");
  }

  return candidate;
}

} // namespace common
