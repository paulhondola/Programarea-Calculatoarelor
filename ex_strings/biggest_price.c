// 10. Se citesc prin redirectare dintr-un fișier linii de forma:
/*
produs,preț
unde produsul are maxim 15 caractere și poate conține spații, iar prețul e un număr real. Se cere să se afișeze produsul cu cel mai mare preț. 
*/

// ce pl mea,69.420
// ai de pl mea,43.24

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16

typedef struct {
    char name[MAX];
    float price;
} Product;

int main(void)
{
    Product input, max;
    char space = 0;
    // initializare max
    
    max.name[0] = 0;
    max.price = 0;

    // citim pana la EOF

    while(1)
    {
        // citim numele produsului pana la virgula

        input.name[0] = 0;

        unsigned int index = 0;
        while(1)
        {
            if(scanf("%c", &input.name[index]) != 1)
            {
                printf("error\n");
                return -1;
            }
            if(input.name[index] == ',')
            {
                input.name[index] = 0;
                break;
            }

            index++;
        }

        scanf("%f", &input.price);
        
        printf("%s %f\n", input.name, input.price);

        // comparam pretul cu maximul

        if(input.price > max.price)
        {
            strcpy(max.name, input.name);
            max.price = input.price;
        }

        // citim spatiul dintre linii

        space = getchar();

        // daca am ajuns la EOF, iesim din while

        if(space == EOF)
            break;
    }

    printf("Max: %s %f\n", max.name, max.price);

    return 0;
}
