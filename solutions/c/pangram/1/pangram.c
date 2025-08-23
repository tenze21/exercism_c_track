#include "pangram.h"
bool is_pangram(const char *sentence){
    if(!sentence){
        return false;
    }
    bool letters_found[26]={false};
    while(*sentence){
        char c=*sentence;
        if(c>='A' && c<='Z'){
            letters_found[c-'A']=true;
        }else if(c>='a' && c<='z'){
            letters_found[c-'a']=true;
        }
        sentence++;
    }
    for(int i=0; i<26; i++){
        if(!letters_found[i]){
            return false;
        }
    }
    return true;
}