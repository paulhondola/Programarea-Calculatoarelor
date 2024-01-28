/*
Să se implementeze o funcție void transform(const char *srcfile, const char *destfile) care primeste ca parametrii cai către un fișier de intrare și un fișier de ieșire. Programul citește din fișierul de intrare un text cu caractere și spații și transformă prima literă a fiecărui cuvânt în literă mare, iar dacă nu este literă caracterul rămâne neschimbat. Se va scrie în fișierul de ieșire acest șir. Obs. pe fiecare linie pot fi mai multe cuvinte și pot exista și linii vide. Citirea din fișier trebuie făcută cât mai eficient (cu chunk)
	ex: la ^masa sta Laura                  La ^masa Sta Laura
	         in Oras #ste O cASa                 In Oras #ste O CASa
Sa se încerce problema de mai sus și pentru transformarea tuturor literelor mici în litere mari, indiferent de poziția lor în șir (nu mai este necesar să transformăm doar prima literă)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define CHUNK 1024

FILE *open_file(const char *filepath, const char *mode)
{
    FILE *file = fopen(filepath, mode);
    if (file == NULL)
    {
        perror(filepath);
        exit(EXIT_FAILURE);
    }
    return file;
}


void close_file(FILE *file)
{
    if (fclose(file) == EOF)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}


void transform(const char *srcfile, const char *destfile)
{
    FILE *input = open_file(srcfile, "r");
    FILE *output = open_file(destfile, "w");

    char line[CHUNK];
    char *token;
    while(1)
    {
        if(fgets(line, CHUNK, input) == NULL)
            break;

        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        token = strtok(line, " ");

        while(token != NULL)
        {
            if(isalpha(token[0]))
                token[0] = toupper(token[0]);

            fprintf(output, "%s ", token);
            token = strtok(NULL, " ");
        }

        fprintf(output, "\n");
    }

    close_file(input);
    close_file(output);
}


int main(void)
{
    transform("input.txt", "output.txt");

    return 0;
}
