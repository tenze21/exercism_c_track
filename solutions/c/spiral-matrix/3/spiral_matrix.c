#include "spiral_matrix.h"
#include "stdlib.h"
#include "stdbool.h"

//FROM @Dawn99's & @stackcats's solution
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

    int *matrix=calloc(size * size, sizeof(*matrix));//*matrix == int, allocate a contigous memory block for the entire 2D array.
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
    
    unsigned int x=0;
    unsigned int y=0;
    int dx=0;//0: same row, 1: increment row, -1: decrement row
    int dy=1;//0: same column, 1: increment column, -1: decrement column
    int max_value=size * size;
    for(int i=1; i<=max_value; i++){
        sm->matrix[x][y]=i;
        int nx=x+dx;
        int ny=y+dy;
        if(nx < 0 || nx >= size || ny < 0 || ny >= size || sm->matrix[nx][ny]>0){//change direction
            int t=-dx;
            dx=dy;
            dy=t;
        }
        x+=dx;
        y+=dy;  
    }
    return sm;
}