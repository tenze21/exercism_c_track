#include "resistor_color.h"
#include <stdio.h>

static resistor_band_t color_list[10]={COLORS};

unsigned int color_code(resistor_band_t color){
    return color;
}

resistor_band_t *colors(void){
    return color_list;
}