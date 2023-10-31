#include <stdio.h>
#include <stdint.h>

void print_bit_8 (uint8_t nr)
{
  uint8_t mask = 1 << 7; // 0b1000 0000
  uint8_t i = 0;
  for (i = 0; i < 8; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}

// 0 -> paritate para pe biti - numar par de biti de 1
// 1 -> paritate impara pe biti - numar impar de biti de 1
int parity(uint8_t num)
{
    int count = 0;
    int mask = 1 << 7;
    for(int i = 0; i < 8; i++, mask >>= 1)
        if((num & mask) != 0)
            count++;

    return count % 2;
}


int main(void)
{
    uint8_t n = 0;

    printf("n = ");
    scanf("%hhX", &n);

    print_bit_8(n);
    printf("Parity: %d\n", parity(n));
    return 0;
}