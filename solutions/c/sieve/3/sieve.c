#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    int nbr_arr[limit - 1];
    int n=2;
    for(uint32_t i=0; i<limit - 1; i++) nbr_arr[i]= n++;
    
    uint32_t prime_count=0;
    for(uint32_t i=0; i<limit - 1 && prime_count<max_primes; i++){
        if(nbr_arr[i] != 0){
            primes[prime_count]= nbr_arr[i];
            prime_count++;

            for(uint32_t j=i + nbr_arr[i]; j<limit - 1; j+=nbr_arr[i]) nbr_arr[j]=0;
        }
    }
    return prime_count;
}