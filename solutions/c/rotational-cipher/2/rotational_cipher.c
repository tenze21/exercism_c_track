#include "rotational_cipher.h"
#include "string.h"
#include "stdlib.h"
// #define MAXLEN 100

char *rotate(const char *text, int shift_key){
    size_t len= strlen(text);
    char *rotated= (char *)malloc(len + 1);

    for(int i=0; *text != '\0'; i++){
        if(*text >= 'A' && *text <= 'Z') rotated[i]= (((*text + shift_key) - 'A') % 26) + 'A';
        else if(*text >= 'a' && *text <= 'z') rotated[i]= (((*text + shift_key) - 'a') % 26) + 'a';
        else rotated[i]= *text;
        text++;
    }

    rotated[len]='\0';

    return rotated;
}