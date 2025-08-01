#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
    if (strlen(lhs) != strlen(rhs)) return -1;

    int hamming_d = 0;
    for (; *lhs != '\0'; lhs++, rhs++)
        if (*lhs != *rhs)
            hamming_d++;
            
    return hamming_d;
}