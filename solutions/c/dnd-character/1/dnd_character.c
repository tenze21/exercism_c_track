#include "dnd_character.h"
#include <stdlib.h>
#include <time.h>

int ability(void){/*calculate the ability score*/
    int nums[4];
    int smallest_num=7;
    int index_smallest;
    int score=0;
    for(int i=0; i<4; i++){
        srand(time(NULL));
        int randnum=1 + rand() % 6;
        if(randnum < smallest_num){
            smallest_num=randnum;
            index_smallest=i;
        }
        nums[i]=randnum;
    }
    for(int j=0; j<4; j++){
        if(j==index_smallest) continue;/*skip the smallest number*/
        score+=nums[j]; /*add the rest.*/
    }
    return score;
}
int modifier(int score){
    if((score - 10) % 2 == 0){
        return (score - 10) / 2;
    }else{
        return (score - 10) / 2 - 1;/*score - 10 will always be -ve, since 6 < 10*/
    }
}

dnd_character_t make_dnd_character(void){
    dnd_character_t character={0};
    character.strength=ability();
    character.dexterity=ability();
    character.constitution=ability();
    character.intelligence=ability();
    character.wisdom=ability();
    character.charisma=ability();
    character.hitpoints= 10 + modifier(character.constitution);
    return character;
}