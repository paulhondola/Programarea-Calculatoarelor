#include <stdio.h>
#include <stdlib.h>

void read_array(int *len, int **array)
{
    scanf("%d", len);

    *array = malloc((*len) * sizeof(int));

    for(int i = 0; i < *len; i++)
        scanf("%d", array[i]);
}

int main(void)
{
    int len = 0, *array = NULL;

    read_array(&len, &array);

    printf("%d", array[0]);

    free(array);

    return 0;
}