// Scrieți o funcție care primește ca parametru 2 numere întregi pe 1 byte fără semn (n1 și n2)
// și returnează un număr întreg pe 2 bytes (n) format din cele două numere ca și parte cea mai semnificativă (n2)
// și parte mai putin semnficativă (n1)
//exemplu: n1 = 1100 1011, n2 = 0110 0111 -> n = 0110 0111 1100 1011

#include <stdio.h>
#include <stdint.h>

void show_bits_8(uint8_t num)
{
    uint8_t mask = 1U << 7;
    for(uint8_t i = 0; i < 8; i++, mask >>= 1)
    {
        printf("%hhu", (num & mask) != 0);
        if (i % 4 == 3)
            printf(" ");
    }
    printf("\n");
}

void show_bits_16(uint16_t num)
{
    uint16_t mask = 1U << 15;
    for(uint8_t i = 0; i < 16; i++, mask >>= 1)
    {
        printf("%hhu", (num & mask) != 0);
        if (i % 4 == 3)
            printf(" ");
    }
    printf("\n");
}

uint16_t combine(uint8_t n1, uint8_t n2)
{
    return n2 << 8 | n1;
}

int main(void)
{
    uint8_t n1 = 0, n2 = 0;
    printf("n1 = ");
    scanf("%hhu", &n1);
    printf("n2 = ");
    scanf("%hhu", &n2);

    show_bits_8(n1);
    show_bits_8(n2);
    show_bits_16(combine(n1, n2));
    return 0;
}