#include <stdio.h>
#include <stdlib.h>
#define LEN 16

int main(void)
{
    int *int_ptr = NULL;
    int *int_dyn_array = NULL;

    int_ptr = malloc(sizeof(int));

    int_dyn_array = malloc(LEN * sizeof(int));

    *int_ptr = 5;

    printf ("value of int_ptr: %d\n", *int_ptr);

    free(int_ptr);

    for (int i = 0; i < LEN; i++)
    {
        int_dyn_array[i] = i * i;
    }

    printf ("array values: ");
    for (int i = 0; i < LEN; i++)
    {
        printf ("%d ", int_dyn_array[i]);
    }

    free(int_dyn_array);

    printf ("\n");
    return 0;
}
