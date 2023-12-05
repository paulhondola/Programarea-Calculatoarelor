// Să se citească de la tastatură un număr n<=10 iar apoi
// n valori de tip int. Să se afișeze dacă toate valorile pozitive sunt pare.

#include <stdio.h>
#include <stdint.h>

uint8_t check_poz_pare(int *array, uint8_t size)
{
    for(uint8_t i = 0; i < size; i++)
        if(array[i] >= 0 && array[i] % 2 == 1)
            return 0;
    return 1;
}

void read_array(int *array, uint8_t * size)
{
    for(uint8_t i = 0; i < * size; i++)
        if(scanf("%d", &array[i]) != 1)
        {
            * size = i;
            break;
        }
}

void print_array(int *array, uint8_t size)
{
    for(uint8_t i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    uint8_t size = 0;

    scanf("%hhu", &size);

    int array[size];

    read_array(array, &size);

    print_array(array, size);

    if(check_poz_pare(array, size))
        printf("Da\n");
    else
        printf("Nu\n");

    return 0;
}