#include "pascals_triangle.h"
#include <stdlib.h>

uint8_t **create_triangle(size_t rows){
    if(rows == 0){
        uint8_t **res= malloc(1 * sizeof(*res));
        res[0]= calloc(1, sizeof(uint8_t));
        return res;
    }
    // Allocate an array of pointers to `uint8_t` type
    uint8_t **res= malloc(rows * sizeof(*res));
    if(!res) return NULL;

    // Allocate rows
    for(size_t i=0; i<rows; ++i){
        res[i]= calloc(rows, sizeof(uint8_t));
        // If allocation fails free all previously allocated rows
        if(!res[i]){
            free_triangle(res, i);
            return NULL;
        }
    }

    // Create Pascal's triangle
    for(size_t row=0; row<rows; ++row){
        for(size_t col=0; col<rows; ++col){
            if(row==0 && col == 0){
                res[row][col]=1;
                break;
            }
            if(col == 0){
                res[row][col]=1;
                continue;
            }
            res[row][col]= res[row - 1][col - 1] + res[row - 1][col]; 
        }
    }

    return res;
}

void free_triangle(uint8_t **triangle, size_t rows){
    for(size_t row=0; row<rows; ++row){
        free(triangle[row]);
    }
    free(triangle);
}