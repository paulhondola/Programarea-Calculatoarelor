#include <stdio.h>
#include <stdlib.h>

void show_bits(unsigned int x)
{
    unsigned int mask = 1U << (sizeof(unsigned int) * 8 - 1);

    while(mask)
    {
        printf("%d", (x & mask) != 0);

        mask >>= 1;
    }

    printf("\n");
}


void bit_sequence(unsigned int x)
{
    unsigned int current_bit = 1U;

    unsigned int previous_bit = x & 1U;

    unsigned int sequence_length = 1U;

    for(unsigned int i = 1; i < 32; i++)
    {
        current_bit = (x >> i) & 1U;

        if(previous_bit == 1)
        {
            if(current_bit == 1)
            {
                sequence_length++;
            }
            else
            {
                printf("%u ", sequence_length);

                sequence_length = 1U;
            }
        }

        previous_bit = current_bit;
    }
}

int main(void)
{
    unsigned int x;

    if(scanf("%u", &x) != 1)
    {
        perror("invalid input");
        exit(EXIT_FAILURE);
    }

    show_bits(x);

    bit_sequence(x);

    return 0;
}
