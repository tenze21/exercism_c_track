#include "pascals_triangle.h"
#include <stdlib.h>

uint8_t **create_triangle(size_t rows){
    if(rows == 0){
        uint8_t **res= create_triangle(1);
        res[0][0]= 0;
        return res;
    }

    // Allocate an array of pointers to `uint8_t` type
    uint8_t **res= malloc(rows * sizeof(*res));
    if(!res) return NULL;

    size_t cols= rows;
    // Create Pascal's triangle
    for(size_t row=0; row<rows; ++row){
        res[row]= calloc(rows, sizeof(uint8_t));
        // If allocation fails free all previously allocated rows
        if(!res[row]){
            free_triangle(res, row);
            return NULL;
        }

        for(size_t col=0; col<cols; ++col){
            if(row==0 && col == 0){
                res[row][col]=1;
                break;
            }
            if(col == 0) res[row][col]=1;
            else res[row][col]= res[row - 1][col - 1] + res[row - 1][col]; 
        }
    }

    return res;
}

void free_triangle(uint8_t **triangle, size_t rows){
    for(size_t row=0; row<rows; ++row){
        free(triangle[row]);
        triangle[row]= NULL;
    }
    free(triangle);
    triangle= NULL;
}