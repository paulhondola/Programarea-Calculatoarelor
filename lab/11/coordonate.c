/*
Se citește un n oricât de mare și apoi n puncte în plan, definite prin coordonatele lor (x,y). Să se afișeze toate punctele, grupate în seturi de puncte care sunt pe aceeași linie orizontală (au același y). Memoria folosită va fi minimă.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} Punct;

int input(Punct *puncte, unsigned int n)
{
    for(unsigned int i = 0; i < n; i++)
    {
        printf("punctul %u\n", i + 1);

        printf("x = ");
        if(scanf("%f", &puncte[i].x) != 1)
            return -1;

        printf("y = ");
        if(scanf("%f", &puncte[i].y) != 1)
            return -1;
    }

    //printf("Nu a puscat\n");
    return 1;
}

void sort_y(Punct *puncte, unsigned int n)
{
    unsigned short int ok = 0;
    Punct aux;
    do
    {
        ok = 0;
        for(unsigned int i = 0; i < n - 1; i++)
        {
            if(puncte[i].y > puncte[i + 1].y)
            {
                aux = puncte[i];
                puncte[i] = puncte[i + 1];
                puncte[i + 1] = aux;
                ok = 1;
            }
        }
    } while (ok);
    
}

int main(void)
{
    unsigned int n = 0;
    Punct *puncte = NULL; 

    printf("n = ");
    scanf("%u", &n);

    puncte = malloc(n * sizeof(Punct));
    
    if(puncte == NULL)
    {
        printf("eroare la alocarea memoriei\n");
        return -1;
    }

    if(input(puncte, n) == -1)
        return -1;
    
    for(unsigned int i = 0; i < n; i++)
        printf("punctul %u: (%.2f, %.2f)", i + 1, puncte[i].x, puncte[i].y);

    sort_y(puncte, n);

    printf("\nsetul %u: (%.2f, %.2f)\n", 1, puncte[0].x, puncte[0].y);

    for(unsigned int i = 1; i < n; i++)
        if(puncte[i - 1].y == puncte[i].y)
            printf(" (%.2f, %.2f)", puncte[i].x, puncte[i].y);
        else
            printf("setul %u: (%.2f, %.2f)", i + 1, puncte[i].x, puncte[i].y);

    putchar('\n');

    free(puncte);

    return 0;
}