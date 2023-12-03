#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define CHUNK 32

FILE *open_input(void)
{
    FILE *file = NULL;

    if((file = fopen("Luceafarul.txt", "r")) == NULL)
    {
        perror("Eroare la deschiderea fisierului\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

FILE *open_output(void)
{
    FILE *file = NULL;

    if((file = fopen("output.txt", "w")) == NULL)
    {
        perror("Eroare la deschiderea fisierului\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

void close_input(FILE *file)
{
    if(fclose(file) == EOF)
    { 
        perror("Eroare la inchiderea fisierului\n");
        exit(EXIT_FAILURE);
    }
}

void close_output(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("Eroare la inchiderea fisierului\n");
        exit(EXIT_FAILURE);
    }
}


char *get_line(FILE *file)
{
    char *line = NULL;
    char ch = 0;
    int current_size = 0, index = 0;

    while((ch = fgetc(file)) != EOF)
    {
        // daca nu mai am spatiu alocat dinamic pentru string

        if (index == current_size)
        {
            current_size += CHUNK;
            if((line = realloc(line, current_size * sizeof(char))) == NULL)
                return NULL;
        }

        // punem caracterul in string

        line[index++] = ch;

        // finalizam daca intalnim un /n

        if (ch == '\n')
            break;
    }

    // mai adaugam caracterul 0

    if (line != NULL)
    {
        if (index == current_size)
        {
            current_size++;
            if ((line = realloc(line, current_size * sizeof(int))) == NULL)
                return NULL;
        }

        line[index] = 0;
    }

    return line;
}


char **get_all_lines(FILE *file)
{
    char **line_arr = NULL;
    char *line = NULL;

    int current_size = 0, index = 0;

    while((line = get_line(file)) != NULL)
    {
        // verific daca mai am spatiu in vector
        
        if (index == current_size)
        {
            current_size += CHUNK;
            // daca pusca alocarea
            if((line_arr = realloc(line_arr, current_size * sizeof(char*))) == NULL)
                return NULL;
        }

        line_arr[index++] = line;
        
    }

    // adaugam un 0

    if (index == current_size)
    {
        current_size++;

        // daca pusca
        if((line_arr = realloc(line_arr, current_size * sizeof(char))) == NULL)
            return NULL;
    }

    line_arr[index] = NULL;

    return line_arr;
}   

void free_lines(char **arr)
{
    char **iter = NULL;
    iter = arr;

    // iter - vector
    // *iter - element din vector
    if(iter == NULL)
        printf("Vectorul este gol\n");

    else
        while(*iter != NULL)
        {
            free(*iter);
            iter++;
        }
}

void print_lines(char **array, FILE *file)
{
    char **iter = NULL;
    iter = array;

    while(*iter != NULL)
    {
        fputs(*iter, file);
        iter++;
    }
}

int main(void)
{
    FILE *input = NULL, *output = NULL;

    input = open_input();
    output = open_output();


    char **line_arr = NULL;

    line_arr = get_all_lines(input);
    
    print_lines(line_arr, output);
    
    free_lines(line_arr);
    free(line_arr);

    close_input(input);
    close_output(output);

    return 0;
}