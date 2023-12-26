#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 2048

FILE *open_file(const char *filename, const char *mode)
{
    FILE *f = fopen(filename, mode);
    if (f == NULL) 
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    return f;
}

void close_file(FILE *f)
{
    if (fclose(f) == EOF)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
}

// afisati caracterele printabile 

// care nu sunt, (0x0A)


void printable(FILE *input, FILE *output)
{
    int ch;

    while(1)
    {
        ch = fgetc(input);

        if (ch == EOF)
        {
            break;
        }

        if(isprint(ch))
        {
            fprintf(output, "%c ", ch);
        }
        else
        {
            fprintf(output, "(0x%x) ", ch);
        }
    }
}


void print_all_chars(FILE *input, FILE *output)
{
    char buffer[BUFFER_SIZE];

    unsigned int read = 0;

    while ((read = fread(buffer, sizeof(char), BUFFER_SIZE, input)) != 0)
    {
        for (int i = 0; i < read; i++)
        {
            fprintf(output, "%c", buffer[i]);
        }
    }
}


int main(void)
{
    FILE * input = open_file("input.txt", "r");

    FILE * output = open_file("output.txt", "w");

    printable(input, output);

    return 0;
}