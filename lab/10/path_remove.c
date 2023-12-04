/*
3. Se citesc de la tastatura căi către fișiere de pe disk, până la EOF (ctrl+D).
Programul va afișa numele fișierului, eliminând numele directoarelor în care este stocat.
ex. /home/student/pc/lab2/fisier.c -> fisier.c
Pentru rezolvarea problemei se vor folosi următoarele metode:
    1. strtok cu împărțire după '/'
    2. strchr cu căutare după '/'
    3. fără funcții din string.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 100

char *get_path()
{
    char *path = NULL;
    char ch = 0;
    int index = 0;
    int size = 0;

    while((ch = getchar()) != EOF)
    {
        if (index == size)
        {
            // modificam marimea totala a liniei
            size += CHUNK;

            // alocam dinamic restul
            if((path = realloc(path, sizeof(char) * size)) == NULL)
            // daca pusca
                return NULL;

        }

        *(path + index++) = ch;

        if(ch == '\n')
            break;
    }

    if(path != NULL)
        *(path + index - 1) = 0;

    return path;
}

char **get_all_paths()
{
    char **path_array = NULL;
    char *path = NULL;
    int index = 0, size = 0;

    while((path = get_path()) != NULL)
    {
        // verificam daca mai este loc in array

        if (index == size)
        {
            size += CHUNK;
            // alocam dinamic

            if((path_array = realloc(path_array, size * sizeof(char *) )) == NULL)
                return NULL;
        }

        *(path_array + index++) = path;
    }

    if (index == size)
    {
        size++;

        // daca pusca
        if((path_array = realloc(path_array, size * sizeof(char *))) == NULL)
            return NULL;
    }

    *(path_array + index) = NULL;

    return path_array;
}


void remove_all_headers(char **path_array)
{
    char ** iterator = path_array;

    char *delimitator = "/";

    while(*iterator != NULL)
    { 
        char *root_path = NULL;
        char *aux = NULL;

        aux = strtok(*iterator, delimitator);

        while(aux != NULL)
        {
            root_path = aux;
            aux = strtok(NULL, delimitator);
        }

        *iterator = root_path;
        iterator++;
    }
    
}


void print_paths(char **path_array)
{

    printf("Paths:\n");

    char **iterator = path_array;

    while(*iterator)
    {
        printf("%s\n", *iterator);
        iterator++;
    }
}


void free_all(char **path_array)
{
    char **iterator = path_array;

    if(iterator == NULL)
        printf("Vectorul este gol\n");
    else
        while(*iterator != NULL)
        {
            free(*iterator);
            iterator++;
        }
}

int main(void)
{
    char **path_array = NULL;

    
    if((path_array = get_all_paths()) == NULL)
    {
        perror("Nu ati citit nimic\n");
        exit(EXIT_FAILURE);
    }

    print_paths(path_array);

    remove_all_headers(path_array);

    print_paths(path_array);

    //free_all(path_array);
    free(path_array);

    return 0;
}