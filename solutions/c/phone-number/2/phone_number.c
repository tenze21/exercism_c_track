#include "phone_number.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITS 10
#define MAX_INP_LEN 32

static const char DELIMITERS[]= " +().-";

char *phone_number_clean(const char *input){
    // Using calloc to avoid having to manually null terminate string
    char *res=calloc(MAX_DIGITS + 1, sizeof(char));
    if(!res) return NULL;
    
    // copy input into a modifiable character array
    char input_cpy[MAX_INP_LEN]= {'\0'};
    strcpy(input_cpy, input);
    
    int get_pos=0, put_pos=0;
    
    // break the input sequence into different parts
    char *token= strtok(input_cpy, DELIMITERS);
    
    // process each part seperately
    while(token){
        char c;
        for(; (c= *token); token++, get_pos++){
            if(get_pos==0 && c=='1') continue;
            if(c < '0' || c > '9') break;
            res[put_pos++]= c;
        }
        token= strtok(NULL, DELIMITERS);
    }
    
    //check for invalid NANP sequence
    if(put_pos!=10 || res[0]<'2' || res[3]<'2'){
        memset(res, '0', MAX_DIGITS);
        res[MAX_DIGITS]= '\0';
    }
    return res;
}
