// Scrieți o funcție recursivă care returnează cea mai semnificativă cifră a unui număr natural scris în baza 10.

#include <stdio.h>

int MSD(int n)
{
    if (n < 10)
        return n;
    else
        return MSD(n / 10);
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", MSD(n));

    return 0;
}