/*
2. Se citesc m și n, iar apoi elementele întregi ale unei matrice a[m][n]. Matricea se va aloca dinamic, astfel încât memoria folosită se fie minimă. Se cere să se sorteze liniile matricei, astfel încât sumele elementelor de pe fiecare linie să fie crescătoare. Să se testeze dacă matricea sortată după linii are și coloanele sortate crescător, după sumele elementelor de pe fiecare coloană.
*/

#include <stdio.h>
#include <stdlib.h>

int **read_matrix(int *lines, int *columns)
{
    if(scanf("%d %d", lines, columns) != 2)
    {
        perror("Invalid input");
        exit(1);
    }

    int **matrix = (int **)malloc(*lines * sizeof(int *));

    if(matrix == NULL)
    {
        perror("Not enough memory");
        exit(1);
    }

    for(int i = 0; i < *lines; i++)
    {
        matrix[i] = (int *)malloc(*columns * sizeof(int));

        if(matrix[i] == NULL)
        {
            perror("Not enough memory");
            exit(1);
        }
    }

    for(int i = 0; i < *lines; i++)
        for(int j = 0; j < *columns; j++)
            scanf("%d", &matrix[i][j]);

    return matrix;
}


int *sum_lines(int **matrix, int lines, int columns)
{
    int *sums = (int *)malloc(lines * sizeof(int));

    if(sums == NULL)
    {
        perror("Not enough memory");
        exit(1);
    }

    for(int i = 0; i < lines; i++)
    {
        sums[i] = 0;
        for(int j = 0; j < columns; j++)
            sums[i] += matrix[i][j];
    }

    return sums;
}


void sort_lines(int **matrix, int lines, int columns)
{
    int *sums = sum_lines(matrix, lines, columns);
    int ok = 0;
    int swap;

    do
    {
        ok = 0;
        for(int i = 0; i < lines - 1; i++)
            if(sums[i] > sums[i + 1])
            {
                swap = sums[i];
                sums[i] = sums[i + 1];
                sums[i + 1] = swap;

                for(int j = 0; j < columns; j++)
                {
                    swap = matrix[i][j];
                    matrix[i][j] = matrix[i + 1][j];
                    matrix[i + 1][j] = swap;
                }

                ok = 1;
            }
    } while (ok);

    free(sums);
}


void free_matrix(int **matrix, int lines)
{
    for(int i = 0; i < lines; i++)
        free(matrix[i]);
    free(matrix);
}


void print_matrix(int **matrix, int lines, int columns)
{
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}


int main(void)
{
    int lines, columns, **matrix = NULL;

    matrix = read_matrix(&lines, &columns);

    print_matrix(matrix, lines, columns);

    sort_lines(matrix, lines, columns);

    printf("\n");

    print_matrix(matrix, lines, columns);

    free_matrix(matrix, lines);

    return 0;
}
