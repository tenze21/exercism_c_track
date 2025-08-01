#include "difference_of_squares.h"
#include <stdio.h>

unsigned int sum_of_squares(unsigned int number)
{
    unsigned int i, sum;
    sum = 0;
    for (i = 1; i <= number; i++)
        sum += i * i;
    return sum;
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int i, sum;
    sum = 0;
    for (i=1; i<=number; i++)
        sum+=i;
    return sum * sum;
}

unsigned int difference_of_squares(unsigned int number){
    unsigned int n, m;
    n= square_of_sum(number);
    m= sum_of_squares(number);
    return n - m;
}