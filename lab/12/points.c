#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 4096

typedef struct
{
    int x;
    int y;
} POINTS_T;

POINTS_T *input_array(uint64_t *size)
{
    POINTS_T *array = NULL;
    POINTS_T input;
    *size = 0;

    uint64_t allocated_size = 0;

    while(1)
    {
        if(scanf("%d.%d", &input.x, &input.y) != 2)
        {
            printf("end of input\n");
            break;
        }

        if(*size == allocated_size)
        {
            allocated_size += CHUNK;

            array = realloc(array, allocated_size * sizeof(POINTS_T));

            if(array == NULL)
            {
                printf("out of memory <3\n");
                return NULL;
            }
        }

        array[(*size)++] = input;
    }

    return array;
}


void print_points_first_quadrant(POINTS_T *array, uint64_t size)
{
    for(uint64_t i = 0; i < size; i++)
    {
        if((array[i].x >= 0 && array[i].y >= 0))
        {
            printf("%llu -> %d.%d\n", i, array[i].x, array[i].y);
        }
    }
}

int main(void)
{
    POINTS_T *array = NULL;

    uint64_t size = 0;

    array = input_array(&size);

    print_points_first_quadrant(array, size);

    free(array);
    return 0;
}
