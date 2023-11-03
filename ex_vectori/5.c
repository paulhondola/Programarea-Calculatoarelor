// Se citesc 2 numere x și y cu x<y. Să se afișeze minimul elementelor din vectorul
// {7, -5, 4, 3, -9, 2, -8}, care se află în același timp și în intervalul [x,y].

#include <stdio.h>
#include <stdint.h>

uint8_t check_bigger(int8_t *array, uint8_t size, int8_t x, int8_t y)
{
    uint8_t min = 0, found = 0, index = 0;
    while(!found)
    { 
        if(array[index] >= x && array[index] <= y)
        {
            min = array[index];
            found++;
        }
        index++;
    }

    
    while(index < size)
    {
        if(min > array[index] && array[index] >= x && array[index] <= y)
            min = array[index];
        index++;
    }
    
    return min;
}

int main(void)
{
    int8_t x = 0, y = 0;
    scanf("%hhd %hhd", &x, &y);

    if(x >= y)
        return -1;

    int8_t array[] = {7, -5, 4, 3, -9, 2, -8};
    uint8_t size = sizeof(array) / sizeof(array[0]);

    printf("%hhu\n", check_bigger(array, size, x, y));

    return 0;
}
