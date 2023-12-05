#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int nr_elements)
{
    for(int i = 0; i < nr_elements; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}


void insert_at(int *array, int *size, int index, int value)
{
    value = - *(array + index);

    for(int i = *size; i > index; i--)
    {
        *(array + i) = *(array + i - 1);
    }

    *(array + index) = value;

    *size += 1;
}

void update_array(int *array, int *size)
{
    for(int i = 0; i < *size; i += 2)
    {
        insert_at(array, size, i, *(array + i));
    }
}


int main(void)
{
    int array[14] = {7, -5, 4, 3, -9, 2, -8};

    int size = sizeof(array) / sizeof(array[0]) / 2;

    print_array(array, size);

    update_array(array, &size);

    print_array(array, size);
    
    return 0;
}