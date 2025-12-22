#include "all_your_base.h"
#include "math.h"

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length){
    if(digits == NULL || input_length == 0 || output_base<=1 || input_base <= 1) return 0;

    int16_t input_nbr=0;
    double exp=input_length - 1;
    for(size_t i=0; i<input_length; i++){
        if(digits[i]<0 || digits[i]>=input_base) return 0;
        input_nbr+=(int16_t)digits[i] * (int16_t)pow(input_base, exp);
        exp--;
    }
    
    if(input_nbr < 1) return 1;
    
    size_t output_size=0;
    for(int16_t n=input_nbr; n>0; n/=output_base) output_size++;

    for(size_t i= output_size - 1; input_nbr>0; i--){
        digits[i]= input_nbr % output_base;
        input_nbr/=output_base;
    }

    return output_size;
}