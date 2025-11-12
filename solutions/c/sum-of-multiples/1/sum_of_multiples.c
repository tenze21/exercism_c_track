#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit){
    unsigned int result=0;
    int is_exist=0;//track if current multiple being processed has already occured

    for(int i=0; i<(int)number_of_factors; i++){
        if(factors[i] == 0) continue; // 0 is the only multiple of itself
        for(int j=1; factors[i] * j<limit; j++){//as long as the current multiple is less than limit
            is_exist=0;
            unsigned int multiple= factors[i] * j;
            if(i>0){
                for(int k=i; k>0; k--){
                    if(multiple % factors[k - 1] == 0){ // check if the current multiple is a factor of earlier factors 
                        is_exist=1;
                        break;
                    }
                }
            }

            if(!is_exist){
                result += multiple;
            }
        }
    }
    return result;
}