#include "clock.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int get_total_mins(int hour, int minute){
    int res=0;
    res+= hour * 60;

    res+= minute;
    /**If total minutes is -ve roll over, else return total mins */
    return res;
}

clock_t clock_create(int hour, int minute){
    clock_t clock;
    unsigned int clock_hr;
    unsigned int clock_min;
    int total_mins= get_total_mins(hour, minute);

    /* Get number of hours in total minutes */
    clock_hr= ((total_mins / 60) % 24 + 24) % 24;
    /*set the remaining minutes as clock minutes*/
    clock_min= total_mins % 60 < 0? total_mins % 60 + 60 : total_mins % 60;

     /*save the result in the required format*/
    if(clock_hr < 10 && clock_min < 10) sprintf(clock.text, "0%d:0%d", clock_hr, clock_min);
    else if(clock_hr < 10) sprintf(clock.text, "0%d:%d", clock_hr, clock_min);
    else if(clock_min < 10) sprintf(clock.text, "%d:0%d", clock_hr, clock_min);
    else sprintf(clock.text, "%d:%d", clock_hr, clock_min);
    return clock;
}

time_t extract_time(clock_t clock){
    time_t time;
    char hour[3]={'\0'};//store hour string
    char minute[3]={'\0'};//store minute string

    /*extract hour*/
    hour[0]= clock.text[0];
    hour[1]= clock.text[1];

    /*extract minute*/
    minute[0]= clock.text[3];
    minute[1]= clock.text[4];

    time.hour=atoi(hour);//convert string hour to int and store
    time.minute=atoi(minute); //convert string minute to int and store

    return time;
}

clock_t clock_add(clock_t clock, int minute_add){
    time_t time= extract_time(clock);
    time.minute+=minute_add;
    clock_t res= clock_create(time.hour, time.minute);
    return res;
}

clock_t clock_subtract(clock_t clock, int minute_subtract){
    time_t time= extract_time(clock);
    time.minute-=minute_subtract;
    clock_t res= clock_create(time.hour, time.minute);
    return res;
}

bool clock_is_equal(clock_t a, clock_t b){
    time_t a_time= extract_time(a);
    time_t b_time= extract_time(b);
    clock_t a_clock= clock_create(a_time.hour, a_time.minute);
    clock_t b_clock= clock_create(b_time.hour, b_time.minute);
    return strcmp(a_clock.text, b_clock.text) == 0;
}