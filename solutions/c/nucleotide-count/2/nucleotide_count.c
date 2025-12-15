#include "nucleotide_count.h"
#include "stdio.h"
#include "stdlib.h"
#define FORMAT "A:%d C:%d G:%d T:%d"

char *count(const char *dna_strand){
    unsigned int a=0, c=0, g=0, t=0;
    char *res;

    while(*dna_strand){
        switch(*dna_strand){
            case 'A':
                ++a;
                break;
            case 'C':
                ++c;
                break;
            case 'G':
                ++g;
                break;;
            case 'T':
                ++t;
                break;
            default:
                if((res= malloc(1)) == NULL) return NULL;
                *res='\0';
                return res;
        }
        dna_strand++;
    }

    //determine the size to be allocated to res
    size_t nbr_char= snprintf(NULL, 0, FORMAT, a, c, g, t);

    //allocate the required size determined from above to res
    res= malloc(nbr_char + 1);
    if(res == NULL) return NULL;
    
    snprintf(res, nbr_char + 1, FORMAT, a, c, g, t);
    return res;
}