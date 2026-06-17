/*
 * Copyright 2023 Chair of EDA, Technical University of Munich
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

#include "models/rocket/DividerUnsignedModel.h"

#include <cstdint>
#include <stdbool.h>


namespace rocket {

namespace {

uint64_t maskForWidth(int width)
{
    if (width >= 64) {
        return ~0ULL;
    }
    return (1ULL << width) - 1ULL;
}

int leadingZeros(uint64_t value, int width)
{
    value &= maskForWidth(width);

    if (value == 0) {
        return width;
    }

    int zeros = 0;
    for (int bit = width - 1; bit >= 0; --bit) {
        if ((value >> bit) & 1ULL) {
            break;
        }
        ++zeros;
    }
    return zeros;
}

int clampDelay(int delay, int minDelay, int maxDelay)
{
    if (delay < minDelay) {
        return minDelay;
    }
    if (delay > maxDelay) {
        return maxDelay;
    }
    return delay;
}

/*
 * Unsigned divider delay model.
 *
 * Old model:
 *   delay = f(divisor)
 *
 * New model:
 *   delay = f(dividend, divisor)
 *
 * This is important because the divider can early-out when the dividend
 * is smaller than the divisor, even if the divisor itself has many bits.
 */
int rocketUnsignedDividerDelay(uint64_t dividend, uint64_t divisor, int width)
{
    const uint64_t mask = maskForWidth(width);

    dividend &= mask;
    divisor  &= mask;

    /*
     * Keep Rocket's previous fast behavior for divide-by-zero.
     * If RTL evidence shows divide-by-zero is slow, adjust this separately.
     */
    if (divisor == 0) {
        return 3;
    }

    int lzcDividend = leadingZeros(dividend, width);
    int lzcDivisor  = leadingZeros(divisor, width);

    int shift = lzcDivisor - (dividend == 0 ? width : lzcDividend);

    int delay = (shift < 0) ? 2 : shift + 3;

    return clampDelay(delay, 2, width + 1);
}

} // namespace

int DividerUnsignedModel::getDelay(void)
{
    // uint64_t rs1 = rs1_data_ptr[getInstrIndex()];
    // uint64_t rs2 = rs2_data_ptr[getInstrIndex()];

    // return rocketUnsignedDividerDelay(rs1, rs2, 64);
    return 1;
}

} // namespace rocket