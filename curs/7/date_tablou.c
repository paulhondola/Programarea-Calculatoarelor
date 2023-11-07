#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define MAX 1000

int read_array_stdin(uint32_t arr[], int size)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(scanf("%d", &arr[i]) != 1)
            break;
    }
    return i;
}

void read_array_random(uint32_t arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % MAX;
    }
}

void print_array(uint32_t arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    static uint32_t array[SIZE];

    //srand(time(NULL));

    //read_array_random(array, SIZE);

    int new_size = read_array_stdin(array, SIZE);

    print_array(array, new_size);

    return 0;
}