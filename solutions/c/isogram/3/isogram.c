#include "isogram.h"
#include <ctype.h>
/*from bobahop's solution*/
#define INSERT(f, c) ((f) | 1 << (tolower(c) - 'a'))

bool is_isogram(const char phrase[]){
    if(!phrase) return false;

    int letter_flags=0;

    while(*phrase){
        if(isalpha(*phrase)){
            if((letter_flags & (1 << (tolower(*phrase) - 'a'))) != 0){/*If this value is not 0 means the letter already occured*/
                return false;
            }else{
                letter_flags=INSERT(letter_flags, *phrase);
            }
        }
        phrase++;
    }
    return true;
}