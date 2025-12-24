#include "scrabble_score.h"
#include "ctype.h"
#include "stddef.h"
#define NUMBER_OF_LETTERS (26)

// FROM @bobahop's solution.
static unsigned int letter_score(char letter){
    switch (tolower(letter)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'l':
        case 'n':
        case 'r':
        case 's':
        case 't':
            return 1;
        case 'd':
        case 'g':
            return 2;
        case 'b':
        case 'c':
        case 'm':
        case 'p':
            return 3;
        case 'f':
        case 'h':
        case 'v':
        case 'w':
        case 'y':
            return 4;
        case 'k':
            return 5;
        case 'j':
        case 'x':
            return 8;
        case 'q':
        case 'z':
            return 10;
    }
    return 0;
}

unsigned int score(const char *word){
    if(word == NULL) return 0;
    unsigned int score=0;
    while(*word){
        score+= letter_score(*word);
        word++;
    }
    return score;
}