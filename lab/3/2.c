#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        printf("%d + ", i);

    printf("\b\b= %d\n", n * (n + 1) / 2);
    return 0;
}