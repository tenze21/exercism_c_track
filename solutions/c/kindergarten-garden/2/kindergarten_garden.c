#include "kindergarten_garden.h"
#include "stddef.h"
#include "string.h"
#include "assert.h"

static const char *students[]={"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
static const size_t students_size=sizeof(students)/sizeof(*students);

static plant_t identify_plant(char encoding){
    switch (encoding)
    {
    case 'C': return CLOVER;
    case 'G': return GRASS;
    case 'R': return RADISHES;
    case 'V': return VIOLETS;
    default: return INVALID;
    }
}

plants_t plants(const char *diagram, const char *student){
    assert(diagram && "diagram must not be NULL");
    assert(student && "student must not be NULL");
    size_t diagram_len= strlen(diagram);

    unsigned int stdnt_idx=0;
    while(stdnt_idx<students_size){
        if(strcmp(student, students[stdnt_idx])==0) break;
        stdnt_idx++;
    }
    assert(stdnt_idx<students_size && "Student not found");//if stdnt_idx==12 means student name isn't in the students array.

    unsigned int first_row_start=stdnt_idx * 2;
    unsigned int second_row_start=(diagram_len / 2) + first_row_start + 1;

    return (plants_t){{
        identify_plant(diagram[first_row_start]),
        identify_plant(diagram[first_row_start + 1]),
        identify_plant(diagram[second_row_start]),
        identify_plant(diagram[second_row_start + 1])
    }};
}
