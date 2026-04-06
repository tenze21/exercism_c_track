#include "phone_number.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITS 11 // number of digits + terminator

typedef enum number_parts{COUNTRY_CODE, AREA_CODE, EXCHANGE_CODE, SUBSCRIBER_NUMBER} number_parts_t;

char *phone_number_clean(const char *input){
    if(!input) return NULL;
    
    char *res=calloc(MAX_DIGITS, sizeof(char));
    if(!res) return NULL;
    
    if(strlen(input)==11){
        if(*input != '1') goto INVALID_NUMBER;
        memcpy(res, &input[1], (size_t)10);
        return res;
    }
    
    if(*input=='+') input+=3;
    
    if(*input=='1') input+=2;
    
    number_parts_t current_part= AREA_CODE;
    int i= 0;
    while(*input){
        if(*input == '-' || *input=='.' || *input==' '){
            if(current_part == SUBSCRIBER_NUMBER) break;
            if(*(input + 1) != ' ') current_part++;
            input++;
            continue;
        }
        
        if(current_part == AREA_CODE){
            if(*input < '0' || *input > '9') goto INVALID_NUMBER;
            if(*input == '(' || *input == ')'){
                input++;
                continue;
            }
            if((i==0 && *input=='1') || i>2){
                goto INVALID_NUMBER;
            }
            res[i]= *input;
            i++;
        }
        
        if(current_part ==  EXCHANGE_CODE){
            if(*input < '0' || *input > '9') goto INVALID_NUMBER;
            if((i==3 && *input=='1') || i>5){
                goto INVALID_NUMBER;
            }
            res[i]= *input;
            i++;
        }
        
        if(current_part ==  SUBSCRIBER_NUMBER){
            if(*input < '0' || *input > '9') goto INVALID_NUMBER;
            if(i>9){
                goto INVALID_NUMBER;
            }
            res[i]= *input;
            i++;
        }
        input++;
    }
    return res;
    
    INVALID_NUMBER:
        memset(res, '0', sizeof(char)*10);
        return res;
}
