// abcdefg -> apabcdepefg

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 16
#define SIZE 100

char *input_string(void)
{
    char *string = malloc(SIZE * sizeof(char));

    if(string == NULL)
    {
        perror("Nu s-a putut aloca memorie pentru string.\n");
        exit(EXIT_FAILURE);
    }

    if(fgets(string, SIZE, stdin) == NULL)
    {
        printf("Nu s-a putut citi string-ul.\n");
        exit(EXIT_FAILURE);
    }

    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';

    return string;
}


char *edit_string(char *input)
{
    char *string = malloc(strlen(input) * sizeof(char));   // alocam memorie pentru noul string

    if(string == NULL)
    {
        perror("Nu s-a putut aloca memorie pentru noul string.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(string, input);     // copiem string-ul in noul string

    // parcurgem string-ul si adaugam pe pozitia i caracterul 'p' daca string[i] este vocala

    const char *vowels = "aeiouAEIOU";

    char *aux = NULL;

    unsigned long size = strlen(string);

    for(unsigned long i = 0; i < size; i++)
    {
        if(strchr(vowels, string[i]) == NULL)
        {
            continue;
        }
        
        size += 2;

        string = realloc(string, size * sizeof(char));

        if(string == NULL)
        {
            perror("Nu s-a putut aloca memorie pentru noul string.\n");
            exit(EXIT_FAILURE);
        }

        aux = realloc(aux, size);

        strcpy(aux, string + i + 1);
        strcpy(string + i + 3, aux);

        string[i + 1] = 'p';
        string[i + 2] = string[i];

        i += 2;
    }

    free(aux);

    return string;
}


int main(void)
{
    char *string = input_string();

    string = edit_string(string);

    printf("%s\n", string);

    free(string);

    return 0;
}
