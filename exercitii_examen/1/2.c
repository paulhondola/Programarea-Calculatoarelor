// abcd efgh -> efgh abcd
// abcd >>= 4
// efgh <<= 4
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_bits(uint32_t number)
{
    uint32_t mask = (uint32_t) 1 << 31;

    while(mask)
    {
        printf("%u", (number & mask) != 0);
        mask >>= 1;
    }

    printf("\n");
}

uint32_t invert_nibble(uint32_t number)
{
    // 1234 5678 1234 5678 

    // n1 n2 n1 >> 4 n2 << 4


    uint32_t front_mask = 0xf0;
    uint32_t end_mask = 0x0f;

    uint32_t front = 0;
    uint32_t end = 0;

    uint32_t cleaner = 0xff;

    for(uint8_t i = 0; i < sizeof(uint32_t); i++)
    {
        front = number & front_mask;
        end = number & end_mask;

        front >>= 4;
        end <<= 4;

        number &= ~cleaner;

        number = number | front | end;

        cleaner <<= 8;
        front_mask <<= 8;
        end_mask <<= 8;
    }

    return number;
}

int main(void)
{
    uint32_t number = 0;

    if(scanf("%u", &number) != 1)
    {
        perror("Invalid input");
        exit(-1);
    }

    print_bits(number);
    print_bits(invert_nibble(number));

    return 0;
}
