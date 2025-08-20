#include "high_scores.h"
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
    int32_t first=INT32_MIN, second=INT32_MIN, third=INT32_MIN;
    for(size_t i=0; i<scores_len; i++){
        if(scores[i]>first){
            third = second;
            second = first;
            first = scores[i];
        }else if(scores[i]>second){
            third= second;
            second= scores[i];
        }else if(scores[i] > third){
            third=scores[i];
        }
    }
    size_t count=0;
    if(first!=INT32_MIN) output[count++]=first;
    if(second!=INT32_MIN) output[count++]=second;
    if(third!=INT32_MIN) output[count++]=third;
    return count;
}