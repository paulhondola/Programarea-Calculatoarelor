#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 2000

uint16_t *read_array_dynamic(uint16_t *size)
{
    uint16_t temp;
    uint16_t *array = NULL;
    uint16_t i = 0;

    uint16_t current_size = 0;



    while(scanf("%hu", &temp) == 1)
    {
        if (i == current_size)
        {
            // nu mai e loc boss

            current_size += CHUNK;

            
            if((array = realloc(array, current_size * sizeof(uint16_t))) == NULL)
            {
                // nu mai e loc veric
                *size = 0;
                return NULL;
            }
        }

        array[i] = temp;
        i++;
    }

    if((array = realloc(array, i * sizeof(uint16_t))) == NULL)
    {
        // nu mai e loc baaaaaa
        *size = 0;
        return NULL;
    }

    *size = i;

    return array;
}

void print_array(u_int16_t *arr, uint16_t size)
{
    for (uint16_t i = 0; i < size; i++)
    {
        printf("%hu ", arr[i]);
    }
    printf("\n");
}


int main(void)
{
    uint16_t *array = NULL;
    uint16_t size = 0;
    array = read_array_dynamic(&size);

    print_array(array, size);
    
    free(array);
    return 0;
}