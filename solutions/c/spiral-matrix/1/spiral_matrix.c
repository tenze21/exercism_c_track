#include "spiral_matrix.h"
#include "stdlib.h"

spiral_matrix_t spiral_matrix_create(int size){
    int **matrix= malloc(size * sizeof(int *));
    if(matrix==NULL) return (spiral_matrix_t){.size=0, .matrix=NULL};

    for(int i=0; i<size; i++){
        matrix[i]=malloc(size * sizeof(int));
        if(matrix[i]==NULL){
            for(int j=0; j<i; j++) free(matrix[j]);
            free(matrix);
            return (spiral_matrix_t){.size=0, .matrix=NULL};
        } 
    }
}