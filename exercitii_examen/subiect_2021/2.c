#include <stdio.h>
#include <stdlib.h>

int ** read_matrix(int *lines, int *col)
{
    int **matrix = NULL;

    if(scanf("%d %d", lines, col) != 2)
    {
        perror("invalid input");
        exit(1);
    }

    matrix = malloc((*lines) * sizeof(int *));

    for(int i = 0; i < *lines; i++)
    {
        matrix[i] = malloc((*col) * sizeof(int));
    }

    for(int i = 0; i < *lines; i++)
        for(int j = 0; j < *col; j++)
            if(scanf("%d", &matrix[i][j]) != 1)
            {
                perror("invalid matrix input");
                exit(2);
            }

    return matrix;
}


void print_matrix(int lines, int col, int **matrix)
{
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }       
}


void free_matrix(int lines, int col, int **matrix)
{
    for(int i = 0; i < lines; i++)
        free(matrix[i]);

    free(matrix);
}




int main(void)
{
    int lines = 0, col = 0, **matrix = NULL;

    matrix = read_matrix(&lines, &col);

    print_matrix(lines, col, matrix);

    free_matrix(lines, col, matrix);

    return 0;
}
