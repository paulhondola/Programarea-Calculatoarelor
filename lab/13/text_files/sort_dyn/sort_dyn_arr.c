/*
Se citesc de la tastatură maxim 100 numere reale, până la întâlnirea numărului 0. Să se sorteze aceste numere și să se scrie într-un fișier, toate numerele fiind pe o singură linie, separate prin | (bară verticală).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

FILE *open_output(void)
{
    FILE *file = fopen("output.txt", "w");

    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    return file;
}

void close_output(FILE *file)
{
    if(fclose(file) == EOF)
    {
        printf("Error closing file\n");
        exit(1);
    }
}


void swap(float *a, float *b)
{
    float aux = *a;
    *a = *b;
    *b = aux;
}


void sort(float *array, int size)
{
    int ok = 0;

    do
    {
        ok = 0;

        for(int i = 0; i < size - 1; i++)
        {
            if(array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                ok = 1;
            }
        }
    } while(ok);
}


void input_array(float *array, int *size)
{
    int i = 0;

    for(i = 0; i < *size; i++)
    {
        if(scanf("%f", &array[i]) != 1)
        {
            break;
        }

        if(array[i] == 0)
        {
            break;
        }
    }

    *size = i;
}


void print_array(float *array, int size, FILE *file)
{
    int i = 0;

    for(i = 0; i < size; i++)
    {
        fprintf(file, "%.02f | ", array[i]);
    }

    printf("\n");
}


int main(void)
{
    FILE *file = NULL;

    file = open_output();


    float array[MAX];

    int size = MAX;

    input_array(array, &size);

    sort(array, size);

    print_array(array, size, file);


    close_output(file);

    return 0;
}
