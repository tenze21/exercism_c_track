#include "sum_of_multiples.h"
#include "stdlib.h"
#include "memory.h"
#include "stdbool.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit){
    bool *set=malloc(limit * sizeof(bool));
    memset(set, false, limit);

    int sum=0;
    for(size_t i=0; i<number_of_factors; i++){
        if(factors[i]==0) continue;
        for(int j=0; factors[i] * j < limit; j++){
            int multiple= factors[i] * j;
            if(!set[multiple]){
                sum+=multiple;
                set[multiple]= true;
            }
        }
    }

    return sum;
}