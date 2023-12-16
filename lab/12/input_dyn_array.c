#include <stdio.h>
#include <stdlib.h>
#define CHUNK 100

int *input_array(int *size)
{
    int *array = 0;

    int input = 0;

    int allocated_size = 0;

    *size = 0;

    while(1)
    {
        if(scanf("%d", &input) != 1)
        {
            printf("end of input\n");
            break;
        }

        if(*size == allocated_size)
        {
            allocated_size += CHUNK;
            array = realloc(array, allocated_size * sizeof(int));

            if(array == NULL)
            {
                printf("realloc failed\n");
                exit(1);
            }
        }

        array = realloc(array, allocated_size * sizeof(int));

        if(array == NULL)
        {
            printf("realloc failed\n");
            exit(1);
        }

        array[(*size)++] = input;

        
    }

    return array;
}


int main(void)
{
    int *array = NULL;
    int size = 0;

    array = input_array(&size);

    for(int i = 0; i < size; i++)
    {
        printf("%d -> %d\n", i, array[i]);
    }

    free(array);

    return 0;
}
