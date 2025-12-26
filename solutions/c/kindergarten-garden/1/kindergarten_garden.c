#include "kindergarten_garden.h"
#include "stddef.h"
#include "string.h"

typedef enum {ALICE=0, BOB, CHARLIE, DAVID, EVE, FRED, GINNY, HARRIET, ILEANA, JOSEPH, KINCAID, LARRY} student_t;

static plant_t identify_plant(char encoding){
    switch (encoding)
    {
    case 'C':
        return CLOVER;
        break;
    case 'G':
        return GRASS;
        break;
    case 'R':
        return RADISHES;
        break;
    case 'V':
        return VIOLETS;
        break;
    default:
        return INVALID;
        break;
    }
}

plants_t plants(const char *diagram, const char *student){
    plants_t stdnt_plants;
    student_t stdnt=student[0] - 'A';
    size_t len= strlen(diagram);

    unsigned int first_row_start=stdnt * 2;
    unsigned int second_row_start=(len / 2) + first_row_start + 1;
    unsigned int plant_idx=0;
    for(unsigned int i=first_row_start; i<(first_row_start + 2); i++){
        stdnt_plants.plants[plant_idx]=identify_plant(diagram[i]);
        plant_idx++;
    }
    
    for(unsigned int i=second_row_start; i<(second_row_start + 2); i++){
        stdnt_plants.plants[plant_idx]=identify_plant(diagram[i]);
        plant_idx++;
    }

    return stdnt_plants;
}
