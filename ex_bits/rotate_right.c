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

uint32_t rotate_right_bit(uint32_t input)
{
    return (input >> 1) | (input & 0x1);
}

uint32_t rotate_right_nibble(uint32_t input)
{
    return (input >> 4) | (input & 0xf);
}

uint32_t rotate_right_byte(uint32_t input)
{
    return (input >> 8) | (input & 0xff);
}

int main(void)
{
    uint32_t num = 0;
    scanf("%u", &num);
    show_bits_32(num);
    show_bits_32(rotate_right_bit(num));
    show_bits_32(rotate_right_nibble(num));
    show_bits_32(rotate_right_byte(num));

    return 0;
}