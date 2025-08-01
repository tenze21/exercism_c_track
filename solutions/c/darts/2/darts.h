#ifndef DARTS_H
#define DARTS_H
#include <stdint.h>
typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t coordinates);
float throw_radius(coordinate_t throw);

#endif
