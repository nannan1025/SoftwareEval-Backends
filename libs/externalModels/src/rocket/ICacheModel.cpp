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

#include <cstdint>

#include "models/rocket/ICacheModel.h"

namespace rocket{

int ICacheModel::getDelay(void)
{
    uint64_t pc = pc_ptr[getInstrIndex()];

    isMiss = !inCache(pc);

    if(!cachable(pc) || isMiss)
    {
        return MEMORY_DELAY;
    }
    return CACHE_DELAY;
}

bool ICacheModel::inCache(uint64_t pc_)
{
    // uint64_t index = (pc_ >> 6) & 0xFF;    // 用 8 位 index → 256 sets
    // uint64_t tag   = pc_ >> (6 + 8);       // 其余高位
    uint64_t index = (pc_ >> 6) & (SETS - 1);  // (pc_ >> 6) & 0x3F

    // tag: bits [63:12]
    uint64_t tag = pc_ >> 12;


    for (int way = 0; way < WAYS; ++way) {
        if (tag_cache[way][index].tag == tag) {
            // hit
            return true;
        }
    }
    // Cache miss
    updateCache(tag, index);
    return false;
}

void ICacheModel::updateCache(uint64_t tag_, uint64_t index_)
{
    int way = -1;

    for(int i=0; i<WAYS; i++)
    {
      if(!tag_cache[i][index_].valid)
      {
        way = i;
        break;
      }
    }

    if(way == -1)
    {
      way = lfsr();
    }
    
    tag_cache[way][index_].tag = tag_;
    tag_cache[way][index_].valid = true;
}

int ICacheModel::lfsr(void)
{
    static uint8_t shift_state = 0;
    uint8_t shift_in = ~(((shift_state & 0x80) >> 7) ^ ((shift_state & 0x08) >> 3) ^ ((shift_state & 0x04) >> 2) ^ ((shift_state & 0x02) >> 1));
    shift_state = (shift_state << 1) | (shift_in & 0x01);
    return (shift_state & 0x03);
}

} // namespace rocket
