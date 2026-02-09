#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include "stdint.h"
#include "stdlib.h"
#include "errno.h"

typedef int buffer_value_t;
typedef int16_t buffer_status_t;

typedef struct circular_buffer{
    buffer_value_t *buff;
    size_t buffsize;/*total buffer size*/
    unsigned int read_offset;/*current read position*/
    unsigned int write_offset;/*current write position*/
    size_t element_count;/*available buffer space.*/
} circular_buffer_t;

/*allocate and return a pointer to the buffer of "capacity" size.*/
circular_buffer_t *new_circular_buffer(size_t capacity);
/*free space allocated to the circular buffer.*/
void delete_buffer(circular_buffer_t *buffer);
/*read values from the circular buffer, writes the read values to "out" and returns a operation sucess or failure status.*/
buffer_status_t read(circular_buffer_t *buffer, buffer_value_t *out);
/*write values to the circular buffer, returns a operation sucess or failure status.*/
buffer_status_t write(circular_buffer_t *buffer, buffer_value_t val);
/*overwrite the value at the current buffer pointer with "val", returns a operation sucess or failure status.*/
buffer_status_t overwrite(circular_buffer_t *buffer, buffer_value_t val);
/*reset read and write offsets.*/
void clear_buffer(circular_buffer_t *buffer);
#endif
