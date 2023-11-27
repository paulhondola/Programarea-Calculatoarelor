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
        scanf("%f", &puncte[i].x);

        printf("y = ");
        scanf("%f", &puncte[i].y);
    }

    printf("Nu a puscat\n");
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

void same_line(Punct *puncte, unsigned int n)
{
    
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
        printf("punctul %u: (%.2f, %.2f)\n", i + 1, puncte[i].x, puncte[i].y);

    sort(puncte, n);

    for(unsigned int i = 0; i < n; i++)
        printf("punctul %u: (%.2f, %.2f)\n", i + 1, puncte[i].x, puncte[i].y);

    //same_line(puncte, n);

    free(puncte);

    return 0;
}