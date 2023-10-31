#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // operatori pe biti

    // ./exe - stdin - tastatura ca default
    // ./exe < input.txt - stdin - fisierul input.txt

    // ./exe - stdout - terminalul ca default
    // ./exe > output.txt - stdout - fisierul output.txt


    // bitul 0 - 1
    // nibble - 4 biti
    // byte - 8 biti

    // least significant byte - LSB - bitul 0
    // most significant byte - MSB - bitul ....

    // operatorii pe biti - utilizati pt a putea prelucra binar date la nivel de bit

    // & - AND - SI

    uint8_t a = 0b10011101;
    uint8_t b = 0b11010111;

    // a = 1001 1101
    // b = 1101 0111

    // 1 & 1 = 1
    // 1 & 0 = 0
    // 0 & 1 = 0
    // 0 & 0 = 0

    // se ia fiecare bit de pe aceeasi pozitie si se face operatia de AND

    // a & b = 1001 0101

    printf("a & b = %d\n", a & b);

    // | - OR - SAU

    // 1 | 1 = 1
    // 1 | 0 = 1
    // 0 | 1 = 1
    // 0 | 0 = 0

    // a | b = 1101 1111

    printf("a | b = %d\n", a | b);

    // ~ - NOT - NEGATIE

    // ~1 = 0
    // ~0 = 1

    printf("~a = %d\n", ~a);

    // << si >> - OPERATORI DE DEPLASARE

    a = 0b11010101;

    // a << 1 - deplasare la stanga cu 1 bit
    // 1101 0101 << 1 = /1/ 1010 101 + 0
    // deplasarea de 8 ori (pe uint8) - numarul devine 0

    printf("a << 1 = %d\n", a << 1);

    // a >> 1 - deplasare la dreapta cu 1 bit
    // 1101 0101 >> 1 = 0 + 110 1 010 - /1/






    // deplasarea unui numar cu semn - la dreapta se adauga biti de semn

    // S101 0101 ----> SS10 1010

    // S = 1 - numar negativ
    // S = 0 - numar pozitiv

    // deplasarea unui numar cu semn - la stanga se adauga biti de 0

    // S101 0101 ----> 1010 1010

    // int a = 0110 0101 
    // r = a >> 1
    // r = 0011 0010

    // int a = 1110 0101
    // r = a >> 1
    // r = 1111 0010



    // ^ - XOR - SAU EXCLUSIV

    // 1 ^ 1 = 0
    // 1 ^ 0 = 1
    // 0 ^ 1 = 1
    // 0 ^ 0 = 0

    a = 0b11010101;
    b = 0b11010111;

    // a ^ b = 0000 0010

    printf("a ^ b = %d\n", a ^ b);


    // OPERATII UZUALE

    // testare de bit

    // n = n & (1 << k) - testarea bitului de pe pozitia k

    // setare de bit

    // n = n | (1 << k) - setarea bitului de pe pozitia k
    // n |= (1 << k)

    // resetare de bit

    // n = n & ~(1 << k) - resetarea bitului de pe pozitia k
    // n &= ~(1 << k)

    // inversare de bit

    // n = n ^ (1 << k) - inversarea bitului de pe pozitia k
    // n ^= (1 << k)


    // AFISAREA UNUI NUMAR PE BITI

    // 1. se parcurge numarul de la MSB la LSB
    // 2. se afiseaza bitul curent
    // 3. se deplaseaza numarul la dreapta cu 1 bit

    uint8_t n = 0b11010101;
    uint8_t mask = 0b10000000;

    printf("Numarul n scris binar este: 0b");
    for (uint8_t i = 0; i < 8; i++)
    {
        if ((n & mask) != 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        
        mask >>= 1;
    }
    printf("\n");

    return 0;
}