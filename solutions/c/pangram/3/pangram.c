#include "pangram.h"
#include <ctype.h>
#define EMPTY_SET 0
#define FULL_SET ((1 << 26) - 1)
#define INSERT(s, c) ((s) | 1 << (tolower(c) - 'a'))

//from @NobbZ's solution
bool is_pangram(const char *sentence){
    if(!sentence) return false;

    int set= EMPTY_SET;
    while(*sentence){
        if(isalpha(*sentence))
            set= INSERT(set, *sentence);

        if(set==FULL_SET) return true;/*using this condition here removes the need to go through the entire sentence since if all the alphabets are already found to exist mid sentence then directly return.*/
        sentence++;
    }
    return false;
}