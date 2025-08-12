#include "eliuds_eggs.h"
unsigned int egg_count(unsigned int decimal){
    int eggs=0;
    
    for(int current= decimal; current >= 1; current= current / 2)
        if(current % 2 == 1) eggs++;
    return eggs;
}
