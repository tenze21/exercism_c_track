#include "high_scores.h"
#define MAX_TOP_SCORES 3

int32_t latest(const int32_t *scores, size_t scores_len){/*returns the players latest score*/
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){/*returns player's the highest score.*/
    int32_t highest= 0;
    for(int i=0; i<(int)scores_len; i++){
        if(scores[i] > highest){
            highest=scores[i];
        }
    }
    return highest;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    size_t count=0;/*Keeps track of the number of elements in the output.*/
    for(size_t i=0; i<scores_len; i++){
        int score= scores[i];
        if(count<MAX_TOP_SCORES){/*if output has less than 3 elements accept it automatically.*/
            count++;
        }else if(score<=output[count-1]){/*else accept only if score is greater than the last element in output(the lowest score)*/
            continue;
        }

        int k=count-1;
        while(k > 0 && score > output[k-1]){/*shift and place the scores in their correct position in the output array.*/
            output[k]= output[k - 1];
            --k;
        }
        output[k]=score; 
    }
    return count;
}