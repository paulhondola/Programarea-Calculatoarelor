// 234.256 226.2626 22.22 0.25 2.6622

// array = {234.256, 226.2626, 22.22, 0.25, 2.6622} -> size = 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_FLOAT_SIZE 100


int create_float_array(char *string, float *array, int max_size)
{
    int real_size = 0;
    float input = 0;

    char *token = strtok(string, " ");

    while(token != NULL)
    {
        input = strtod(token, NULL);

        // numar = strtol(string, NULL, 10)

        if(real_size == max_size)
        {
            break;
        }

        array[real_size++] = input;

        token = strtok(NULL, " ");
    }

    return real_size;
}


void print_array(float *array, int size)
{
    printf("size: %d\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", array[i]);
    }

    printf("\n");
}


int main(void)
{
    char string[] = "234.256 226.2626 22.22 0.25 2.6622";

    float array[MAX_SIZE];

    int size = create_float_array(string, array, MAX_SIZE);

    print_array(array, size);

    return 0;
}