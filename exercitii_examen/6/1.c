#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


uint64_t * read_array(uint64_t *count)
{
    uint64_t *array = NULL;
    uint64_t i;

    if(scanf("%llu", count) != 1)
    {
        perror("invalid input");
        exit(EXIT_FAILURE);
    }

    array = (uint64_t *)malloc(*count * sizeof(uint64_t));

    if(array == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < *count; ++i)
        if(scanf("%llu", &array[i]) != 1)
        {
            perror("invalid input");
            exit(EXIT_FAILURE);
        }

    return array;
}


void print_array(uint64_t *array, uint64_t count)
{
    for (uint64_t i = 0; i < count; ++i)
        printf("%llu ", array[i]);
    printf("\n");
}


uint64_t count_bits(uint64_t x)
{
    uint64_t mask = 1ULL << 63;
    uint64_t count = 0;

    while(mask)
    {
        if((x & mask) != 0)
            count++;
        mask >>= 1;
    }

    return count;
}


void show_bits(uint64_t x)
{
    uint64_t mask = 1ULL << 63;

    while(mask)
    {
        printf("%d", (x & mask) != 0);
        mask >>= 1;
    }
    printf("\n");
}


void print_array_bits(uint64_t *array, uint64_t count)
{
    for (uint64_t i = 0; i < count; ++i)
        show_bits(array[i]);
}


uint64_t *create_bit_count_array(uint64_t *array, uint64_t count)
{
    uint64_t *bit_array = malloc(count * sizeof(uint64_t));

    if(bit_array == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (uint64_t i = 0; i < count; ++i)
        bit_array[i] = count_bits(array[i]);

    return bit_array;
}


int main(void)
{
    uint64_t count;
    uint64_t *array = read_array(&count);

    print_array(array, count);

    print_array_bits(array, count);

    uint64_t *bit_array = create_bit_count_array(array, count);

    print_array(bit_array, count);


    free(array);
    free(bit_array);
    
    return 0;
}
