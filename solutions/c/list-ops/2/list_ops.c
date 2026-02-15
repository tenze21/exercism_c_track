#include "list_ops.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*IMPROVED BY REFERING  bobahop's SOLUTION.*/
static list_t *alloc_list(size_t length){
    list_t *list= calloc(1, sizeof(list_t) + (length * sizeof(list_element_t)));
    if(!list) return NULL;
    list->length=length; return list;
}

list_t *new_list(size_t length, list_element_t elements[]){
    list_t *new_list=alloc_list(length);
    if(!new_list) return NULL;
    if(new_list->length>0) memcpy(new_list->elements, elements,  length * sizeof(list_element_t));
    return new_list;
}

list_t *append_list(list_t *list1, list_t *list2){
    if(!list1 || !list2) return NULL;
    
    list_t *combined_list=alloc_list(list1->length + list2->length);
    if(!combined_list) return NULL;
    
    if(list1->length>0) memcpy(combined_list->elements, list1->elements, list1->length * sizeof(list_element_t));
    if(list2->length>0) memcpy(combined_list->elements + list1->length, list2->elements, list2->length * sizeof(list_element_t));
    
    return combined_list;
}

/*
 * Initially didn't know that you could reallocate with a memory with a new size.
 */
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    if(!list) return NULL;
    
    list_t *filtered_list=alloc_list(list->length);
    if(!filtered_list) return NULL;
    unsigned int nbr_filtered=0;
    for(size_t i=0; i<list->length; i++){
        if((*filter)(list->elements[i])){
            filtered_list->elements[nbr_filtered]=list->elements[i];
            nbr_filtered++;
        } 
    }
    filtered_list=realloc(filtered_list, sizeof(list_t) + (nbr_filtered * sizeof(list_element_t)));
    filtered_list->length=nbr_filtered;
    return filtered_list;
}

size_t length_list(list_t *list){
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    if(!list) return NULL;
    
    list_t *mapped_list=alloc_list(list->length);
    if(!mapped_list) return NULL;
    
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
    
    list_t *reversed_list=alloc_list(list->length);
    if(!reversed_list) return NULL;
    
    for(size_t i=0; i<list->length; i++)
        reversed_list->elements[i]=list->elements[(list->length - 1)-i];
    
    return reversed_list;
}

void delete_list(list_t *list){
    if(list) free(list);
}