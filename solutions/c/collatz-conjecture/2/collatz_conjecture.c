#include "collatz_conjecture.h"

/*
using bitwise operators:
    * the operation "start & 1" results in a truthy value if start is odd and falsy if even. This can also be understood from the fact 
    that all odd numbers are 1 greater than an even number hence the least significant bit is always 1 which when &nd with 1 results in 1.(e.g, 11(3) & 01(1) = 1(truthy), 
    100(4) & 001(1) = 0(falsy))
    * the operation "start >> 1" is equivalent to dividing a number by 2. This is because right shifting a binary number by n positions is equivalent to dividing it by 2^n.
*/ 
int steps(int start){
    unsigned int steps;
    steps = 0;

    if(start < 1)
        return ERROR_VALUE;

    while(start != 1)
        if(!(start & 1)){
            start= start >> 1;
            steps++;
        }
        else{
            start= start * 3 + 1;
            steps++;
        }
    
    return steps;
}