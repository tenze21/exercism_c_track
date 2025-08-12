#include <stdlib.h>
#include <string.h>
#include "rna_transcription.h"

char *to_rna(const char *dna){
    /*
        defining len as size_t type instead of an int eliminates implicit conversion of 
        size_t to int since strlen returns a size_t type, it also removes the need for 
        implicit conversion of int to size_t type when len is passed to malloc since malloc expects an argument of type size_t.
    */
    size_t len= strlen(dna);

    /*
        we can directly pass len + 1 to malloc in this case because size of char is 1 byte, but if 
        something like int was used then malloc would need to be called as malloc(len * sizeof(int)) 
        to get the exact number of bytes to allocate. 
    */
    char *rna_strand= malloc(len + 1); //allocate enough space for the null terminator too.
    memset(rna_strand, '\0', len + 1); //sets all the allocated byte to 0(null character).
    /*
        memset is actually unnecessary in this case since we are immediately assigning values 
        to the allocated memory block so, there is no risk of reading garbage data,
        but we need to terminate the string at the end
    */
    int i= 0;

    while (*dna)
    {
        switch (*dna)
        {
        case 'G':
            rna_strand[i] = 'C';
            break;
        case 'C':
            rna_strand[i]= 'G';
            break;
        case 'T':
            rna_strand[i]= 'A';
            break;
        case 'A':
            rna_strand[i]= 'U';
            break;
        default:
            free(rna_strand);
            return NULL;
        }
        i++;
        dna++;
    }
    //without memset
    // rna_strand[i]= '\0'; 
    return rna_strand;
}