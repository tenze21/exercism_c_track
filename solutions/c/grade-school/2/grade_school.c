#include "grade_school.h"

static void sort(roster_t *roster){/*insertion sort due to it's efficiency with already sorted or nearly sorted lists*/
    for(size_t i=1; i<roster->count; i++){
        student_t key=roster->students[i];
        int j=i-1;
        while(j>=0 && (roster->students[j].grade > key.grade || (roster->students[j].grade == key.grade && strcmp(roster->students[j].name, key.name)>0))){
            roster->students[j+1]=roster->students[j];
            j--;
        }
        roster->students[j+1]=key;
    }
}

static bool is_present(roster_t *roster, char *name){
    for(size_t i=0; i<roster->count; i++){
        if(strcmp(roster->students[i].name, name)==0) return true;
    }
    return false;
}

void init_roster(roster_t *roster){
    roster->count=0;
}

bool add_student(roster_t *roster, char *name, uint8_t grade){
    if(roster->count>=MAX_STUDENTS) return false;
    if(is_present(roster, name)) return false;

    student_t *std= &roster->students[roster->count];
    strncpy(std->name, name, MAX_NAME_LENGTH - 1);
    std->grade=grade;

    roster->count++;
    sort(roster);
    return true;
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade){
    roster_t res;
    init_roster(&res);
    for(size_t i=0; i<roster->count && roster->students[i].grade <= desired_grade; i++){
        if(roster->students[i].grade==desired_grade) add_student(&res, roster->students[i].name, roster->students[i].grade);
    }
    return res;
}