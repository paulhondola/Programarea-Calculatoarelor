// Scrieți o funcție care primește ca parametri trei numere n, b și c, cu c în intervalul [0,b) și returnează de câte ori apare cifra c în numărul n, dacă acesta s-ar afișa în baza b.

#include <stdio.h>

int base_b(int n, int b)
{
    if (n == 0)
        return 0;
    else
        return b * base_b(n / 10, b) + (n % b);
}

int ap_interval(int n, int b, int c)
{
    int nr_ap = 0;
    int num = base_b(n, b);
    while(num)
    {
        if(c == num % 10)
            nr_ap++;
            
        num /= 10;
    }

    return nr_ap;
}

int main(void)
{
    int num = 0, base = 0, cif = 0;
    scanf("%d%d%d", &num, &base, &cif);
    printf("%d", ap_interval(num, base, cif));
}