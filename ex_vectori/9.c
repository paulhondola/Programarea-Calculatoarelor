// Se citește un număr n<=10 și apoi n numere pozitive.
// Se cere să se insereze înainte de fiecare valoare impară din vectorul original valoarea 0.

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

void free_at(int *array, unsigned int *size, int position)
{
    (*size)++;
    for(int i = *size - 2; i >= position; i--)
        array[i + 1] = array[i];
}

void insert(int *array, unsigned int *size)
{
    for(int i = 0; i < *size; i++)
        if(array[i] % 2)
        {
            free_at(array, size, i);
            array[i] = 0;
            i++;
        }         
}

int main(void)
{
    unsigned int size = 0;
    scanf("%u", &size);
    int array[2 * size];

    read_array(array, size);
    print_array(array, size);

    //cfree_at(array, &size, 0);
    insert(array, &size);
    printf("%u\n", size);
    print_array(array, size);

    return 0;
}