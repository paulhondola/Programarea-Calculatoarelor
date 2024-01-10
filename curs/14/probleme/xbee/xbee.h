#ifndef __XBEE_H
#define __XBEE_H

#include <stdio.h>
#include <stdint.h>

#define START_OF_FRAME 0x7E
#define BUFFER 255

typedef struct 
{
    uint64_t id;
    uint8_t start_of_frame;
    uint8_t length;
    uint8_t buffer[BUFFER];
    uint16_t check_sum;
    uint16_t calculated_check_sum;

} FRAME_DATA;


FILE *open_file(const char *file_name, const char *mode);

void close_file(FILE *file);

FRAME_DATA *input_frame_data(const char *filename, uint64_t *size);

void check_end_of_file(FILE *file, uint64_t counter);

void print_to_file(const char *file_path, const FRAME_DATA *frame_data);

#endif
