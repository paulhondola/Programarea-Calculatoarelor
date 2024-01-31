/*
Se citesc numere până la întâlnirea numărului 0. Să se afișeze aceste numere în ordine inversă. Programul va folosi doar minimul necesar de memorie
*/

#include <stdio.h>
#include <stdlib.h>

#define CHUNK 100

int main(void)
{
    int *numbers = NULL;
    int size = 0;
    int allocated_size = 0;
    int input = 0;

    while(1)
    {
        if(scanf("%d", &input) != 1)
        {
            break;
        }

        if(input == 0)
        {
            break;
        }

        if(size == allocated_size)
        {
            allocated_size += CHUNK;
            numbers = realloc(numbers, allocated_size * sizeof(int));

            if(numbers == NULL)
            {
                printf("Not enough memory\n");
                return 1;
            }
        }

        numbers[size++] = input;
    }

    for(int i = size - 1; i >= 0; i--)
    {
        printf("%d ", numbers[i]);
    }

    if(numbers != NULL)
        free(numbers);
    return 0;
}
