#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static char toUppercase(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a' + 'A';
    }
    return c;
} 

char *abbreviate(const char *phrase){
    // return NULL if phrase is NULL or is a 0 length string
    if(phrase == NULL || *phrase == '\0') return NULL;

    // make a copy of phrase to work on and get the abbreviation
    char *copy= malloc(strlen(phrase) + 1);
    if(copy == NULL) return NULL;

    strcpy(copy, phrase);

    char *abbreviation= calloc(strlen(phrase) + 1, sizeof(char));
    if(abbreviation == NULL){
        free(copy);
        return NULL;
    } 

    int pos=0;

    // tokenize the copy string
    char *word= strtok(copy, " -");
    while(word != NULL){
        // capitalize and save the first alphabetic character of the word to abbreviation 
        for(char *p= word; *p != '\0'; ++p){
            if(isalpha(*p)){
                abbreviation[pos++]= (char)toUppercase(*p);
                break;
            }
        }
        word= strtok(NULL, " -");
    }

    // terminate abbreviation
    abbreviation[pos]= '\0';
    free(copy);

    return abbreviation;
}