#include <stdio.h>

void read_array(int *array, unsigned size)
{
    for(unsigned i = 0; i < size; i++)
        scanf("%d", array + i);
}


void print_array(int *array, unsigned size)
{
    for(unsigned i = 0; i < size; i++)
        printf("%d ", *(array + i));
    printf("\n");
}


int main(void)
{
    unsigned size = 0;
    scanf("%u", &size);

    int array[size];
    read_array(array, size);

    int *ptr = array + 2;
    *array = *ptr;
    print_array(array, size);

    return 0;
}