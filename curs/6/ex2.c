#include <stdint.h>
#include <stdio.h>

int main(void)
{
    // CONST

    const int n = 3; // n este o variabila constanta
    // n = 4; // eroare - nu pot modifica valoarea unei variabile constante

    int a;
    const int *ptr;
    ptr = &a;

    // *ptr = 5; ---> eroare - nu pot modifica valoarea variabilei a prin intermediul pointerului ptr


    // NEINITIALIZAREA UNUI POINTER - VALOARE OARECARE DIN STIVA

    int *p;
    // *p = 7; ---> eroare - nu pot scrie la o adresa oarecare din stiva

    // POINTERI DE UN TIP - ADRESA DE ALT TIP

    int *q;
    double *r;
    // q = r; ---> eroare - nu pot atribui unui pointer de tip int o adresa de tip double

    // POINTERI VOID

    void *v;
    a = 10;
    v = &a;
    printf("%d\n", *(int *)v); // 0x8000 - 20

    // POINTERI NULL

    int *nll = NULL;
    // *nll = 3; // nu se poate scrie la adresa NULL 0x0

    return 0;
}