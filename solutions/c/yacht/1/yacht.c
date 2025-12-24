#include "yacht.h"
#define NUMBER_OF_DICE (5)

static unsigned int full_house_score(dice_t dice){
    unsigned int faces[7]={0};
    unsigned int score=0;
    for(int i=0; i<NUMBER_OF_DICE; i++){
        faces[dice.faces[i]]++;
        score+= dice.faces[i];
    }

    unsigned int flag_2=0;
    unsigned int flag_3=0;
    for(int i=1; i<7; i++){
        if(faces[i]==2) flag_2=1;
        if(faces[i]==3) flag_3=1;
    }

    return flag_2 && flag_3? score : 0;
}

static unsigned int four_of_a_kind_score(dice_t dice){
    unsigned int faces[7]={0};
    for(int i=0; i<NUMBER_OF_DICE; i++)
        faces[dice.faces[i]]++;
    
    unsigned int face=0;
    for(int i=1; i<7; i++)
        if(faces[i]>=4) face=i;  
    
    return face? 4*face : 0;
}

static unsigned int little_straight_score(dice_t dice){
    unsigned int faces[7]={0};
    for(int i=0; i<NUMBER_OF_DICE; i++)
        faces[dice.faces[i]]=1;
    
    for(int i=1; i<6; i++)
        if(faces[i]==0) return 0;
    
    return 30;
}

static unsigned int big_straight_score(dice_t dice){
    unsigned int faces[7]={0};
    for(int i=0; i<NUMBER_OF_DICE; i++)
        faces[dice.faces[i]]=1;
    
    for(int i=2; i<7; i++)
        if(faces[i]==0) return 0;
    
    return 30;
}

static unsigned int yacht_score(dice_t dice){
    for(int i=1; i<NUMBER_OF_DICE; i++)
        if(dice.faces[i]!=dice.faces[0]) return 0;
    
    return 50;
}

static unsigned int other_scores(dice_t dice, category_t category){
    if(category == CHOICE){//found it better to write it here, than using a seperate function.
        unsigned int score=0;
        for(int i=0; i<NUMBER_OF_DICE; i++) score+=dice.faces[i];
        return score;
    }

    unsigned int count=0;
    for(int i=0; i<NUMBER_OF_DICE; i++)
        if(dice.faces[i]==((int)category + 1)) count++;
    
    return (category + 1) * count;
}

int score(dice_t dice, category_t category){
    if(category <= SIXES) return other_scores(dice, category);
    else if(category == FULL_HOUSE) return full_house_score(dice);
    else if(category == FOUR_OF_A_KIND) return four_of_a_kind_score(dice);
    else if(category == LITTLE_STRAIGHT) return little_straight_score(dice);
    else if(category == BIG_STRAIGHT) return big_straight_score(dice);
    else if(category == CHOICE) return other_scores(dice, category);
    else if(category == YACHT) return yacht_score(dice);
    else return -1;//Invalid category
}