#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]){
    list_t *new_list=calloc(1, sizeof(list_t) + (length * sizeof(list_element_t)));
    if(!new_list) return NULL;
    
    new_list->length=length;
    for(size_t i=0; i<length; i++)
        new_list->elements[i]= elements[i];
    
    return new_list;
}

list_t *append_list(list_t *list1, list_t *list2){
    if(!list1 || !list2) return NULL;
    
    list_t *combined_list=calloc(1, sizeof(list_t) + ((list1->length + list2->length)*sizeof(list_element_t)));
    if(!combined_list) return NULL;
    combined_list->length=list1->length + list2->length;
    
    for(size_t i=0; i<list1->length; i++)
        combined_list->elements[i]=list1->elements[i];
    
    for(size_t j=0; j<list2->length; j++)
        combined_list->elements[list1->length + j]=list2->elements[j];
    
    return combined_list;
}

/*
 * Could be made space efficient by first running the filter function and determining the 
 * number number of elements that would remain, then just allocate that much space for `filtered_list`
 * but the cost would be longer execution time due to more operations.
 */
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    if(!list) return NULL;
    
    list_t *filtered_list=calloc(1, sizeof(list_t) + (list->length * sizeof(list_element_t)));
    if(!filtered_list) return NULL;
    unsigned int nbr_filtered=0;
    for(size_t i=0; i<list->length; i++){
        if((*filter)(list->elements[i])){
            filtered_list->elements[nbr_filtered]=list->elements[i];
            nbr_filtered++;
        }
    }
    filtered_list->length=nbr_filtered;
    return filtered_list;
}

size_t length_list(list_t *list){
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    if(!list) return NULL;
    
    list_t *mapped_list=calloc(1, sizeof(list_t) + (list->length * sizeof(list_element_t)));
    if(!mapped_list) return NULL;
    mapped_list->length=list->length;
    
    for(size_t i=0; i<list->length; i++)
        mapped_list->elements[i]=(*map)(list->elements[i]);
    
    return mapped_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)){
    if(!list) return 0;
    
    for(size_t i=0; i<list->length; i++)
        initial=(*foldl)(list->elements[i], initial);
    return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t)){
    if(!list) return 0;
    
    int i=list->length-1;
    while(i>=0){
        initial=(*foldr)(list->elements[i], initial);
        i--;
    }
    return initial;
}

list_t *reverse_list(list_t *list){
    if(!list) return NULL;
    
    list_t *reversed_list=calloc(1, sizeof(list_t) + (list->length * sizeof(list_element_t)));
    if(!reversed_list) return NULL;
    reversed_list->length=list->length;
    
    for(size_t i=0; i<list->length; i++)
        reversed_list->elements[i]=list->elements[(list->length - 1)-i];
    
    return reversed_list;
}

void delete_list(list_t *list){
    if(list){free(list); list=NULL;}
}