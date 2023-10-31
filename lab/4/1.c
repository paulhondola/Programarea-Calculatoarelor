#include <stdio.h>

void full_line(int n)
{
    for(int i = 1; i <= n; i++)
        printf("*");
    printf("\n");
}

void empty_line(int n)
{
    printf("*");

    for(int i = 2; i <= n - 1; i++)
        printf(" ");

    printf("*\n");
}

void print8(int n)
{
    full_line(n);
    for(int i = 2; i <= n / 2; i++)
        empty_line(n);
    full_line(n);
    for(int i = 2; i <= n / 2; i++)
        empty_line(n);
    full_line(n);
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    print8(n);
    
    return 0;
}