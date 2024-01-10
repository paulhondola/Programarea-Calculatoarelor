#include <stdio.h>
#include <stdlib.h>
#include "xbee.h"

FILE *open_file(const char *filename, const char *mode)
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

void check_end_of_file(FILE *file, uint64_t counter)
{  
    if(feof(file) != 0)
    {
        fprintf(stderr, "Successful reads, %llu \nEnd of file\n", counter);
    }
}

void print_to_file(const char *file_path, const FRAME_DATA *frame_data)
{
    FILE *log_file = open_file(file_path, "a");
    fprintf(log_file, "ID: %llu\n", frame_data->id);
    fprintf(log_file, "Start of frame: %02X\n", frame_data->start_of_frame);
    fprintf(log_file, "Length: %02X\n", frame_data->length);
    fprintf(log_file, "Buffer: ");
    for(uint8_t i = 0; i < frame_data->length; i++)
    {
        fprintf(log_file, "%02X ", frame_data->buffer[i]);
    }
    fprintf(log_file, "\n");
    fprintf(log_file, "Check sum: %02X\n", frame_data->check_sum);
    fprintf(log_file, "Check sum calculated: %02X\n", frame_data->calculated_check_sum);

    fprintf(log_file, "\n");

    close_file(log_file);
}
