#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SIZE 128
#define LINE_SIZE 2048
#define ALLOC_CHUNK 1000

FILE * open_input(void)
{
    FILE * f = fopen("parc-auto-2013.csv", "r");

    if (f == NULL)
    {
        perror("auto.csv");
        exit(EXIT_FAILURE);
    }

    return f;
}

void close_input(FILE * f)
{
    if(fclose(f) != 0)
    {
        perror("parc-auto-2013.csv");
        exit(EXIT_FAILURE);
    }

}


typedef struct
{
    char judet[SIZE + 1];
    char categorie[SIZE + 1];
    char marca[SIZE + 1];
    char descriere[SIZE + 1];
    uint32_t total; 

} AUTO;



int8_t process_line(char *line, AUTO *a)
{
    char *p;

    // JUDET
    if((p = strtok(line, ",")) == NULL)
        return -1;  // format error
    
    strcpy(a->judet, p + 1);

    a->judet[strlen(a->judet) - 1] = '\0';

    
    // CATEGORIE
    if ((p = strtok(NULL, ",")) == NULL)
        return -1;  // format error


    strcpy(a->categorie, p + 1);

    a->categorie[strlen(a->categorie) - 1] = '\0';

    // CATEGORIA COMUNITARA
    if ((p = strtok(NULL, ",")) == NULL)
        return -1;  // format error


    // MARCA
    if ((p = strtok(NULL, ",")) == NULL)
        return -1;  // format error

    strcpy(a->marca, p + 1);

    a->marca[strlen(a->marca) - 1] = '\0';


    // DESCRIERE
    if ((p = strtok(NULL, ",")) == NULL)
        return -1;  // format error

    strcpy(a->descriere, p + 1);

    a->descriere[strlen(a->descriere) - 1] = '\0';


    // TOTAL
    if ((p = strtok(NULL, ",")) == NULL)
        return -1;  // format error

    
    a->total = strtol(p + 1, NULL, 10); // sarim de prima ghilimea, strtol se va opri la a doua

    return 0;
}

void print_auto(AUTO *a)
{
    printf("JUDET: %s ", a->judet);
    printf("CATEGORIE: %s ", a->categorie);
    printf("MARCA: %s ", a->marca);
    printf("DESCRIERE: %s ", a->descriere);
    printf("TOTAL: %u ", a->total);
    printf("\n");
}


void print_auto_array(AUTO *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        print_auto(&arr[i]);
    }

}

AUTO * add_to_array(AUTO *array, const AUTO *element, int *size)
{
    static int index = 0;

    static int current_size = 0;

    if(index == current_size)
    {
        current_size += ALLOC_CHUNK;

        array = realloc(array, current_size * sizeof(AUTO));

        if(array == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
    }

    array[index++] = *element;
    *size = index;

    return array;
}


void write_count_to_file(const char *filename, const AUTO *array, int size, char *judet)
{
    FILE *f = fopen(filename, "w");

    if(f == NULL)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    } 


    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(strcmp(array[i].judet, judet) == 0)
        {
            count += array[i].total;
        }
    }


    fprintf(f, "%s,%6d\n", judet, count);


    if(fclose(f) != 0)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }
}


int main(void)
{
    FILE *input = open_input();

    AUTO aux;
    char line[LINE_SIZE];

    if(fgets(line, LINE_SIZE, input) == NULL)
    {
        perror("parc-auto-2013.csv");
        exit(EXIT_FAILURE);
    }

    printf("HEADER: %s\n", line);

    int size = 0;
    AUTO *array = NULL;
    while(fgets(line, LINE_SIZE, input) != NULL)
    {
        if(process_line(line, &aux) == 0)
        {
            array = add_to_array(array, &aux, &size);
        }
    }

    print_auto_array(array, size);

    close_input(input);

    write_count_to_file("out.txt", array, size, "TIMIS");

    free(array);
    return 0;
}