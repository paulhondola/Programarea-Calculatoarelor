#include <stdio.h>
#include <stdint.h>

uint8_t minim(uint8_t a, uint8_t b)
{
    return a < b ? a : b;
}

int main(void)
{
    uint16_t input = 0;
    uint16_t minimum = 0;
    uint16_t count = 0;
    uint64_t average = 0;
    

    if(scanf("%hu", &input) != 1)
        return 1;

    if(input == 0)
        return 1;

    minimum = input;

    while(1)
    {
        if(scanf("%hu", &input) != 1)
            break;

        if(input == 0)
            break;

        minimum = minim(minimum, input);
        count++;
        average += input;
    }

    uint32_t result = (uint32_t)average / count;

    result = result << 16 | minimum;

    printf("0x%08x\n", result);

    return 0;
}