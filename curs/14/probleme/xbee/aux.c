#include <stdio.h>
#include <stdlib.h>
#include "xbee.h"

#define CHUNK 256

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror(filename);
        exit(1);
    }

    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) != 0)
    {
        printf("Error closing file\n");
        exit(1);
    }
}

// SOF - 7E - 1 byte
// LEN - 1 byte
// DATA - LEN bytes
// CHECKSUM - 2 byte

/*
    uint8_t id;
    uint8_t start_of_frame;
    uint8_t length;
    uint8_t buffer[BUFFER];
    uint16_t check_sum;
    uint16_t calculated_check_sum;
*/

uint8_t check_frame_sum(FRAME_DATA *frame_data)
{
    frame_data->calculated_check_sum = 0;

    for(uint8_t i = 0; i < frame_data->length; i++)
    {
        frame_data->calculated_check_sum += frame_data->buffer[i];
    }

    return frame_data->calculated_check_sum == frame_data->check_sum;
}

FRAME_DATA *input_frame_data(char *filename, uint64_t *size)
{
    FILE *file = open_file(filename, "rb");
    FILE *log_file = open_file("logs.txt", "w");

    FRAME_DATA input_frame;
    FRAME_DATA *frame_data = NULL;

    uint64_t counter = 0;

    uint8_t used_size = 0;
    uint8_t allocated_size = 0;
    

    while(1)
    {
        if(feof(file) != 0)
        {
            fprintf(log_file, "End of file\n");
            break;
        }

        input_frame.id = counter;

        if(fread(&input_frame.start_of_frame, sizeof(uint8_t), 1, file) != 1)
        {
            fprintf(log_file, "Error reading start of frame\n");
            break;
        }

        if(input_frame.start_of_frame != START_OF_FRAME)
        {
            fprintf(log_file, "Invalid start frame\n");
            break;
        }

        if(fread(&input_frame.length, sizeof(uint8_t), 1, file) != 1)
        {
            fprintf(log_file, "Error reading length\n");
            break;
        }

        if(input_frame.length > BUFFER)
        {
            fprintf(log_file, "Invalid length\n");
            break;
        }

        if(fread(input_frame.buffer, sizeof(uint8_t), input_frame.length, file) != input_frame.length)
        {
            fprintf(log_file, "Error reading buffer\n");
            break;
        }

        if(fread(&input_frame.check_sum, sizeof(uint16_t), 1, file) != 1)
        {
            fprintf(log_file, "Error reading checksum\n");
            break;
        }

        if(used_size == allocated_size)
        {
            allocated_size += CHUNK;
            frame_data = realloc(frame_data, allocated_size * sizeof(FRAME_DATA));
            if(frame_data == NULL)
            {
                fprintf(log_file, "Error reallocating memory\n");
                exit(-1);
            }
        }

        frame_data[used_size++] = input_frame;
    }


    *size = used_size;

    close_file(file);

    return frame_data;
}

