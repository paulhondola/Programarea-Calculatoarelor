#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

#define SIZE 1000

void build_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % MAX;
    }
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main(void) 
{
    srand(time(NULL));

    int array[SIZE];
    
    build_array(array, SIZE);

    print_array(array, SIZE);
    
    return 0;
}
