#include "isogram.h"
#include <ctype.h>

bool is_isogram(const char phrase[]){
    if(!phrase){
        return false;
    }
    bool is_isogram= true;
    for(int i=0; phrase[i]; i++){
        if (phrase[i] == ' ' || phrase[i] == '-')continue;
        int letter;
        if(phrase[i]>='a' && phrase[i] <= 'z'){
            letter= phrase[i] - 'a';
        }
        if(phrase[i]>='A' && phrase[i] <= 'Z'){
            letter= phrase[i] - 'A';
        }
        for(int j=i+1; phrase[j]; j++){
            if((phrase[j]>='a' && phrase[j]<='z') && (letter == phrase[j] - 'a')){
                is_isogram=false;
                break;
            }
            if((phrase[j]>='A' && phrase[j]<='Z') && (letter == phrase[j] - 'A')){
                is_isogram=false;
                break;
            }
        }
    }
    return is_isogram;
}