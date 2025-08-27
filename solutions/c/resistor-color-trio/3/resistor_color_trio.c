#include "resistor_color_trio.h"
resistor_value_t color_code(resistor_band_t colors[]){
    resistor_value_t resistance;
    uint64_t actual_value= (colors[0] * 10 + colors[1]) * pow(10, colors[2]);/*kept it uint64_t here to fit the maximum possible resistance.*/
    int i=0;/*number of zores*/
    while(1){/*count the number of zeros*/
        if(actual_value % 10 != 0 || actual_value == 0){/*there are no more zeros*/
            break;
        }
        actual_value/=10;
        i++;
    }
    if(i >= 0 && i < 3){
        resistance.unit=OHMS;
        resistance.value= (uint16_t)actual_value * pow(10, i);
    }else if(i>=3 && i<6){
        resistance.unit=KILOOHMS;
        resistance.value= (uint16_t)actual_value * pow(10, i - 3);/*KILO => three zeros*/
    }else if(i>=6 && i<9){
        resistance.unit= MEGAOHMS;
        resistance.value= (uint16_t)actual_value * pow(10, i - 6);/*MEGA => six zeros*/
    }else{
        resistance.unit= GIGAOHMS;
        resistance.value= (uint16_t)actual_value * pow(10, i - 9);/*GIGA => nine zeros*/
    }
    return resistance;
}