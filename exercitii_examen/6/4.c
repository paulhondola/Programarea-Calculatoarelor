#include <stdio.h>
#include <stdlib.h> 

int **read_matrix(int *lines, int *collumns)
{
    int **matrix;
    int i, j;

    if(scanf("%d %d", lines, collumns) != 2)
    {
        perror("Error reading lines and collumns");
        exit(1);
    }

    matrix = (int **)malloc(*lines * sizeof(int *));

    if(matrix == NULL)
    {
        perror("Error allocating memory for matrix");
        exit(1);
    }

    for (i = 0; i < *lines; i++)
    {
        matrix[i] = (int *)malloc(*collumns * sizeof(int));
        

        for (j = 0; j < *collumns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

int main(void)
{


    return 0;
}