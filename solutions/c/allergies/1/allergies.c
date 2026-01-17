#include "allergies.h"
bool is_allergic_to(allergen_t allergen, int value){
    if((value >> allergen) % 2 != 0) return true;
    return false;
}

allergen_list_t get_allergens(int value){
    allergen_list_t allergen_list;
    allergen_list.count=0;
    int shift=0;
    while(value > 0 && shift < 8){
        if(value % 2 != 0){
            allergen_list.count++;
            allergen_list.allergens[shift]= true;
        }
        value= value >> 1;
        shift++;
    }
    return allergen_list;
}