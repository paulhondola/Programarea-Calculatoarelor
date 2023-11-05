// Se citește un număr n<=10 și apoi n numere întregi.
// Se cere să se șteargă toate duplicatele (ori de câte ori apar acestea) din vector,
// păstrându-se ordinea elementelor.

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

void remove_element(int *array, unsigned int *size, unsigned int position)
{
    for(unsigned int i = position; i < (*size) - 1; i++)
        array[i] = array[i + 1];

    (*size)--;
}

void remove_duplicates(int *array, unsigned int *size)
{
    for(int i = 0; i < *size; i++)
    {
        for(int j = i + 1; j < *size; j++)
            if(array[i] == array[j])
            {
                remove_element(array, size, j);
                i--;
            }  
    }
}

int main(void)
{
    unsigned int size = 0;
    scanf("%u", &size);
    int array[size];

    read_array(array, size);
    print_array(array, size);

    remove_duplicates(array, &size);
    print_array(array, size);

    return 0;
}