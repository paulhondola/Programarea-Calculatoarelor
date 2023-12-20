#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024


int main(int argc, char **argv) 
{
    FILE *input = NULL;
    FILE *output = NULL;

    unsigned char ch[BUFFER_SIZE];
    unsigned char out_buffer[BUFFER_SIZE + 1];


    unsigned long read = 0;

    if(argc != 3)
    {
        fprintf(stderr, "Incorrect number of arguments\n");
        exit(1);
    }

    input = fopen(argv[1], "rb");

    if(input == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(1);
    }


    output = fopen(argv[2], "w");

    if(output == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", argv[2]);
        exit(1);
    }

    memset(out_buffer, 0, BUFFER_SIZE + 1);

    int index = 0;

    while((read = fread(ch, sizeof(char), BUFFER_SIZE, input)) > 0)
    {
        for(int i = 0; i < read; i++)
        {
            if(isprint(ch[i]))
            {
                //fputc(ch[i], output);
                out_buffer[index++] = ch[i];

                if(index == BUFFER_SIZE)
                {
                    fputs((char *)out_buffer, output);
                    memset(out_buffer, 0, BUFFER_SIZE + 1);
                    index = 0;
                }
            }
        }
    }

    if(index > 0)
    {
        fputs((char *)out_buffer, output);
    }


    

    if(fclose(input) != 0)
    {
        fprintf(stderr, "Error closing file %s\n", argv[1]);
        exit(1);
    }

    if(fclose(output) != 0)
    {
        fprintf(stderr, "Error closing file %s\n", argv[2]);
        exit(1);
    }

    return 0;
}
