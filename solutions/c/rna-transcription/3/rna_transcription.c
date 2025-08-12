#include <stdlib.h>
#include <string.h>
#include "rna_transcription.h"

char *to_rna(const char *dna){
    int len= strlen(dna);
    char *rna_strand= malloc((len + 1) * sizeof(char));
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
    rna_strand[i]='\0';
    return rna_strand;
}