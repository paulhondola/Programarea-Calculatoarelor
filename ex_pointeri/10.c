/*
n valori intregi

sa se afiseze toate valorile care au cel putin un duplicat
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 10

void input(int *array, int *nr_elements)
{
    if(scanf("%d", nr_elements) != 1)
    {
        perror("scanf");
        exit(-1);
    }

    int *iterator = array;
    for(int i = 0; i < *nr_elements; i++)
    {
        if(scanf("%d", iterator) != 1)
        {
            perror("scanf");
            exit(-1);
        }

        iterator++;
    }
}

void output(int *array, int nr_elements)
{
    int *iterator = array;

    for(int i = 0; i < nr_elements; i++)
    {
        printf("%d ", *iterator);
        iterator++;
    }
    printf("\n");
}


void array_duplicates(int *array, int nr_elements)
{
    int *iterator = array;
    int *iterator2 = array;

    for(int i = 0; i < nr_elements; i++)
    {
        iterator2 = iterator + 1;

        for(int j = i + 1; j < nr_elements; j++)
        {
            if(*iterator == *iterator2)
            {
                printf("%d ", *iterator);
                break;
            }
            iterator2++;
        }
        iterator++;
    }
}

int main(void)
{
    int array[SIZE];
    int nr_elements = 0;

    input(array, &nr_elements);
    output(array, nr_elements);

    print_duplicates(array, nr_elements);

    return 0;
}