// Să se scrie o funcție care pentru un număr n afișează pe ecran: x^n+x^n-1+...+x+1. De exemplu pentru n=3:   x^3+x^2+x+1.

#include <stdio.h>

void polinom(int n)
{
    if(n == 0)
        printf("1\n");
    else if(n == 1)
    {
        printf("x + ");
        polinom(n - 1);
    }     
    else 
    {
        printf("x^%d + ", n);
        polinom(n - 1);
    }
}

int main(void)
{
    int cif = 0;
    scanf("%d", &cif);
    polinom(cif);
}