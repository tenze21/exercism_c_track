#include "isogram.h"
#include <ctype.h>

bool is_isogram(const char phrase[]){
    if(!phrase){
        return false;
    }
    bool is_isogram= true;
    for(int i=0; phrase[i]; i++){
        if (phrase[i] == ' ' || phrase[i] == '-')continue;
        for(int j=i+1; phrase[j]; j++){
            if(tolower(phrase[i]) == tolower(phrase[j])){
                is_isogram=false;
                break;
            }
        }
    }
    return is_isogram;
}