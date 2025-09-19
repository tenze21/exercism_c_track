#include "gigasecond.h"
#define ONE_GIGASECOND 1000000000

void gigasecond(time_t input, char *output, size_t size){
    time_t time_after_gigasecond= input + ONE_GIGASECOND;
    struct tm *utc_time= gmtime(&time_after_gigasecond);
    /*write a formated date-time string to the provided character array(output)*/
    /*
    output - buffer to write the output to
    size - size of buffer
    "%Y-%m-%d %H:%M:%S" - format
    utc_time - `struct tm` type to get the date-time data 
    */
    strftime(output, size, "%Y-%m-%d %H:%M:%S", utc_time);
}