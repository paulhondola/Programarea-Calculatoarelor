// Scrieţi o funcție care ia ca parametru un întreg fără semn şi returnează numărul de biţi de 1 din reprezentarea sa.

#include <stdio.h>
#include <stdint.h>

unsigned int count_bits(unsigned int num)
{
    unsigned int count = 0, mask = 1 << (sizeof(num) * 8 - 1);

    while(mask != 0)
    {
        count += (num & mask) != 0;
        mask >>= 1;
    }

    return count;
}

int main(void)
{
    unsigned int num = 0;
    printf("n = ");
    scanf("%u", &num);
    printf("%u\n", count_bits(num));

    return 0;
}