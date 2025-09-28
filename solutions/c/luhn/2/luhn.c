#include "luhn.h"
bool luhn(const char *num){
    int sum=0, pos=0;
    int idx= strlen(num) - 1;/*last element is at index length of array - 1*/
    for(;idx > -1; idx--){/*go till 0th index*/
        char c= num[idx];
        if(c==' ') continue;
        if(c < '0' || c > '9') return false;
        int nbr= c - '0';/*convert char to int*/
        pos++;/*increment pos to set it to the first digit from right*/
        if(pos & 1) sum += nbr;/*if it not the second digit from right directly add it to sum. 1 & 1=1, 2 & 1=0, 3 & 1=1*/
        else sum += (nbr * 2) - ((nbr > 4) * 9);/*only for numbers > 4, number * 2 > 9. if nbr > 4 -> 1 * 9 = 9; else 0 * 9=0*/
    }
    return pos > 1 && !(sum % 10);
}