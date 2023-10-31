// Scrieți o funcție care primește ca
// și argumente 4 numere întregi pe 1 byte fără semn
// (n3, n2, n1, n0) și returnează un număr întreg pe 4 bytes (n) format
// din cele 4 numere unde n3 este partea cea mai semnificativă și n0 partea cea mai puțin semnficativă
//exemplu:
// n3 = 1111 0000,
// n2 = 0011 1100,
// n1 = 1010 0011,
// n0 = 0010 1101 ->
// n = 1111 0000 0011 1100 1010 0011 0010 1101

#include <stdint.h>
#include <stdio.h>

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

void show_bits_32(uint32_t num)
{
    uint32_t mask = 1U << 31;
    for(uint8_t i = 0; i < 32; i++, mask >>= 1)
    {
        printf("%hhu", (num & mask) != 0);
        if (i % 4 == 3)
            printf(" ");
    }
    printf("\n");
}

uint32_t combine(uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3)
{
    const uint8_t SIZE = 8;
    return (n3 << SIZE * 3) | (n2 << SIZE * 2) | (n1 << SIZE) | n0;
}


int main(void)
{
    uint8_t n0 = 0, n1 = 0, n2 = 0, n3 = 0;
    printf("n0 = ");
    scanf("%hhu", &n0);
    printf("n1 = ");
    scanf("%hhu", &n1);
    printf("n2 = ");
    scanf("%hhu", &n2);
    printf("n3 = ");
    scanf("%hhu", &n3);

    show_bits_8(n0);
    show_bits_8(n1);
    show_bits_8(n2);
    show_bits_8(n3);

    show_bits_32(combine(n0, n1, n2, n3));
    return 0;
}