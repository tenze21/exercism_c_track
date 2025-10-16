#include "allergies.h"
bool is_allergic_to(allergen_t allergen, int value){
    return value & (1U << allergen);
}

allergen_list_t get_allergens(int value){
    allergen_list_t allergen_list={0};
    int shift=0;
    while(shift < ALLERGEN_COUNT){
        if(value & 1U){
            allergen_list.count++;
            allergen_list.allergens[shift]= true;
        }
        value= value >> 1;
        shift++;
    }
    return allergen_list;
}