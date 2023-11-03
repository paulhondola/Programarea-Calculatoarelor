// Se citesc 2 numere x și y cu x<y. Să se afișeze minimul elementelor din vectorul
// {7, -5, 4, 3, -9, 2, -8}, care se află în același timp și în intervalul [x,y].

#include <stdio.h>
#include <stdint.h>

uint8_t check_bigger(int8_t *array, uint8_t size, int8_t x, int8_t y)
{
    uint8_t min = ;
    for(uint8_t i = 0; i < size; i++)
        if(x <= array[i])
            return 1;
    return 0;
}

int main(void)
{
    int8_t k = 0;
    scanf("%hhd", &k);

    if(k < -129 || k > 128)
        return -1;

    int8_t array[] = {7, -5, 4, 3, -9, 2, -8};
    uint8_t size = sizeof(array) / sizeof(array[0]);

    printf("%hhu\n", check_bigger(array, size, k));

    return 0;
}
