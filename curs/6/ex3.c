#include <stdio.h>

// functii cu pointeri

// poate returna - doar daca pointerul este adresa unei variabile statice / globale / alocata dinamic
// SA NU FIE PE STIVA

int *func(void)
{
    static int b;
    int *a;
    a = &b;
    return a;
}

void functie(int *n)
{
    *n = 100;
}

int main(void)
{
    int a = 200;
    functie(&a);
    printf("%d\n", a); // 200

    return 0;
}