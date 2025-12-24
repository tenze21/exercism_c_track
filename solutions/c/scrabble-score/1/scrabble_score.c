#include "scrabble_score.h"
#include "ctype.h"
#define NUMBER_OF_LETTERS (26)

static unsigned int letter_value[NUMBER_OF_LETTERS]={0};

static void init(void){
    for(int i=0; i<NUMBER_OF_LETTERS; i++)
        if(i==3 || i==6 ) letter_value[i]=2;
        else if(i==1 || i==2 || i==12 || i==15) letter_value[i]=3;
        else if(i==5 || i==7 || i==21 || i==22 || i==24) letter_value[i]=4;
        else if(i==10) letter_value[i]=5;
        else if(i==9 || i==23) letter_value[i]=8;
        else if(i==16 || i==25) letter_value[i]=10;
        else letter_value[i]=1;
}

unsigned int score(const char *word){
    init();
    unsigned int score=0;
    while(*word){
        unsigned int letter_idx=tolower(*word) - 'a';
        score+= letter_value[letter_idx];
        word++;
    }
    return score;
}