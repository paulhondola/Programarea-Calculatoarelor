// Se da o functie care primeste ca parametrii: calea catre un fisier de intrare, calea catre un fisier de iesire si un nr n. Sa se afiseze in fisierul de iesire caracterele de pe pozitiile 0, 1•n, 2•n, 3•n, … din fisierul de intrare.

#include <stdio.h>
#include <stdlib.h>
#define CHUNK 32

FILE *open_file(char *path, char *mode) 
{
    FILE *file = fopen(path, mode);
    if (file == NULL) 
    {
        perror(path);
        exit(1);
    }
    return file;
}

void close_file(FILE *file) 
{
    if(fclose(file) == EOF) 
    {
        printf("Error closing file\n");
        exit(1);
    }
}

void print_n_file(FILE *input, FILE *output, int n)
{
    char *buffer = (char *)malloc(CHUNK * n * sizeof(char));
    int i = 0;

    while (1)
    {
        if(fgets(buffer, CHUNK * n, input) == NULL)
            break;

        for (i = 0; i < CHUNK; i++)
            fprintf(output, "%c", buffer[i * n]);
    }

    free(buffer);
}

int main(void)
{
    FILE *input = open_file("input.txt", "r");
    FILE *output = open_file("output.txt", "w");


    print_n_file(input, output, 3);


    close_file(input);
    close_file(output);

    return 0;
}
