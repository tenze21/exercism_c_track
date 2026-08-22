#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>
#define R_ONE 0
#define R_FIVE 1
#define R_TEN 2
#define R_FIFTY 3
#define R_HUNDRED 4
#define R_FIVE_HUNDRED 5
#define R_ONE_THOUSAND 6


typedef struct {
    int intVal;
    char roman[3];
} roman_value;

char *to_roman_numeral(unsigned int number)
{
    char res[]= calloc(9, sizeof(char));
    roman_value pairs[]={{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {900, "CM"}, {400, "CD"}, {90, "XC"}, {40, "XL"}, {9, "IX"}, {4, "IV"}};

}