#include "allergies.h"
bool is_allergic_to(allergen_t allergen, int value){
    return value & (1U << allergen);
}

allergen_list_t get_allergens(int value){
    allergen_list_t allergen_list={0};
    for(allergen_t allergen=ALLERGEN_EGGS; allergen < ALLERGEN_COUNT; allergen++){
        allergen_list.count+=(allergen_list.allergens[allergen]=is_allergic_to(allergen, value))? 1 : 0;
    }
    return allergen_list;
}