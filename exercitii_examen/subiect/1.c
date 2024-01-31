/*
1. Rotirea la stânga, cu o poziție, a biților unui număr, înseamnă deplasarea biților la stânga cu o poziție și inserarea fostului bit din stânga pe prima poziția din dreapta. Analogic se definește rotirea la dreapta.
	Să se scrie o funcție care primește două argumente: o valoare v pe 8 biți fără semn și un număr întreg n. Funcția va roti biții din v cu n poziții și va returna numărul rezultat. Dacă n>0, rotirea se face la stânga, altfel va fi la dreapta.
	Să se testeze funcția cu v și n citite de la tastatură. Se vor afișa în binar v inițial și rezultatul funcției.
	Exemplu: 1010.0110 rotit la stânga cu 2 poziții => 1001.1010
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void show_bits(uint8_t value)
{
    uint8_t mask = 1 << 7;

    while(mask)
    {
        printf("%d", (value & mask) != 0);

        mask >>= 1;
    }

    printf("\n");
}


uint8_t rotate(uint8_t value, int64_t shifts)
{
    shifts %= 8;

    // TODO : rotate left
    if(shifts > 0)
    {
        uint8_t mask = 1 << 7;
        uint8_t front_bit;
        for(int64_t i = 0; i < shifts; i++)
        {
            front_bit = (value & mask) != 0;
            value <<= 1;
            value |= front_bit;
        }
    }

    // TODO : rotate right
    else
    {
        uint8_t back_bit;
        for(int64_t i = 0; i < -shifts; i++)
        {
            back_bit = (value & 1) != 0;
            value >>= 1;
            value |= back_bit << 7;
        }
    }

    return value;
}

int main(void)
{
    uint8_t value;
    int64_t shifts;

    printf("value = ");
    scanf("%hhu", &value);

    printf("shifts = ");
    scanf("%lld", &shifts);

    show_bits(value);

    value = rotate(value, shifts);

    show_bits(value);
    return 0;
}
