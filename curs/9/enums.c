#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

enum saptamana {
    // constantele sunt de tip int
    Luni = 4,
    Marti = 78,
    Miercuri = 15,
    Joi = 16,
    Vineri = 0,
    Sambata = 1,
    Duminica = 2, // 6
};


int main(void)
{
    // tipul enum

    enum saptamana zi = Luni;
    
    zi = Marti;

    printf("%d\n", zi);


    if(zi == Marti)
        printf("ziua e marti\n");
    else
        printf("ziua nu e marti\n");



    switch(zi)
    {
        case Luni:
        case Marti:
        {
            printf("ziua e luni sau marti\n");
            break;
        }
        case Miercuri:
        case Joi:
        default:
        {
            printf("ziua nu e luni sau marti\n");
            break;
        }
    }

    return 0;
}