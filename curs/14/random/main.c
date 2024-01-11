#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_VALUE 500000
#define CHUNK 1024

// {1262, 52562, 52515, 19581589, 5151} -> "1262 52562 52515 19581589 5151"


void init_array(int *array, const int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % MAX_VALUE;
    }
}


char *array_to_string(const int *array, const int size)
{
    char *string = malloc(sizeof(char));

    string[0] = 0;

    char aux[10];

    long long int allocated_size = 1;

    for(int i = 0; i < size; i++)
    {
        sprintf(aux, "%d ", array[i]);

        if(strlen(string) + strlen(aux) + 2 > allocated_size)
        {
            allocated_size += CHUNK;

            string = realloc(string, allocated_size * sizeof(char));
        }

        strcat(string, aux);
    }


    // ....... _ /0

    long long int string_size = strlen(string) - 1;

    string[string_size] = 0;

    // 1024 1024 1024

    string = realloc(string, (string_size + 1) * sizeof(char));

    return string;
}


int main(void)
{
    int array[MAX_SIZE];
    int size = MAX_SIZE;

    init_array(array, size);

    char *result = array_to_string(array, size);

    printf("%s\n", result);

    free(result);

    return 0;
}
