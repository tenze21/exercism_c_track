#include "triangle.h"

bool is_triangle(triangle_t dimensions){
    if(dimensions.a == 0 || dimensions.b == 0 || dimensions.c == 0) return false;
    else if((dimensions.a + dimensions.b < dimensions.c) || (dimensions.a + dimensions.c < dimensions.b) || (dimensions.b + dimensions.c < dimensions.a)) return false;
    else return true;
}

bool is_equilateral(triangle_t triangle){
    if(!is_triangle(triangle)) return false;
    if(triangle.a == triangle.b && triangle.b == triangle.c) return true;
    return false;
}

bool is_isosceles(triangle_t triangle){
    if(!is_triangle(triangle)) return false;
    if(triangle.a == triangle.b || triangle.a == triangle.c || triangle.b == triangle.c)return true;
    return false;
}

bool is_scalene(triangle_t triangle){
    if(!is_triangle(triangle)) return false;
    if(triangle.a != triangle.b && triangle.b != triangle.c && triangle.a != triangle.c) return true;
    return false; 
}