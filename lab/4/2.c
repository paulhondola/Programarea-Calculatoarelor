#include <stdio.h>

int maxim(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int main(void)
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", maxim(a, b, c));
    
    return 0;
}