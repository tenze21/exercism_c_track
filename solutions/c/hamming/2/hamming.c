#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    /*note: dereferencing the null terminator(\0) returns 0*/

    if(!lhs || !rhs) return -1;/*return -1 if either pointer is null*/

    if(!*lhs || !*rhs) return 0;/*return 0 if either string is empty*/

    int hamming_d = 0;
    for (; *lhs && *rhs; lhs++, rhs++)/*while both elements are not null*/
        if (*lhs != *rhs)
            hamming_d++;
            
    return (*lhs || *rhs)? -1 : hamming_d;/*if either is not pointing at the terminator means they are not the same length*/
}