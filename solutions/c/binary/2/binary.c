#include "binary.h"
#include <math.h>
#include <string.h>

int convert(const char *input){/*convert string of binary input to it's decimal equivalent*/
    int res= 0;
    while(*input){
        if(*input != '0' && *input != '1') return INVALID;
        // left shift the initial value and add the current value, just like 2 * 10 shifts 2 one place to the left.
        res = res * 2 + (*input == '0'? 0 : 1);
        input++;
    }
    return res;
}