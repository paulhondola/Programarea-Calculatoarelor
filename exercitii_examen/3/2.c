/*
Sa se scrie o functie care primeste ca argumente 2 fisiere: source si destination. sa se scrie in fisierul destination suma numerelor gasite in textul din fisierul source si apoi continutul fisierului fara acele numere. antentul functiei: void addNumbers(char *source, char *dest). Sa se scrie folosind minimul de memorie, intr-un mod eficient.

input source: 
Ana7 a4re mere9.

output dest: 
18 Ana are mere.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 1024


FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);

    if(file == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}


char *read_string(FILE *file)
{
    char *string = malloc(sizeof(char));

    if(string == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    string[0] = 0;

    char buffer[CHUNK];

    while(1)
    {
        if(fgets(buffer, CHUNK, file) == NULL)
        {
            break;
        }

        string = realloc(string, strlen(string) + strlen(buffer) + 2);

        if(string == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        strcat(string, buffer);

        if(string[strlen(string) - 1] == '\n')
        {
            string[strlen(string) - 1] = 0;
            break;
        }
    }

    return string;
}


void add_numbers(FILE *source, FILE *destination)
{
    char *string = read_string(source);
    char *aux = malloc(strlen(string) + 1);

    aux[0] = 0;

    if(aux == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int sum = 0;

    for(int i = 0; i < (int)strlen(string); i++)
    {
        if(isdigit(string[i]))
        {
            sum += string[i] - '0';

            strcpy(aux, string + i + 1);
            strcpy(string + i, aux);
            i--;
        }
    }

    fprintf(destination, "%d %s", sum, string);

    free(string);
    free(aux);
}


int main(void)
{
    FILE *source = open_file("source.txt", "r");
    FILE *destination = open_file("destination.txt", "w");

    add_numbers(source, destination);

    close_file(source);
    close_file(destination);

    return EXIT_SUCCESS;
}
