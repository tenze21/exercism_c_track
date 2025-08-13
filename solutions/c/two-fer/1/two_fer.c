#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name){
    char default_str[]="One for you, one for me.";
    char *strp=default_str;
    if(name){
        while(*strp){
            if(*strp == 'y'){
                while(*name){
                    *buffer= *name;
                    name++;
                    buffer++;
                }
                strp+=3;
            }
            *buffer= *strp;
            strp++;
            buffer++;
        }
        *buffer='\0';
    }else{
        strcpy(buffer, default_str);
    }
}