#include <stdio.h>
#include <stdlib.h>
#include "xbee.h"

// 7E - 1 byte
// LEN - 1 byte
// DATA - LEN bytes
// CHECKSUM - 2 byte

void calculate_check_sum(FRAME_DATA *frame_data)
{
    frame_data->calculated_check_sum = 0;
    for(uint8_t i = 0; i < frame_data->length; i++)
    {
        frame_data->calculated_check_sum += frame_data->buffer[i];
    }
}


FRAME_DATA *input_frame_data(const char *filename, uint64_t *size)
{
    FILE *file = open_file(filename, "rb");
    
    FRAME_DATA *frame_data = malloc(100000 * sizeof(FRAME_DATA));

    if(frame_data == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    uint64_t counter = 0;
    
    FRAME_DATA input;

    while(1)
    {
        input.id = counter;

        if(fread(&input.start_of_frame, sizeof(uint8_t), 1, file) != 1)
        {
            check_end_of_file(file, counter);
            break;
        }

        if(input.start_of_frame != START_OF_FRAME)
        {
            check_end_of_file(file, counter);
            break;
        }

        if(fread(&input.length, sizeof(uint8_t), 1, file) != 1)
        {
            check_end_of_file(file, counter);
            break;
        }

        if(input.length > BUFFER)
        {
            check_end_of_file(file, counter);
            break;
        }

        if(fread(input.buffer, sizeof(uint8_t), input.length, file) != input.length)
        {
            check_end_of_file(file, counter);
            break;
        }

        if(fread(&input.check_sum, sizeof(uint16_t), 1, file) != 1)
        {
            check_end_of_file(file, counter);
            break;
        }

        calculate_check_sum(&input);

        frame_data[counter++] = input;
    }

    *size = counter;

    close_file(file);

    return frame_data;
}


void print_logs(const char *file_path_good, const char *file_path_bad, const FRAME_DATA *frame_data, const uint64_t size)
{
    for(uint64_t i = 0; i < size; i++)
    {
        if(frame_data[i].start_of_frame == START_OF_FRAME && frame_data[i].check_sum == frame_data[i].calculated_check_sum)
        {
            print_to_file(file_path_good, &frame_data[i]);
        }
        else
        {
            print_to_file(file_path_bad, &frame_data[i]);
        }
    }
}
