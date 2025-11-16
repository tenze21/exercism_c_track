#include "clock.h"
#include "stdio.h"
#include "string.h"

#define DAY_MINUTES 1440
#define HOUR_MINUTES 60

static int normalize_minutes(int minutes){
    return ((minutes % DAY_MINUTES) + DAY_MINUTES) % DAY_MINUTES;
}

static void set_text(clock_t *clock, int total_minutes){
    unsigned int hours= total_minutes / 60;
    unsigned int minutes= total_minutes % 60;
    sprintf(clock->text, "%02d:%02d", hours, minutes);
}

static int minutes_from_text(char text[static 5]){
    int hour, minute;
    sscanf(text, "%d:%d", &hour, &minute);
    return hour * HOUR_MINUTES + minute;
}

clock_t clock_create(int hour, int minute){
    clock_t clock;
    set_text(&clock, normalize_minutes(hour * HOUR_MINUTES + minute));
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add){
    int total_minutes= minutes_from_text(clock.text) + minute_add;
    return clock_create(0, total_minutes);
}

clock_t clock_subtract(clock_t clock, int minute_subtract){
    int total_minutes= minutes_from_text(clock.text) - minute_subtract;
    return clock_create(0, total_minutes);
}

bool clock_is_equal(clock_t a, clock_t b){
    return(!strcmp(a.text, b.text));
}