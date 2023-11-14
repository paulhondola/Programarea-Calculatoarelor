#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;

    printf ("value of p: %p\n", p);

    p = malloc(sizeof(int));

    *p = 5;

    printf ("value of p: %p\n", p);

    free(p);

    printf ("value of p: %p\n", p);

    return 0;
}