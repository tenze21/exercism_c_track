#include "sublist.h"
#include "stdbool.h"

typedef struct{
    int *list;
    size_t element_count;
}list_detail_t;

static bool compare_list(list_detail_t larger_list, list_detail_t smaller_list){//check whether the larger list contains the smaller list.
    unsigned int is_sublist=false;  
    for(size_t i=0; i<=larger_list.element_count-smaller_list.element_count; i++){
        unsigned int is_contained=true;
        for(size_t j=0, k=i; j<smaller_list.element_count; j++){
            if(larger_list.list[k]!=smaller_list.list[j] || k++>=larger_list.element_count){
                is_contained=false;
                break;
            }
        }
        if(is_contained){
            is_sublist=true;
            break;
        }
    }
    return is_sublist;
}

static bool is_equal(list_detail_t list1, list_detail_t list2){
    for(size_t i=0; i<list1.element_count; i++)
        if(list1.list[i]!=list2.list[i]) return false;

    return true;
}


comparison_result_t check_lists(int *list_to_compare, int *base_list, size_t list_to_compare_element_count,size_t base_list_element_count){
    list_detail_t smaller_list;
    list_detail_t larger_list;
    if(list_to_compare_element_count>base_list_element_count){
        smaller_list.list=base_list;
        smaller_list.element_count=base_list_element_count;
        larger_list.list=list_to_compare;
        larger_list.element_count=list_to_compare_element_count;
    }else{//doesn't matter if it's equal
        larger_list.list=base_list;
        larger_list.element_count=base_list_element_count;
        smaller_list.list=list_to_compare;
        smaller_list.element_count=list_to_compare_element_count;
    }

    unsigned int compare_res= compare_list(larger_list, smaller_list);
    if(list_to_compare_element_count>base_list_element_count && compare_res) return SUPERLIST;
    else if(list_to_compare_element_count<base_list_element_count && compare_res) return SUBLIST;
    else if(list_to_compare_element_count == base_list_element_count && is_equal(larger_list, smaller_list)) return EQUAL;
    else return UNEQUAL;
}