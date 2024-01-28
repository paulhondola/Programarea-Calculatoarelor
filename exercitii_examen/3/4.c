/*
Sa se scrie o implementare proprie a functiei strcat (denumita mystrcat) din biblioteca standard string.h cu diferenta ca rezultatul concatenarii este returnat ca un string alocat dinamic. Pentru implementare, se interzice utilizarea oricarei functii standard de prelucrare de string-uri din biblioteca string.h. Pentru simplificarea acestei cerinte se recomanda nici sa nu se includa deloc in program biblioteca string.h. Functia se va testa prin string-uri citite de la tastatura. Programul se va termina fara memory leaks. Se vor verifica si testa corespunzator toate cazurile de eroare posibile.
*/

#include <stdio.h>
#include <stdlib.h>

#define CHUNK 10

// ana/0 are/0 -? anaare/0 -> strlen(1) + strlen(2) + 1

char *my_strcat(char *front, char *back)
{
    char *result = NULL;

    int front_len = 0;
    int back_len = 0;
    int result_len = 0;
    int allocated_len = 0;

    while(1)
    {
        if(front[front_len] == '\0')
        {
            break;
        }

        if(result_len == allocated_len)
        {
            allocated_len += CHUNK;
            result = realloc(result, allocated_len * sizeof(char));
        }

        if(result == NULL)
        {
            perror("realloc");
            exit(1);
        }

        result[result_len++] = front[front_len++];
    }

    while(1)
    {
        if(back[back_len] == '\0')
        {
            if(result_len == allocated_len)
            {
                allocated_len += 1;
                result = realloc(result, allocated_len * sizeof(char));
            }

            if(result == NULL)
            {
                perror("realloc");
                exit(1);
            }

            result[result_len] = '\0';

            break;
        }

        if(result_len == allocated_len)
        {
            allocated_len += CHUNK;
            result = realloc(result, allocated_len * sizeof(char));
        }

        if(result == NULL)
        {
            perror("realloc");
            exit(1);
        }

        result[result_len++] = back[back_len++];
    }

    return result;
}

int main(void)
{
    char *s1 = "ana ";
    char *s2 = "are ";
    char *s3 = "mere";

    char *result = my_strcat(s1, s2);
    result = my_strcat(result, s3);

    printf("%s\n", result);

    free(result);

    return 0;
}
