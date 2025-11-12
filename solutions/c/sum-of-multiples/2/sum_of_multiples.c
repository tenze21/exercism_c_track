#include "sum_of_multiples.h"

bool is_uniq(const unsigned int *factors, unsigned int curr_factor_idx, unsigned int multiple){
    for(unsigned int i=0; i<curr_factor_idx; i++){
        if(multiple % factors[i] == 0){
            return false;
        }
    }
    return true;
}


unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit){
    unsigned int result=0;

    for(size_t i=0; i<number_of_factors; i++){

        if(factors[i] == 0) continue; // 0 is the only multiple of itself

        for(int j=1; factors[i] * j<limit; j++){//as long as the current multiple is less than limit
            unsigned int multiple= factors[i] * j;
            if(is_uniq(factors, i, multiple)) result+= multiple;
        }
    }
    return result;
}