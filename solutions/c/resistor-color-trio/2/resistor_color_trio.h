#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>
#include <math.h>
#define COLORS BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE


typedef struct{
    uint16_t value;
    const char *unit;
}resistor_value_t;

typedef enum RESISTOR_BANDS{COLORS} resistor_band_t;

resistor_value_t color_code(resistor_band_t colors[]);

#endif
