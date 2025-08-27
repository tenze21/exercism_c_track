#include "resistor_color_trio.h"
resistor_value_t color_code(resistor_band_t colors[]){
    resistor_value_t resistance;
    uint64_t actual_value= (colors[0] * 10 + colors[1]) * pow(10, colors[2]);
}