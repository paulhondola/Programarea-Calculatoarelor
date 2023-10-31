#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    printf("Secventa de numere este:\n%d\n", n);
    while(n > 10)
    {
        n -= n / 10;
        printf("%d\n", n);
    }

    return 0;
}