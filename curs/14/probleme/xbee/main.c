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
