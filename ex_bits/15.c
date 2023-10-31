#include <stdio.h>
#include <stdint.h>

/*
 Să se scrie o funcție care ia un număr fără semn n și returnează
 numărul de segmente de biți consecutivi egali.
 Exemplu: 000100 are 3 segmente: 000, 1, 00, deci programul va returna 3
 */

uint64_t seg_consec(uint64_t num)
{
    uint64_t seg = 1, mask = 1UL << 63;
    uint8_t prev = (num & mask) != 0; // 0 pt ca numarul este fara semn

    mask >>= 1;
    while(mask)
    {
        if (prev != ((num & mask) != 0))
        {
            prev = (num & mask) != 0;
            seg++;
        }

        mask >>= 1;
    }

    return seg;
}

int main(void)
{
    uint64_t num = 0b00101010;
    printf("%llu", seg_consec(num));
    return 0;
}