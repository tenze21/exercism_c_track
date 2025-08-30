#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){
    int temp=candidate;
    int number_of_digits;
    int result=0;
    for(number_of_digits=0; temp>0; number_of_digits++){/*count number of digits*/
        temp/=10;
    }/*temp becomes 0 after this loop*/

    temp=candidate;/*reset temp to be the value of the candidate*/
    for(; temp>0; temp/=10){
        result += (int)pow(temp % 10, number_of_digits);
    }

    return result==candidate;
}