#include "spiral_matrix.h"
#include "stdlib.h"
#include "stdbool.h"

//FROM @Dawn99's solution
static spiral_matrix_t *spiral_matrix_allocate(int size){
    spiral_matrix_t *sm=malloc(sizeof(*sm));//sizeof(*sm)==sizeof(spiral_matrix_t) since sm is a pointer to spiral_matrix_t and *sm dereferences the pointer.
    if(!sm) goto allocation_failure;

    sm->size=size;
    if(size == 0){
        sm->matrix=NULL;
        return sm;
    }

    sm->matrix=malloc(size * sizeof(*sm->matrix));//*sm->matrix == int *(pointer to int type), since sm->matrix is of type int ** 
    if(!sm->matrix) goto allocation_failure;

    int *matrix=malloc(size * size * sizeof(*matrix));//*matrix == int, allocate a contigous memory block for the entire 2D array.
    if(!matrix) goto allocation_failure;

    for(int i=0; i<size; i++)
        sm->matrix[i]= &matrix[i * size];//make each row pointer point to the appropraite offset.

    return sm;
    allocation_failure:
        spiral_matrix_destroy(sm);
        return NULL;
}

void spiral_matrix_destroy(spiral_matrix_t *sm){
    if(sm && sm->matrix){
        free(sm->matrix[0]);
        free(sm->matrix);
    }
    free(sm);
}

spiral_matrix_t *spiral_matrix_create(int size){
    if(size < 0) return NULL;
    spiral_matrix_t *sm=spiral_matrix_allocate(size);
    if(!sm || sm->size == 0) return sm;

    int top=0;
    int left=0;
    int bottom=sm->size - 1;
    int right=sm->size - 1;
    int value=1;
    int max_value=size * size;
    while(true){
        for(int i=left; i<=right; i++)//left to right
            sm->matrix[top][i]=value++;
        if(value > max_value) break;
        top++;

        for(int j=top; j<=bottom; j++)//top to bottom
            sm->matrix[j][right]=value++;
        right--;

        for(int i=right; i>=left; i--)//right to left
            sm->matrix[bottom][i]=value++;
        if(value>max_value) break;
        bottom--;

        for(int j=bottom; j>=top; j--)//bottom to top
            sm->matrix[j][left]=value++;
        left++; 
    }

    return sm;
}