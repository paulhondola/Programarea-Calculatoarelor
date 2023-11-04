// Se citește un număr n<=10 și apoi n numere întregi.
// Se cere să se insereze după fiecare valoare din vectorul original pătratul ei.

#include <stdint.h>
#include <stdio.h>

void read_array(int *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

void print_array(int *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insert(int *array, unsigned int size)
{
    int original_size = size / 2;

    for(int i = original_size - 1, j = size - 2; i >= 0; i--, j -= 2)
    {
        array[j] = array[i];
        array[j + 1] = array[i] * array[i];
    }
}

int main(void)
{
    unsigned int size = 0;
    scanf("%u", &size);
    int array[2 * size];

    read_array(array, size);
    print_array(array, size);

    size *= 2;
    insert(array, size);
    print_array(array, size);

    return 0;
}