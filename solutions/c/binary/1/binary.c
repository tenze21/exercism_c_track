#include "binary.h"
#include <math.h>
#include <string.h>

int convert(const char *input){/*convert string of binary input to it's decimal equivalent*/
    int len= strlen(input);
    /*since string is read from left to right get the 2's power of the most significant bit.*/
    int i= len - 1;
    int dec_equivalent=0;
    while(*input && i>=0){
        switch (*input)
        {
        case '0':
            break;
        case '1':
            dec_equivalent+=pow(2, i);
            break;
        default:
            return INVALID;
        }
        i--;
        input++;
    }
    return dec_equivalent;
}