/*
1. Se consideră un număr pe 64 de biți citit de la tastatură.
Să se afișeze numărul transformat astfel: la nivel de octet, biții de rang par sunt mutați în nibble-ul inferior, iar
biții de rang impar sunt mutați în nibble-ul superior.
Pentru afișarea numărului și al rezultatului la nivel de biți se va implementa o funcție dedicată.
ex. octet = abcd efgh => aceg bdfh

7 6 5 4 3 2 1 0
a b c d e f g h

7 5 3 1 6 4 2 0
a c e g b d f h

impar - pozitia devine

7 << 7
5 << 6
3 << 5
1 << 4

6 >> 3
4 >> 2
2 >> 1
0 >> 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void show_bits(uint8_t number)
{
    uint8_t mask = 1 << (sizeof(number) * 8 - 1);
    while(mask)
    {
        putchar(((number & mask) != 0) + '0');
        mask >>= 1;
    }
    putchar('\n');
}

void print_numbers(uint8_t count)
{
    for(uint8_t i = 0; i < sizeof(count) * 8; i++)
        putchar(sizeof(count) * 8 - i - 1 + '0');
    putchar('\n');  
}

uint8_t move_nibbles(uint8_t num)
{
    uint8_t mask, index;
    uint8_t odd, even, odd_index, even_index;

    mask = 1 << 7;
    index = 7;

    odd = 0;
    odd_index = 0;

    even = 0;
    even_index = 3;
    while(mask)
    {
        if(index % 2)
        {
            odd |= (num & mask) << odd_index;
 
            odd_index++;
        }

        else
        {
            even |= (num & mask) >> even_index;

            even_index--;
        }

        index--;
        mask >>= 1;
    }

    return odd | even;
}

int main(void)
{
    uint8_t n = 29;

    printf("%x\n", n);
    printf("%d\n", n);
    show_bits(n);
    print_numbers(n);

    show_bits(move_nibbles(n));

    return 0;
}