#include "resistor_color.h"
#include <stdio.h>

unsigned int color_code(resistor_band_t color){
    return color;
}

resistor_band_t *colors(void){
    static resistor_band_t color_list[]={BLACK, BROWN, RED, ORANGE, YELLOW, GREEN,BLUE, VIOLET, GREY, WHITE};
    return color_list;
}