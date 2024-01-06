#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 1024

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);

    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    return file;
}

void close_file(FILE *file)
{
    if (fclose(file) == EOF)
    {
        perror("Error closing file");
        exit(1);
    }
}


void printable(FILE *input, FILE *output)
{
    char buffer[BUFFER];

    while(1)
    {
        if(fgets(buffer, BUFFER, input) == NULL)
        {
            break;
        }

        printf("citire reusita\n");

        for(unsigned long i = 0; i < strlen(buffer); i++)
        {
            if(isprint(buffer[i]))
            {
                fputc(buffer[i], output);
            }

            else
            {
                fprintf(output, "(0x%02x)", buffer[i]);
            }

            
        }

        fputc('\n', output);
    }
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        perror("Invalid number of arguments");
        exit(1);
    }

    char *input_path = argv[1];
    char *output_path = argv[2];


    FILE *input = open_file(input_path, "r");
    FILE *output = open_file(output_path, "w");

    printable(input, output);

    close_file(input);
    close_file(output);

    return 0;
}
