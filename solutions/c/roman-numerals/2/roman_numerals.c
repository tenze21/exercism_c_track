#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 16 // The longest roman numerial is MMMDCCCLXXXVIII, 15 + 1 

typedef struct
{
    char *symbol;
    unsigned int value;
    unsigned int len;
} roman_numerial_t;

static roman_numerial_t lookup[] = {
    {"M", 1000, 1},
    {"CM", 900, 2},
    {"D", 500, 1},
    {"CD", 400, 2},
    {"C", 100, 1},
    {"XC", 90, 2},
    {"L", 50, 1},
    {"XL", 40, 2},
    {"X", 10, 1},
    {"IX", 9, 2},
    {"V", 5, 1},
    {"IV", 4, 2},
    {"I", 1, 1}};

char *to_roman_numeral(unsigned int number)
{
    char buff[BUFF_SIZE] = {'\0'};
    char *buff_ptr = buff;

    for (int i = 0; i < 13; ++i)
    {
        if (number <= 0)
            break;
        roman_numerial_t roman_numerial = lookup[i];
        while (number >= roman_numerial.value)
        {
            memcpy(buff_ptr, roman_numerial.symbol, roman_numerial.len);
            number -= roman_numerial.value;
            buff_ptr += roman_numerial.len;
        }
    }

    size_t len= strlen(buff) + 1;
    char *res= malloc(len);
    if(res == NULL) return NULL;

    memcpy(res, buff, len);
    return res;
}

/*
ITERATING THROUGH THE FUNCTION:
let number = 1994
i=0:
    lookup= 1000, "M"
    1994 > 1000:
        buff="M"
        number=994
i=1:
    lookup=900, "CM"
    994>900:
        buff="MCM"
        number=94
i=2:
    lookup=500, "D"
    94 !> 500:
...
i=5:
    lookup=90, "XC"
    94 > 90:
        buff="MCMXC"
        number=4
...
i=11:
    lookup=4, "IV"
    4 == 4:
        buff="MCMXCIV"
        number = 0

break;
*/