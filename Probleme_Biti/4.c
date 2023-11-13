#include <stdio.h>

unsigned int reverse_bits(unsigned int num)
{
    unsigned int SIZE = sizeof(num) * 8;
    unsigned int reversed = 0;

    for(unsigned int i = 0; i < SIZE; i++)
    {
        reversed |= (num & (1 << i)) << (SIZE - 1 - i);
    }

    return reversed;
}

int main(void)
{
    unsigned int num = 0;
    printf("Enter a number: ");
    scanf("%u", &num);
    printf("The number %u with the bits reversed is %u\n", num, reverse_bits(num));

    return 0;
}