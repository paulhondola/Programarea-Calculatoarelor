/*
Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin virgulă. Fișierul conține informații despre filme. Pe fiecare linie se află câte o inregistrare ce reprezintă un film cu date despre acesta, date ce sunt separate prin virgulă. O linie are următoarea configurație (cap de tabel)

year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code

Se va citi acest fișier în mod optim. Pentru fiecare înregistrare se vor extrage următoarele date: titlu, an, buget (title, year, budget). Se va proiecte și implementa o structură de date corespunzătoare. Se vor stoca aceste date intr-un tablou alocat dinamic. Se precizează că se consideră necunoscută dimensiunea fișierului ( a numărului de linii) - se va aloca minimul de memorie necesar pentru a stoca toate informațiile. Programul va scrie în fișierul out1.txt toate filmele sortate după anul apariției, în fișierul out2.txt toate filmele sortate după titlu iar în fișierul out3.txt toate filmele sortate după buget.

Fișierul de test poate fi descărcat folosind urmatoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/movies.csv
Se vor realiza mai multe variante de procesare si extragere de informații dintr-o linie de date: folosind strtok, folosind strchr, agloritm propriu prin parcurgere caracter cu caracter a unei linii deja citite din fișier.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

FILE* open_file(char *filename, char *mode)
{
    FILE *file = NULL;

    file = fopen(filename, mode);

    if(file == NULL)
    {
        perror("cannot open file");
        exit(EXIT_FAILURE);
    }

    return file;
}

void close_file(FILE* file)
{
    if(fclose(file) == EOF)
    {
        perror("cannot close file");
        exit(EXIT_FAILURE);
    }
}


#define BUFFER 4096
#define CHUNK 1024
#define TITLE_SIZE 512

void create_header(FILE* file)
{
    char header[BUFFER];
    if(fgets(header, BUFFER, file) == NULL)
    {
        perror("file is empty");
        exit(EXIT_FAILURE);
    }

    printf("TITLE | YEAR | BUDGET\n");
}

// HEADER

// year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code
// 0     1    2     3      4        5       6       7        8       9      10           11             12             13           14


typedef struct
{
    char title[TITLE_SIZE];
    unsigned int year;
    unsigned long long int budget;

} MOVIES_T;


int input_item(MOVIES_T *data, FILE *file)
{
    // check if the file is empty

    char line[BUFFER];

    if(fgets(line, BUFFER, file) == NULL)
    {
        return 0;
    }

    // split the line into structures

    char *field = strtok(line, ",");

    for(uint8_t i = 0; i < 7; i++)
    {
        if(field == NULL)
        {
            printf("invalid format\n");
            exit(EXIT_FAILURE);
        }

        switch (i)
        {
        case 0: // year
            data->year = (unsigned int)strtol(field, NULL, 10);
            break;

        case 2: // title
            strcpy(data->title, field);

            // check if title has one or more commas (the titles are between inverted commas)
            if(data->title[0] == '"')
            {
                while(data->title[strlen(data->title) - 1] != '"')
                {
                    field = strtok(NULL, ",");

                    if(field == NULL)
                    {
                        printf("invalid format\n");
                        exit(EXIT_FAILURE);
                    }

                    strcat(data->title, field);
                }
            }
            
            break;

        case 6: // budget
            data->budget = (unsigned long long)strtol(field, NULL, 10);
            break;

        default:
            break;
        }

        field = strtok(NULL, ",");
    }

    return 1;
}


MOVIES_T *input_array(uint64_t *size, FILE *file)
{
    MOVIES_T *database = NULL;
    MOVIES_T item;

    uint64_t used_space = 0, allocated_space = 0;

    while(1)
    {
        // stop when reaching EOF

        if(!input_item(&item, file))
            break;

        // check if there is no more allocated space

        if(used_space == allocated_space)
        {
            allocated_space += CHUNK;

            database = realloc(database, allocated_space * sizeof(MOVIES_T));

            if(database == NULL)
            {
                perror("realloc failed");
                exit(EXIT_FAILURE);
            }
        }

        database[used_space++] = item;
    }

    *size = used_space;

    return database;
}


void print_array(const MOVIES_T *database, const uint64_t size, FILE *file)
{
    for(uint64_t i = 0; i < size; i++)
    {
        fprintf(file, "%s | %u | %llu\n", database[i].title, database[i].year, database[i].budget);
    }
}


void sort_year(MOVIES_T *database, uint64_t size)
{
    uint8_t ok = 0;
    MOVIES_T aux;

    do
    {
        ok = 0;

        for(uint64_t i = 0; i < size - 1; i++)
            if(database[i].year > database[i + 1].year)
            {
                aux = database[i];
                database[i] = database[i + 1];
                database[i + 1] = aux;
                
                ok = 1;
            }

    } while (ok);
}


void sort_budget(MOVIES_T *database, uint64_t size)
{
    uint8_t ok = 0;
    MOVIES_T aux;

    do
    {
        ok = 0;

        for(uint64_t i = 0; i < size - 1; i++)
            if(database[i].budget > database[i + 1].budget)
            {
                aux = database[i];
                database[i] = database[i + 1];
                database[i + 1] = aux;
                
                ok = 1;
            }

    } while (ok);
}


void sort_title(MOVIES_T *database, uint64_t size)
{
    uint8_t ok = 0;
    MOVIES_T aux;

    do
    {
        ok = 0;

        for(uint64_t i = 0; i < size - 1; i++)
            if(strcmp(database[i].title, database[i + 1].title) > 0)
            {
                aux = database[i];
                database[i] = database[i + 1];
                database[i + 1] = aux;
                
                ok = 1;
            }

    } while (ok);
}


void out(MOVIES_T *database, uint64_t size)
{
    FILE *file1 = open_file("out1.txt", "w");
    FILE *file2 = open_file("out2.txt", "w");
    FILE *file3 = open_file("out3.txt", "w");


    sort_year(database, size);
    print_array(database, size, file1);

    sort_title(database, size);
    print_array(database, size, file2);

    sort_budget(database, size);
    print_array(database, size, file3);

    close_file(file1);
    close_file(file2);
    close_file(file3);
}


int main(void)
{
    FILE *input = open_file("movies.csv", "r");
    MOVIES_T *database = NULL;
    uint64_t size = 0;

    create_header(input);

    database = input_array(&size, input);
    
    print_array(database, size, stdout);


    out(database, size);


    free(database);
    close_file(input);

    return 0;
}
