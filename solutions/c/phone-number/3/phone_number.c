#include "phone_number.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_DIGITS 10

char *phone_number_clean(const char *input){
    // Using calloc to avoid having to manually null terminate string
    char *res=calloc(MAX_DIGITS + 1, sizeof(char));
    if(!res) return NULL;
    
    // Skip country code
    if(*input == '+') input+=2;
    if(*input =='1') input++;
    
    int put_pos=0;
    // write all valid digits to res
    for(int get_pos=0; input[get_pos]; ++get_pos){
        char c= input[get_pos];
        if(isdigit(c)){
            // break if area code or exchange code starts with 0 or 1
            if((put_pos==0 || put_pos==3) && input[get_pos]<'2') break;
            res[put_pos++]= input[get_pos];
        }
    }
    if(put_pos!=MAX_DIGITS){
        // if there are more than 10 digits set all to 0(null terminator)
        memset(res, '\0', put_pos);
        memset(res, '0', MAX_DIGITS);
    }
    res= realloc(res, MAX_DIGITS + 1);
    return res;
}
