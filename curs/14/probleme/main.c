#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 7E - 1 byte
// LEN - 1 byte
// DATA - LEN bytes
// CHECKSUM - 2 byte

// scriu frame-urile bune in fisierul xbee_good.txt
// scriu frame-urile gresite in fisierul xbee_bad.txt

FILE *open_file(char *filename, char *mode) 
{
    FILE *f = fopen(filename, mode);
    if (f == NULL) {
        perror(filename);
        exit(1);
    }
    return f;
}

void close_file(FILE *f)
{
    if(fclose(f) == EOF) 
    {
        perror("fclose");
        exit(1);
    }
}








int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Error\n");
        exit(-1);
    }


    FILE *input = open_file(argv[1], "rb");

    uint8_t sof = 0;
    uint8_t len = 0;
    uint8_t buffer[100];
    uint16_t checksum = 0;
    uint16_t my_checksum = 0;

    while(feof(input) == 0)
    {
        my_checksum = 0;

        if(fread(&sof, sizeof(uint8_t), 1, input) != 1)
        {
            break;
        }

        if(sof != 0x7E)
        {
            break;
        }

        if(fread(&len, sizeof(uint8_t), 1, input) != 1)
        {
            break;
        }

        if(len > 100)
        {
            break;
        }

        if(fread(buffer, sizeof(uint8_t), len, input) != len)
        {
            break;
        }

        if(fread(&checksum, sizeof(uint16_t), 1, input) != 1)
        {
            break;
        }

        for(uint8_t i = 0; i < len; i++)
        {
            my_checksum += buffer[i];
        }

        printf("%3d %04x %04x\n", len, checksum, my_checksum);

    }



    return 0;
}
