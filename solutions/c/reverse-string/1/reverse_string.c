#include "reverse_string.h"
#include "string.h"
#include "stdlib.h"

char *reverse(const char *value){
    size_t len= strlen(value);
    char *res= (char *)malloc(len + 1);

    for(int i=len - 1, j=0; i>=0; i--, j++) res[j]= value[i];

    res[len]='\0';
    return res;
}