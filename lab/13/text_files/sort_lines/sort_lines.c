/*
Se consideră un fișier text ce conține un număr necunoscut de linii de text de o dimensiune necunoscută. Să se scrie un program ce citește un astfel de fișier și stochează datele într-un tablou alocat dinamic de string-uri C alocate dinamic. Se va folosi o amprentă minimă de memorie. Se vor scrie de asemenea și următoarele funcții

o funcție void write_sort(char **lines, char *filepath); - funcția va prelua tabloul de linii, le va sorta alfabetic și le va scrie în fișierul cu calea filepath. Se va realiza conex și o funcție de sortare a tabloului de linii lines. Se poate folosi bubble-sort. Pentru compararea aflabetică a două linii se poate folosi funcția strcmp(...)

o funcție void write_random(char **lines, char *filepath); - funcția va prelua tabloul de linii și le va scrie în fișierul referit prin calea filepath în ordine aleatoare a liniilor. Hint ! Se poate folosi funcția rand(....);

o funcție uint32_t find_word(char **lines, char *word); - funcția va căuta cuvântul referit prin word în tabloul de linii lines și va returna numărul de apariții.

Fișierul de test se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define LINE_CHUNK 4096
#define ARRAY_CHUNK 1024

FILE *open_file(char *filepath, char *mode)
{
    FILE *f = fopen(filepath, mode);

    if (f == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return f;
}


void close_file(FILE *f)
{
    if (fclose(f) == EOF)
    {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}


void free_all(char **lines, uint64_t size)
{
    for(uint64_t i = 0; i < size; i++)
    {
        free(lines[i]);
    }
}


char *input_line(FILE *f)
{
    char *line = malloc(sizeof(char));

    line[0] = 0;

    char aux[LINE_CHUNK];

    uint64_t allocated_size = 0;

    while(1)
    {
        // citim un chunk de linie

        // daca linia este goala, iesim din bucla - am ajuns la finalul fisierului

        // daca ultimul caracter este \n - am terminat de citit linia

        // daca ultimul caracter este diferit de \n - concatenam chunk-ul citit la linie


        if(fgets(aux, LINE_CHUNK, f) == NULL)
        {
            break;
        }

        allocated_size += strlen(aux);
        

        line = (char *)realloc(line, allocated_size * sizeof(char));

        if(line == NULL)
        {
            perror("Error reallocating memory");

            exit(EXIT_FAILURE);
        }

        printf("%s\n", aux);

        strcat(line, aux);
        
        if(line[strlen(line) - 1] == '\n')
        {
            break;
        }
    }


    return line;
}


char **input_lines(FILE *f, uint64_t *size)
{
    char **lines = NULL;
    char *line = NULL;

    uint64_t allocated_size = 0;
    uint64_t used_size = 0;

    while(1)
    {
        line = input_line(f);

        if(line == NULL || line[0] == 0)
        {
            break;
        }

        if(used_size == allocated_size)
        {
            allocated_size += ARRAY_CHUNK;
            lines = (char **)realloc(lines, allocated_size * sizeof(char *));

            if(lines == NULL)
            {
                perror("Error reallocating memory");
                exit(EXIT_FAILURE);
            }
        }

        lines[used_size] = line;

        used_size++;
    }

    if(used_size == 0)
    {
        perror("Empty file");
        exit(EXIT_FAILURE);
    }

    lines = (char **)realloc(lines, used_size * sizeof(char *));

    if(lines == NULL)
    {
        perror("Error reallocating memory");
        exit(EXIT_FAILURE);
    }

    *size = used_size;

    return lines;
}


void print_all_lines(char **lines, uint64_t size, FILE *f)
{
    for(uint64_t i = 0; i < size; i++)
    {
        fprintf(f, "%s", lines[i]);
    }
}


void sort_lines(char **lines, uint64_t size)
{
    uint8_t ok = 0;

    do
    {
        ok = 0;

        for(uint64_t i = 0; i < size - 1; i++)
        {
            if(strcmp(lines[i], lines[i + 1]) > 0)
            {
                char *aux = lines[i];
                lines[i] = lines[i + 1];
                lines[i + 1] = aux;

                ok = 1;
            }
        }

    } while (ok);
    
}


void write_sort(char **lines, uint64_t size, char *filepath)
{
    FILE *f = open_file(filepath, "w");

    sort_lines(lines, size);

    print_all_lines(lines, size, f);

    close_file(f);
}


void write_random(char **lines, uint64_t size, char *filepath)
{
    FILE *f = open_file(filepath, "w");

    srand(time(NULL));

    for(uint64_t i = 0; i < size; i++)
    {
        uint64_t random = rand() % size;

        char *aux = lines[i];
        lines[i] = lines[random];
        lines[random] = aux;
    }

    print_all_lines(lines, size, f);

    close_file(f);
}


uint64_t find_word(char **lines, uint64_t size, char *word)
{
    uint64_t count = 0;

    for(uint64_t i = 0; i < size; i++)
    {
        char *ptr = strstr(lines[i], word);

        while(ptr != NULL)
        {
            count++;

            ptr = strstr(ptr + 1, word);
        }
    }

    return count;
}

int main(void)
{
    FILE *input = NULL;
    FILE *output = NULL;

    input = open_file("scrisoare.txt", "r");
    output = open_file("output.txt", "w");

    uint64_t size = 0;
    char **lines = NULL;

    lines = input_lines(input, &size);

    uint64_t count = find_word(lines, size, "de");

    print_all_lines(lines, size, output);
    
    write_sort(lines, size, "sort.txt");

    write_random(lines, size, "random.txt");
    
    printf("Numarul de aparitii ale cuvantului 'de' este: %llu\n", count);


    free_all(lines, size);
    free(lines);

    close_file(input);
    close_file(output);

    return 0;
}
