// 7E - 1 byte
// LEN - 1 byte
// DATA - LEN bytes
// CHECKSUM - 2 byte

// scriu frame-urile bune in fisierul xbee_good.txt
// scriu frame-urile gresite in fisierul xbee_bad.txt
// frame-ul este bun daca check_sum == calculated_check_sum

#include "xbee.h"
#include <stdlib.h>

int main(void)
{
    uint64_t size = 0;
    FRAME_DATA *frame_data = input_frame_data("xbee.bin", &size);

    printf("size = %llu\n", size);

    free(frame_data);
    
    return 0;
}




/*

        

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

    */
