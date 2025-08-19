#include "perfect_numbers.h"
kind classify_number(int num){
    if(num <= 0){
        return ERROR;
    }
    int aliquot_sum= 0;
    /*add all the factors of the number excluding itself*/
    for(int i=1; i <= num/2; i++){
        if(num % i == 0) aliquot_sum+=i;
    }

    if(aliquot_sum == num){
        return PERFECT_NUMBER;
    }else if(aliquot_sum > num){
        return ABUNDANT_NUMBER;
    }else{
        return DEFICIENT_NUMBER;
    }
} 