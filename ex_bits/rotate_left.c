#include <stdint.h>
#include <stdio.h>

void show_bits_32(uint32_t num)
{
    uint32_t mask = 1 << 31;

    while(mask)
    {
        printf("%hhu ", (num & mask) != 0);
        mask >>= 1;
    }
    printf("\n");
}

uint32_t rotate_left(uint32_t input)
{
    return (input >> 1) | ((input & 1) << 31);
}

int main(void)
{
    uint32_t num = 0;
    scanf("%u", &num);
    show_bits_32(num);
    show_bits_32(rotate_left(num));

    return 0;
}