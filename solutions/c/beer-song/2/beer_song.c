#include "beer_song.h"
#include "stdio.h" 
#define MAX_LINE_LENGTH (1024)

static const char *FIRST_LINE[]={
    "No more bottles of beer on the wall, no more bottles of beer.",
    "1 bottle of beer on the wall, 1 bottle of beer.",
    "%u bottles of beer on the wall, %u bottles of beer."
};

static const char *SECOND_LINE[]={
    "Go to the store and buy some more, 99 bottles of beer on the wall.",
    "Take it down and pass it around, no more bottles of beer on the wall.",
    "Take one down and pass it around, 1 bottle of beer on the wall.",
    "Take one down and pass it around, %u bottles of beer on the wall."
};

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    for(uint8_t bottles_left=start_bottles; take_down>0; bottles_left--, take_down--){
        snprintf(*song++, MAX_LINE_LENGTH, FIRST_LINE[bottles_left > 1? 2 : bottles_left], bottles_left, bottles_left);
        snprintf(*song++, MAX_LINE_LENGTH, SECOND_LINE[bottles_left - 1 > 1? 3 : bottles_left], bottles_left - 1);
        song++;//skip to leave empty string berween verses.
    }
}

/*
*song++ == *(song++): it increments the pointer but the current pointer value is used since it's a postfix increment and *song gives the current string pointer.
*/