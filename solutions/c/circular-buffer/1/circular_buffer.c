#include "circular_buffer.h"
#include "stdio.h"

circular_buffer_t *new_circular_buffer(size_t capacity){
    circular_buffer_t *buff= malloc(sizeof(*buff));
    if(!buff) goto allocation_failure;
    buff->buffsize=capacity;
    buff->read_offset=0;
    buff->write_offset=0;
    buff->element_count=0;

    buff->buff=calloc(capacity, sizeof(*buff->buff));
    if(!buff->buff) goto allocation_failure;

    return buff;

    allocation_failure:
        delete_buffer(buff);
        return NULL;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t val){
    if(!buffer) return EXIT_FAILURE;

    // printf("%zu\n", buffer->element_count);
    if(buffer->element_count>=buffer->buffsize){/*check if there is space in buffer.*/
        errno=ENOBUFS;
        return EXIT_FAILURE;
    }
    buffer->buff[buffer->write_offset]=val;
    buffer->write_offset=(buffer->write_offset + 1)%buffer->buffsize;
    buffer->element_count++;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t val){
    if(!buffer) return EXIT_FAILURE;
    buffer->buff[buffer->write_offset]=val;
    buffer->write_offset=(buffer->write_offset + 1)%buffer->buffsize;
    if(buffer->element_count==buffer->buffsize)/*On overwrite the oldest item in the buffer becomes the element next to the overwritten one.*/
        buffer->read_offset=(buffer->read_offset + 1)%buffer->buffsize;

    if(buffer->element_count < buffer->buffsize) buffer->element_count++;/*don't increment `buffer.element_count` if buffer is full.*/
    
    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *out){
    if(!buffer) return EXIT_FAILURE;

    if(buffer->element_count==0){
        errno=ENODATA;
        return EXIT_FAILURE;
    }
    *out=buffer->buff[buffer->read_offset];
    buffer->read_offset=(buffer->read_offset + 1) % buffer->buffsize;
    buffer->element_count--;
    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer){
    buffer->element_count=0;
    buffer->read_offset=0;
    buffer->write_offset=0;
}

void delete_buffer(circular_buffer_t *buff){
    if(buff && buff->buff) free(buff->buff);
    free(buff);
}