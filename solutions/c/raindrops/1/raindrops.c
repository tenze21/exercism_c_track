#include "raindrops.h"
#include <string.h>
#define DIVISIBLE_BY_THREE "Pling"
#define DIVISIBLE_BY_FIVE "Plang"
#define DIVISIBLE_BY_SEVEN "Plong"

void convert(char result[], int drops){
    char tempBuffer[2]={0};
    if(drops % 3 == 0){
        strcat(result, DIVISIBLE_BY_THREE);
    }
    if(drops % 5 == 0){
        strcat(result, DIVISIBLE_BY_FIVE);
    }
    if(drops % 7 == 0){
        strcat(result, DIVISIBLE_BY_SEVEN);
    }
    if(drops % 3 != 0 && drops % 5 != 0 && drops % 7 != 0){
        for(; drops > 0; drops/=10){
            tempBuffer[0]= '0' + (drops % 10);
            strcat(result, tempBuffer);
        }
    }
}