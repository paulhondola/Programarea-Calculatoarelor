#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

void read_array(int *array, int *size)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(scanf("%d", array + i) != 1)
        {
            *size = i;
            break;
        }
    }
}


void print_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }

    printf("\n");
}


void remove_at(int *array, int *size, int position)
{
    for(int i = position; i < *size - 1; i++)
    {
        *(array + i) = *(array + i + 1);
    }

    (*size)--;
}


void remove_elements(int *array, int *size)
{
    for(int i = 0; i < *size; i++)
    {
        if(*(array + i) % 3 == 0)
        {
            remove_at(array, size, i);
            i--;
        }
    }
}

int main(void)
{
    int array[SIZE];

    int size = 0;

    read_array(array, &size);

    print_array(array, size);

    remove_elements(array, &size);

    print_array(array, size);

    return 0;
}
