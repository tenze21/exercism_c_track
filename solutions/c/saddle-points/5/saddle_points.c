#include "saddle_points.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
    returns the samller of a and b.
*/
static uint8_t min_uint8t(uint8_t a, uint8_t b){
    return a > b? b : a;
}

/*
    returns the larger of a and b.
*/
static uint8_t max_uint8t(uint8_t a, uint8_t b){
    return a > b? a : b;
}

/*
 Reduced algorithms time complexity to O(num_rows * num_cols) by using an auxilary space of O(num_cols)
 to precalculate the smallest elements in a column. 
*/
saddle_points_t *saddle_points(size_t num_rows, size_t num_cols, uint8_t matrix[][num_cols]){
    /* A matrix will have `num_rows * num_cols` saddle points at the max */
    saddle_points_t *result = malloc(sizeof(saddle_points_t) + num_rows * num_cols * sizeof(saddle_point_t));
    if(result == NULL) return NULL;
    result->count = 0;

    /* precalculate and store the smallest elements in each column (line: 31 - 42) */
    uint8_t *min_col_values= malloc(num_cols * sizeof(*min_col_values));
    if(min_col_values == NULL) return NULL;

    /* Assume elements in the first row to be the smallest in their respective rows */
    memcpy(min_col_values, matrix[0], sizeof(matrix[0]));

    for(size_t row=1; row < num_rows; row++){
        for(size_t col=0; col < num_cols; col++){
            min_col_values[col] = min_uint8t(min_col_values[col], matrix[row][col]);
        }
    }

    /* iterate the entire matrix and check if an element is a saddle point(i.e., largest in row and samllest in column) */
    for(size_t row=0; row<num_rows; row++){

        /* In each row record the largest element */
        uint8_t max_row_value = matrix[row][0];
        for(size_t col=1; col<num_cols; col++)
            max_row_value = max_uint8t(max_row_value, matrix[row][col]);

        for(size_t col=0; col<num_cols; col++){
            if(matrix[row][col] == min_col_values[col] && matrix[row][col] == max_row_value){
                result->points[result->count] = (saddle_point_t){.row = row + 1, .column = col + 1};
                result->count++;
            }
        }
    }
    
    saddle_points_t *tmp= realloc(result, sizeof(saddle_points_t) + result->count * sizeof(saddle_point_t));
    if(tmp){
        result = tmp;
    }

    free(min_col_values);
     
    return result;
}

void free_saddle_points(saddle_points_t *saddle_points){
    free(saddle_points);
}