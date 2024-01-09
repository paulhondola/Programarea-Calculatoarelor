#ifndef __XBEE_H
#define __XBEE_H

#include <stdio.h>
#include <stdint.h>

#define START_OF_FRAME 0x7E
#define BUFFER 100

FILE *open_file(char *filename, char *mode);

void close_file(FILE *file);

typedef struct 
{
    uint64_t id;
    uint8_t start_of_frame;
    uint8_t length;
    uint8_t buffer[BUFFER];
    uint16_t check_sum;
    uint16_t calculated_check_sum;

} FRAME_DATA;

FRAME_DATA *input_frame_data(char *filename, uint64_t *size);

#endif