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

#include "models/rocket/DividerModel.h"

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
 * Signed divider delay model.
 *
 * This follows the operand-normalization style used by the CVA6 divider model:
 * delay depends on the leading-zero relationship between dividend and divisor,
 * not only on the divisor magnitude.
 *
 * width = 64 for div/rem
 * width = 32 for divw/remw, if a separate 32-bit model is created.
 */
int rocketSignedDividerDelay(uint64_t dividend, uint64_t divisor, int width)
{
    const uint64_t mask = maskForWidth(width);
    const uint64_t signBit = 1ULL << (width - 1);

    dividend &= mask;
    divisor  &= mask;

    /*
     * Similar to the CVA6 model:
     * op_a_inv = negative ? ((~op_a) & ...FE) : op_a
     * op_b_inv = negative ? ~op_b : op_b
     */
    uint64_t dividendNorm;
    if (dividend & signBit) {
        dividendNorm = (~dividend) & mask;
        dividendNorm &= (mask & ~1ULL);
    } else {
        dividendNorm = dividend;
    }

    uint64_t divisorNorm;
    if (divisor & signBit) {
        divisorNorm = (~divisor) & mask;
    } else {
        divisorNorm = divisor;
    }

    /*
     * Keep Rocket's previous fast behavior for divide-by-zero.
     * If your RTL shows divide-by-zero is slow, change this separately.
     */
    if (divisorNorm == 0) {
        return 3;
    }

    int lzcDividend = leadingZeros(dividendNorm, width);
    int lzcDivisor  = leadingZeros(divisorNorm, width);

    int shift = lzcDivisor - (dividendNorm == 0 ? width : lzcDividend);

    int delay = (shift < 0) ? 2 : shift + 3;

    return clampDelay(delay, 2, width + 1);
}

} // namespace

int DividerModel::getDelay(void)
{
    // uint64_t rs1 = rs1_data_ptr[getInstrIndex()];
    // uint64_t rs2 = rs2_data_ptr[getInstrIndex()];

    // return rocketSignedDividerDelay(rs1, rs2, 64);
    return 1;
}

} // namespace rocket
