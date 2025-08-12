#include <stdlib.h>
#include "rna_transcription.h"

char *to_rna(const char *dna){
    char rna_strand[100];
    int i= 0;

    while (*dna != '\0')
    {
        switch (*dna)
        {
        case 'G':
            rna_strand[i] = 'C';
            i++;
            dna++;
            break;
        case 'C':
            rna_strand[i]= 'G';
            i++;
            dna++;
            break;
        case 'T':
            rna_strand[i]= 'A';
            i++;
            dna++;
            break;
        case 'A':
            rna_strand[i]= 'U';
            i++;
            dna++;
            break;
        default:
            break;
        }
    }
    rna_strand[i]='\0';

    return rna_strand;
}