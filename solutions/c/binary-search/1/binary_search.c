#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
    int left=0;
    int right=length - 1;
    while(left<=right){
        int mid= (left + right) / 2;
        if(value == arr[mid]){
            return &arr[mid];
        }else if(value < arr[mid]){
            right= mid - 1;
        }else{
            left= mid + 1;
        }
    }
    return NULL;
}