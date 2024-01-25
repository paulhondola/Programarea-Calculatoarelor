#include <stdio.h>
#include <stdint.h>

uint32_t decode(uint32_t number, uint8_t option)
{
    switch (option)
    {
    case 0: // ziua
        return number & 0x1f;
        break;

    case 1: // luna
        return number >> 5 & 0xf;
        break;

    case 2: // anul
        return number >> 9;
        break;

    default:
        return 0;
        break;
    }
}

int main(void)
{
    uint32_t number;
    printf("Enter a number: ");
    scanf("%u", &number);

    printf("Year: %u\n", decode(number, 2));
    printf("Month: %u\n", decode(number, 1));
    printf("Day: %u\n", decode(number, 0));

    return 0;
}