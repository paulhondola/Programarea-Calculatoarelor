#include <stdio.h>
#include <stdint.h>

uint8_t digit_count(uint32_t number)
{
    uint8_t digits = 0;
    uint8_t even_digits = 0;

    while(number)
    {
        digits++;
        if(!(number % 2))
            even_digits++;

        number /= 10;
    }

    return digits << 4 | even_digits;
}

int main(void)
{
    uint32_t number;

    printf("Enter a number: ");
    scanf("%u", &number);

    printf("The number of digits is 0x%02x\n", digit_count(number));

    return 0;
}