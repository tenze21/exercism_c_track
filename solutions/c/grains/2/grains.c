#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
        return 0;

    // represents 2^(index-1)
    // 1ULL(unsigned long long) = 64 bit representation of decimal 1(000...(63 zeros)...1)
    // using bit manipulation is more efficient and fast and prevents overflows in this case.
    return 1ULL << (index - 1);
}

// 2^64 - 1 is the maximum value for uint64_t, which means using 2^64 will cause an overflow.
uint64_t total(void)
{
    uint64_t total = 0;
    for(unsigned int i=1; i<=64; i++)
        total+=square(i);
    return total;
}