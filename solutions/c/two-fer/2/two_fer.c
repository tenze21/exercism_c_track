#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name){/*if name is not NULL we build a new string with the name.*/
    char default_str[]="One for you, one for me.";
    char *strp=default_str;
    if(name){/*name is not NULL.*/
        while(*strp){
            if(*strp == 'y'){/*replace "you" in default_str with name.*/
                while(*name){/*put the name in buffer.*/
                    *buffer= *name;
                    name++;
                    buffer++;
                }
                strp+=3;/*skip the "you".*/
            }
            *buffer= *strp;
            strp++;
            buffer++;
        }
        *buffer='\0';/*terminate the new string.*/
    }else{
        strcpy(buffer, default_str);/*directly copy default_str to buffer.*/
    }
}