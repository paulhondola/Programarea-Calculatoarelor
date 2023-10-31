#include <stdio.h>

int main(void)
{
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
            printf("%d * %d = %d\nco", i, j, i * j);
    }
    return 0;
}