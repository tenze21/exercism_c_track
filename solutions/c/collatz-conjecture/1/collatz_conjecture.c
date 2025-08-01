#include "collatz_conjecture.h"

int steps(int start){
    int steps, c;
    steps = 0;
    c = start;

    if(c < 1)
        return ERROR_VALUE;

    while(c != 1)
        if(c % 2 == 0){
            c/=2;
            steps++;
        }
        else{
            c= c * 3 + 1;
            steps++;
        }
    
    return steps;
}