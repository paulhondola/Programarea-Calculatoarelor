/*
Se cere sa se scrie o functie care prelucreaza un sir de caractere astfel: fiecare caracter care nu e litera se inlocuieste cu valoarea sa din tabelul ASCII in format hexazecimal intre paranteze patrate si precedat de 0x. 
EX: “ana are mere, pere!” => “ana[0x20]are[0x20]mere[0x2C][0x20]pere[0x21]”
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 1024

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

        string = realloc(string, strlen(string) + strlen(buffer) + 1);

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

void print_format_string(char *string, FILE *file)
{
    for(unsigned long i = 0; i < strlen(string); ++i)
    {
        if(isalpha(string[i]))
        {
            fprintf(file, "%c", string[i]);
        }
        else
        {
            fprintf(file, "[0x%02x]", string[i]);
        }
    }
}

int main(void)
{
    char *string = read_string(stdin);

    print_format_string(string, stdout);

    free(string);

    return EXIT_SUCCESS;
}
