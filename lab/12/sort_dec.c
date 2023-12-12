/*
Se va citi de la intrarea standard un numar neconscut de valor intregi nenule pozitive pana la EOF. Se vor stoca aceste elemente intr-un tablou dinamic. Programul va afisa la iesirea standard tabloul sortat descrescator.
*/

#include <stdio.h>
#include <stdlib.h>

#define CHUNK 1000

int main(void)
{
    int *array = NULL;

    int allocated_size = 0;

    int size = 0;

    int input = 0;


    if(scanf("%d", &input) != 1)
    {
        printf("Error\n");
        exit(1);
    }

    array = malloc(CHUNK * sizeof(int));

    if(array == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }

    array[size++] = input;

    while(1)
    {
        if(scanf("%d", &input) != 1)
        {
            break;
        }

        // verificam daca mai avem spatiu in vector

        if(size == allocated_size)
        {
            allocated_size += CHUNK;
            array = realloc(array, allocated_size * sizeof(int));

            if(array == NULL)
            {
                printf("Not enough memory\n");
                exit(1);
            }
        }

        // cautam in vector pozitia pe care trebuie sa inseram elementul curent

        int i = 0;

        for(i = 0; i < size; i++)
        {
            if(input > array[i])
            {
                // mutam toate elementele cu o pozitie la dreapta
                int j = 0;

                for(j = size; j > i; j--)
                {
                    array[j] = array[j - 1];
                }

                array[i] = input;
                size++;
                
                break;
            }
        }

    }

    printf("Sorted array:\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}
