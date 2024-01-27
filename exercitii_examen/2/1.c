#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 10000

uint8_t bit_parity(uint32_t number)
{
    uint8_t parity = 0;

    while (number)
    {
        parity ^= number & 1;
        number >>= 1;
    }

    return parity;
}

void read_arrays(uint32_t *array_a, uint32_t *array_b, uint32_t *size, char *filepath)
{
    FILE *file = fopen(filepath, "r");

    if(file == NULL)
    {
        perror(filepath);
        exit(1);
    }

    if(fscanf(file, "%u", size) != 1)
    {
        perror("Invalid input");
        exit(1);
    }

    for(uint32_t i = 0; i < *size; ++i)
    {
        if(fscanf(file, "%u", &array_a[i]) != 1)
        {
            perror("Invalid input");
            exit(1);
        }
    }

    for(uint32_t i = 0; i < *size; ++i)
    {
        if(fscanf(file, "%u", &array_b[i]) != 1)
        {
            perror("Invalid input");
            exit(1);
        }
    }

    if(fclose(file) == EOF)
    {
        perror("Error closing file");
        exit(1);
    }
}


void add_to_second_array(uint32_t *array_a, uint32_t *array_b, uint32_t size, uint32_t *new_size)
{
    *new_size = size;
    for(uint32_t i = 0; i < size; ++i)
    {
        if(bit_parity(array_a[i]) == 0)
        {
            if(*new_size == MAX)
            {
                perror("Array is full");
                break;
            }

            array_b[*new_size] = array_a[i];
            (*new_size)++;
        }
    }
}


void print_array(uint32_t *array, uint32_t size)
{
    for(uint32_t i = 0; i < size; ++i)
    {
        printf("%u ", array[i]);
    }
    printf("\n");
}


int main(void)
{
    uint32_t array_a[MAX], array_b[MAX], size = 0, new_size = 0;

    read_arrays(array_a, array_b, &size, "1.txt");

    add_to_second_array(array_a, array_b, size, &new_size);

    print_array(array_a, size);

    print_array(array_b, new_size);

    return 0;
}
