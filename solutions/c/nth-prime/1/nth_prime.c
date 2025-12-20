#include "nth_prime.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

uint32_t nth(uint32_t n){
    if(n==0) return 0;
    if(n==1) return 2;

    uint32_t limit= n * (log(n)+log(log(n))) + 5;// a little modification of the `n*ln(n)`
    
    uint32_t *nbr_arr= (uint32_t *)malloc(limit * sizeof(uint32_t));
    if(nbr_arr == NULL) return 0;

    for(uint32_t i=0; i<limit; i++) nbr_arr[i]=1;

    uint32_t count=0;
    for(uint32_t i=2; i<limit; i++){
        if(nbr_arr[i]){
            count++;
            if(count == n) return i;
            for(uint32_t j=i+i; j<limit; j+=i)nbr_arr[j]=0;
        }
    }
    free(nbr_arr);
    return 0;
}