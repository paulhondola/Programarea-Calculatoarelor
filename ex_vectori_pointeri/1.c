// Să se scrie o funcție care ia un număr fără semn n și
// returnează numărul de segmente de biți consecutivi egali.
// Exemplu: 000100 are 3 segmente: 000, 1, 00, deci programul va returna 3

#include <stdio.h>
#include <stdint.h>

uint16_t seg_consect_bits(uint64_t num)
{
    uint16_t seg = 0;
    uint64_t mask = 1UL << 63;
    uint8_t prev_bit = 0, current_bit = 0;

    // check MSB - prev

    prev_bit = (num & mask) != 0;
    mask >>= 1;
    seg++;

    while(mask)
    {
        current_bit = (num & mask) != 0;
        if(prev_bit != current_bit)
        {
            prev_bit = current_bit;
            seg++;
        }

        mask >>= 1;
    }
    return seg;
}

int main(void)
{
    uint64_t num;
    scanf("%llu", &num);
    printf("%hu\n", seg_consect_bits(num));
    return 0;
}