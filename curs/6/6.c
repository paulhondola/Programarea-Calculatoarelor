#include <stdint.h>
#include <stdio.h>

int main(void)
{
    // pointeri

    // variabila - numele dat unei adrese in memorie

    // pointer - adresa in memorie a unei variabile

    // & - ampersant - operatorul de adresa


    int a = 10;
    // &a - adresa variabilei a
    printf("%p\n", &a); // %p - pointer - adresa in memorie

    int *p; // o adresa de memorie care contine o valoare de tip int

    p = &a; // p - adresa variabilei a

    printf("%p\n", p); // adresa variabilei a

    // * - asterisc - operatorul de dereferentiere

    printf("%d\n", *p); // valoarea variabilei a
    printf("%d\n", a); // valoarea variabilei a



    return 0;
}