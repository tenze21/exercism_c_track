#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){//a direct implementation of the method stated in the instructions.
    uint64_t factor=2;
    uint8_t idx=0;
    while(n>1){
        if(n%factor==0){
            n/=factor;
            factors[idx]= factor;
            idx++;
            continue;
        }
        factor++;
    }
    return (size_t)idx;
}