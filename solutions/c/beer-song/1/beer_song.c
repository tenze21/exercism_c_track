#include "beer_song.h"
#include "stdio.h" 
#define MAX_LINE_LENGTH (1024)

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    uint8_t bottles_left= start_bottles;//declared a seperated variable to prevent context confusions.

    while(take_down > 0){
        if(bottles_left==1){
            snprintf(*song, MAX_LINE_LENGTH + 1, "1 bottle of beer on the wall, 1 bottle of beer.");//directly put in the number so that time isn't wasted accessing bottles_left value from memory.
            song++;
            snprintf(*song, MAX_LINE_LENGTH + 1, "Take it down and pass it around, no more bottles of beer on the wall.");
            song++;
        }else if(bottles_left== 0){//reset number of bottles and continue
            snprintf(*song, MAX_LINE_LENGTH + 1, "No more bottles of beer on the wall, no more bottles of beer.");
            song++;
            snprintf(*song, MAX_LINE_LENGTH + 1, "Go to the store and buy some more, 99 bottles of beer on the wall.");
            song++;
            bottles_left=99;
            take_down--;
            continue;
        }else{
            snprintf(*song, MAX_LINE_LENGTH + 1, "%d bottles of beer on the wall, %d bottles of beer.", bottles_left, bottles_left);
            song++;
            //need to handle plural and singular forms of bottle
            if(bottles_left == 2) snprintf(*song, MAX_LINE_LENGTH + 1, "Take one down and pass it around, 1 bottle of beer on the wall.");
            else snprintf(*song, MAX_LINE_LENGTH + 1, "Take one down and pass it around, %d bottles of beer on the wall.", bottles_left-1);
            song++;
        }
        bottles_left--;
        take_down--;

        if(take_down != 0){//add the empty character after each verse, if there are more verse(s).
            **song='\0';
            song++;
        }
    }
}