#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int a[4]; // a[0], a[1], a[2], a[3]

    /*

     int - 4 bytes - 32 bits
     tab[0] - 0x1000
     tab[1] - 0x1004
     tab[2] - 0x1008
     ................
     tab[i] - &tab[0] + i * sizeof(int)
     ................
     tab[N - 1] - &tab[0] + (N - 1) * sizeof(int)

     dimensiunea efectiva a unui tablou - N * sizeof(int)


     &tab[0] == tab (tab e adresa primului element din tablou)

     int *tab ---> int tab[] ---> declarare fara initializare a spatiului alocat

     int tab[5] = {1, 2, 3, 4, 5}; ---> declarare cu initializare a spatiului alocat


     tab + i ---> &tab[i]
     *(tab + i) ---> tab[i]


     int *p, *q;

     q = &tab[0];
     p = &tab[2];

     p - q ---> 2 ---- diferenta adreselor / sizeof(int)

     void functie(int tab[], unsigned int size)

     sau

     void functie(int *tab, unsigned int size)

     NU ASA:

        void functie(int tab[10], unsigned int size)


     int a = 3; - nu se genereaza cod
     int a;
     a = 3; - se genereaza cod

        int a[3] = {1, 2, 3}; - initializare completa

        int a[3] = {1}; - initializare partiala / incompleta

        int tab[] = {1, 2, 3, 4, 5}; - initializare completa - fara a specifica dimensiunea tabloului


     EROARE

     int tab[5];
     tab = {1, 2, 3, 4, 5}; - nu se poate initializa un tablou dupa declarare

    */

    int *p;
    p = (int*)0x1000;
    printf("%p\n", p); // 0x1000
    p = p + 1; // p = p + 1 * sizeof(tip)
    printf("%p\n", p); // 0x1004


    return 0;
}