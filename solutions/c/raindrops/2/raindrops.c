#include "raindrops.h"
#include <string.h>
#include <stdio.h>
#define DIVISIBLE_BY_THREE "Pling"
#define DIVISIBLE_BY_FIVE "Plang"
#define DIVISIBLE_BY_SEVEN "Plong"

void convert(char result[], int drops){
    if(drops % 3 == 0){
        strcat(result, DIVISIBLE_BY_THREE);
    }
    if(drops % 5 == 0){
        strcat(result, DIVISIBLE_BY_FIVE);
    }
    if(drops % 7 == 0){
        strcat(result, DIVISIBLE_BY_SEVEN);
    }
    if(strlen(result) == 0){
        sprintf(result, "%d", drops);
    }
}