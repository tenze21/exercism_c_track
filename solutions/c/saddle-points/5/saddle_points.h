#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H
#include <stddef.h>
#include <stdint.h>

typedef struct{
    uint8_t row;
    uint8_t column; 
}saddle_point_t;

typedef struct{
    size_t count;
    saddle_point_t points[];
}saddle_points_t;

/*
    Get the saddle points in a matrix(i.e., elements that are the largest in their row and samllest in their column)
*/
saddle_points_t *saddle_points(size_t num_rows, size_t num_cols, uint8_t matrix[][num_cols]);
void free_saddle_points(saddle_points_t *saddle_points);

#endif
