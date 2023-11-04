// Se citește un număr n<=10 și apoi n perechi de numere întregi.
// Se cere să se insereze după fiecare pereche din vectorul original suma și apoi produsul numerelor din pereche.

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
    for(int i = original_size - 2, j = size - 4; i >= 0 && j >= 0; i -= 2, j -= 4)
    {
        // fragment the existing elements starting with the end of the array, putting along the sum and product
        
        array[j] = array[i];
        array[j + 1] = array[i + 1];
        array[j + 2] = array[j] + array[j + 1];
        array[j + 3] = array[j] * array[j + 1];
    }
}

int main(void)
{
    unsigned int size = 0;
    scanf("%u", &size);
    int array[4 * size];

    size *= 2;
    read_array(array, size);
    print_array(array, size);

    size *= 2;
    insert(array, size);
    print_array(array, size);

    return 0;
}