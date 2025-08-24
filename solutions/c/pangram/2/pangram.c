#include "pangram.h"

bool is_pangram(const char *sentence){
    if(!sentence){
        return false;
    }

    int phrasemask=0;
    while(*sentence){
        char c=*sentence;
        if(c>='A' && c<='Z'){
            phrasemask|=1 << (c - 'A');//sets the corresponding bit to 1. letter='a' bit 1 gets set to 1
        }else if(c>='a' && c<='z'){
            phrasemask|=1 << (c-'a');
        }
        sentence++;
    }

    return phrasemask == 67108863;//Check if all the 26 bits are set to 1. 2^26 - 1=67108863.
}