#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

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


int main(void)
{
    uint8_t a = 0, b = 0;
    uint32_t sum = 0, dif = 0;
    uint32_t result = 0;

    if(scanf("%hhu %hhu", &a, &b) != 2)
    {
        perror("Invalid input");
        exit(-1);
    }

    sum = a + b;
    dif = (uint32_t)abs(a - b);

    result = sum << 16 | dif;

    printf("Suma: %u\n", sum);
    printf("Diferenta: %u\n", dif);
    printf("Rezultat: %u\n", result);

    print_bits(result);

    return 0;
}
