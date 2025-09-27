#include "luhn.h"
bool luhn(const char *num){
    int len = strlen(num);
    if (len <= 1)
        return false;
    int nums[len];
    int numslen=0;
    int sum = 0;
    for (int i = 0; i < len; i++){/*convert all the digits to int and store them in nums array while keeping track of the number of digits.*/
        if ((*num != ' ') && (*num > '9' || *num < '0')) return false;
        if(*num <= '9' && *num >='0'){ 
            nums[numslen] = *num - '0';
            numslen++;
        }
        num++;
    }

    if(numslen <= 1) return false;/*If there is a single digit with one or more spaces*/

    for (int j = 0; j < numslen; j++){
        if (numslen % 2 == 0 && j % 2 == 0)/*if there are even number of digits start doubling every second digit starting from the leftmost digit*/
            nums[j] = nums[j] * 2 > 9 ? nums[j] * 2 - 9 : nums[j] * 2;
        else if (numslen % 2 != 0 && j % 2 != 0)/*If there are odd number of digits start doubling every second digit starting with the second digit from the left*/
            nums[j] = nums[j] * 2 > 9 ? nums[j] * 2 - 9 : nums[j] * 2;
        sum += nums[j];/*After modifying the values accumulate the sum.*/
    }
    return sum % 10 == 0;
}