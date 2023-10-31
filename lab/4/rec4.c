// Scrieți o funcție recursivă care returnează numărul primit ca și parametru, interpretat în baza 16 rezultat din cifrele numărului respectiv.
// De exemplu f(312) = 3*256+1*16+2*1=786

#include <stdio.h>

int base_16(int n)
{
    if (n == 0)
        return 0;
    else
        return 16 * base_16(n / 10) + (n % 10);
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", base_16(n));

    return 0;
}