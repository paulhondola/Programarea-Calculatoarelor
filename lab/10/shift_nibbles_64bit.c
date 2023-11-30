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

void show_bits(uint64_t number)
{
    uint64_t mask = 1UL << (sizeof(number) * 8 - 1);
    while(mask)
    {
        putchar(((number & mask) != 0) + '0');
        mask >>= 1;
    }
    putchar('\n');
}

void print_numbers(uint64_t count)
{
    for(int i = sizeof(count) * 8 - 1; i >= 0 ; i--)
        putchar((i % 8) + '0');
    putchar('\n');  
}

uint64_t move_nibbles(uint64_t num)
{
    uint64_t mask;
    uint64_t odd, even, odd_index, even_index;

    mask = 1UL << (sizeof(num) * 8 - 1);

    odd = 0;
    odd_index = 0;

    even = 0;
    even_index = 3;

    /*
    7 << 7
    5 << 6
    3 << 5
    1 << 4

    6 >> 3
    4 >> 2
    2 >> 1
    0 >> 0

    63 - 63
    61 - 62
    59 - 61
    57 - 60

    62 - 59
    60 - 58
    58 - 57
    56 - 56
    */
    
    for(int i = 0; i < sizeof(num) * 8; i += 8)
    {
        odd_index = 0;
        even_index = 3;
        
        for(int j = 7; j >= 0; j--, mask >>= 1)
        {
            if(j % 2)
            {
                odd |= (num & mask) << odd_index;
    
                odd_index++;
            }

            else
            {
                even |= (num & mask) >> even_index;

                even_index--;
            }
        }
    }
    

    return odd | even;
}

int main(void)
{
    uint64_t n = 0xFEDCBA9876543210;

    printf("%llX\n", n);
    printf("%llu\n", n);
    show_bits(n);
    
    print_numbers(n);

    show_bits(move_nibbles(n));

    return 0;
}