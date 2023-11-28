#include <stdio.h>
#include <stdlib.h>

void alloc_2(int **arr)
{
    *arr = calloc(5 * sizeof(int), 0);
}

int *alloc(int size)
{
    int *dyn_arr = NULL;

    dyn_arr = calloc(size * sizeof(int), 0);

    return dyn_arr;
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *dyn_arr = NULL;
    int *dyn_arr2 = NULL;


    // in main
    dyn_arr = calloc(5 * sizeof(int), 0);

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", dyn_arr[i]);
    }

    // in functie void
    dyn_arr2 = alloc(6);

    printf("%p\n", arr);
    printf("%p\n", dyn_arr);
    printf("%p\n", dyn_arr2);

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", dyn_arr2[i]);
    }

   

    return 0;
}