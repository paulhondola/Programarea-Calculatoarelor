#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10000

void generate_random(int *array)
{
    srand(time(NULL));

    for(int i = 0; i < MAX; i++)
    {
        array[i] = rand() % MAX;
    }
}

int main(void)
{
    int array[MAX];

    generate_random(array);

    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}