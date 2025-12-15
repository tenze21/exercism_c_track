#include "nucleotide_count.h"
#include "stdio.h"
#include "stdlib.h"
#define MAX_STR_LEN sizeof("A:## C:## G:## T:##")

char *count(const char *dna_strand){
    unsigned int count[4]={0};
    char *res= malloc(MAX_STR_LEN + 1);

    while(*dna_strand){
        if(*dna_strand == 'A') count[0]+=1;
        else if(*dna_strand == 'C') count[1]+=1;
        else if(*dna_strand == 'G') count[2]+=1;
        else if(*dna_strand == 'T') count[3]+=1;
        else{
            res[0]='\0';
            return res;
        }
        dna_strand++;
    }

    snprintf(res, MAX_STR_LEN + 1, "A:%d C:%d G:%d T:%d", count[0], count[1], count[2], count[3]);
    
    return res;
}