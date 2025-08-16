#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int ability(void){/*calculate the ability score*/
    int dice_vals[4];
    int smallest_val=7;
    int index_smallest;
    int score=0;
    for(int i=0; i<4; i++){
        srand(time(NULL));
        int dice_roll=1 + rand() % 6;
        if(dice_roll < smallest_val){
            smallest_val=dice_roll;
            index_smallest=i;
        }
        dice_vals[i]=dice_roll;
    }
    for(int j=0; j<4; j++){
        if(j==index_smallest) continue;/*skip the smallest number*/
        score+=dice_vals[j]; /*add the rest.*/
    }
    return score;
}

int modifier(int score){
    return floor((score - 10.0) / 2.0);
}

dnd_character_t make_dnd_character(void){
    dnd_character_t hero={0};
    hero.strength=ability();
    hero.dexterity=ability();
    hero.constitution=ability();
    hero.intelligence=ability();
    hero.wisdom=ability();
    hero.charisma=ability();
    hero.hitpoints= 10 + modifier(hero.constitution);
    return hero;
}