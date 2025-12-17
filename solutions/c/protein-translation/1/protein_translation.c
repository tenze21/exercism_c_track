#include "protein_translation.h"
#include "string.h"

protein_t protein(const char *rna){
    protein_t protein={.valid=true, .count=0};

    while(*rna){
        if(strncmp(rna, "AUG", 3)==0){
            protein.amino_acids[protein.count]=Methionine;
            protein.count++;
        }else if(strncmp(rna, "UUU",3)==0 || strncmp(rna, "UUC", 3)==0){
            protein.amino_acids[protein.count]=Phenylalanine;
            protein.count++;
        }else if(strncmp(rna, "UUA",3)==0 || strncmp(rna, "UUG", 3)==0){
            protein.amino_acids[protein.count]=Leucine;
            protein.count++;
        }else if(strncmp(rna, "UCU", 3)==0 || strncmp(rna, "UCC", 3)==0 || strncmp(rna, "UCA", 3)==0 || strncmp(rna, "UCG", 3)==0){
            protein.amino_acids[protein.count]=Serine;
            protein.count++;
        }else if(strncmp(rna, "UAU", 3)==0 || strncmp(rna, "UAC", 3)==0){
            protein.amino_acids[protein.count]=Tyrosine;
            protein.count++;
        }else if(strncmp(rna, "UGU", 3)==0 || strncmp(rna, "UGC", 3)==0){
            protein.amino_acids[protein.count]=Cysteine;
            protein.count++;
        }else if(strncmp(rna, "UGG", 3)==0){
            protein.amino_acids[protein.count]=Tryptophan;
            protein.count++;
        }else if(strncmp(rna, "UAA", 3)==0 || strncmp(rna, "UAG", 3)==0 || strncmp(rna, "UGA", 3)==0){
            break;
        }else{
            protein.valid=false;
            break;
        }
        rna+=3;
    }

    return protein;
}
