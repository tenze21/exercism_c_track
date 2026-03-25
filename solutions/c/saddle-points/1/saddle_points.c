#include "saddle_points.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Loop through each row, check if there's an element larger than the current one,
 * if there is a larger element, do nothing just continue to the next element,
 * if there isn't a larger element than the current one loop through the column and check it's the smalles element in column,
 * If it's smallest element in the column add it to saddle points. 
 */
saddle_points_t *saddle_points(size_t num_rows, size_t num_cols, uint8_t matrix[][num_cols]){
    saddle_points_t *saddle_point = malloc(sizeof(saddle_points_t) + num_rows * sizeof(saddle_point_t));
    saddle_point->count = 0;
    
    for(size_t i=0; i<num_rows; i++){
        for(size_t j=0; j<num_cols; j++){
            bool has_larger = false;
            for(size_t l=0; l<num_cols; l++){ 
                if(matrix[i][l] > matrix[i][j]){
                    has_larger= true;
                    break;
                }
            }
            if(has_larger) continue;
            
            bool is_smallest_in_col = false;
            for(size_t k=0; k<num_rows; k++){
                if(matrix[k][j] < matrix[i][j]) break;
                if(k+1 == num_rows) is_smallest_in_col= true;
            }
            
            if(is_smallest_in_col){
                saddle_point->points[saddle_point->count] = (saddle_point_t){i + 1, j + 1};
                saddle_point->count++;
            }
        }
    }
    
    return saddle_point;
}

void free_saddle_points(saddle_points_t *saddle_points){
    free(saddle_points);
}