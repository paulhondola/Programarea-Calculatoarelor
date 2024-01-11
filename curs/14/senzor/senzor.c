#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    int valoare;
} SENZOR_DATA;


int main(void)
{
    SENZOR_DATA senzor_data;
    while(feof(stdin) == 0) // cat timp nu am ajuns la sfarsitul fisierului
    {
        printf("Introduceti o valoare: ");
        scanf("%d", &senzor_data.valoare);
        printf("Valoarea introdusa este: %d\n", senzor_data.valoare);
    }

    return 0;
}