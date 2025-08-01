#include "darts.h"

float throw_radius(coordinate_t throw){/*calculate the distance of the dart from the center(annulus).*/
    return throw.x * throw.x + throw.y * throw.y; 
    /*
    using pythagorean theorem we can get the distance of a cartesian point using the equation d^2=(x2 - x1)^2 + (y2 - y1)^2,
    since we are finding the distance from the center(0, 0) where we can write the equation as d^2=x2^2 + y2^2 where x2 and y2 are cartesian coordinates of the dart on the target.
    */
}

uint8_t score(coordinate_t coordinates){
    const float INNER_CIRCLE= 1;
    const float MIDDLE_CIRCLE= 5;
    const float OUTER_CIRCLE= 10;

    float distance_square= throw_radius(coordinates);

    if(distance_square <= INNER_CIRCLE * INNER_CIRCLE) return 10;
    if(distance_square <= MIDDLE_CIRCLE * MIDDLE_CIRCLE) return 5;
    if(distance_square <= OUTER_CIRCLE * OUTER_CIRCLE) return 1;

    return 0;
}