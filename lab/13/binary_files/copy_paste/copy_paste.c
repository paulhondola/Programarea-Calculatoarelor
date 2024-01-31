/*
Sa se scrie si testeze o functie ce primeste ca argument o cale de fisier sursa si o cale de fisier destinatie. Programul va copia continutul fisierului sursa in fisierul destinatie. Se vor folosi functii specializate de lucru cu fisiere binare.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHUNK 1024

FILE *open_file(char *filepath, char *mode)
{
    FILE *file = fopen(filepath, mode);

    if(file == NULL)
    {
        perror("file not found");
        exit(EXIT_FAILURE);
    }

    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("cannot close file");
        exit(EXIT_FAILURE);
    }
}



void move_data(FILE *source, FILE *destination)
{
    fseek(source, 0x00, SEEK_SET);
    fseek(destination, 0x00, SEEK_SET);

    int array[CHUNK];

    unsigned long long int read = 0;

    while(1)
    {
        read = fread(array, sizeof(int), CHUNK, source);

        if (read == 0)
            break;

        fwrite(array, sizeof(int), read, destination);
    }
}


int main(void)
{
    FILE *input = open_file("integers.bin", "rb");
    FILE *output = open_file("integers(copy).bin", "w");

    move_data(input, output);

    close_file(input);
    close_file(output);

    return 0;
}
