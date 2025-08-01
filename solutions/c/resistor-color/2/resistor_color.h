#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H
// minimize code duplication; avoid duplicating the value definitions in both the enum and in the array.
#define COLORS BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum RESISTOR_BANDS { COLORS } resistor_band_t;

unsigned int color_code(resistor_band_t color);
resistor_band_t *colors(void);

#endif
