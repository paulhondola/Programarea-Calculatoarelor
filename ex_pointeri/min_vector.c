// Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși.

#include <stdio.h>

int minim(int *array, unsigned int size)
{
    int min = *array;
    for(unsigned int i = 1; i < size; i++)
        if(min > *(array + i))
            min = *(array + i);
    return min;
}

int main(void)
{
    int array[] = {7, -5, 4, 3, -9, 2, -8};
    unsigned int size = sizeof(array) / sizeof(*array);
    printf("%d\n", minim(array, size));

    return 0;
}