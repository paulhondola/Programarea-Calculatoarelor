#include <stdint.h>
#include <stdio.h>

int global = 321;
int global2 = 5;

int main(void)
{
    int local = 20;
    int *ptr1, *ptr2, *ptr3;
    local = 154;
    ptr1 = &local;
    ptr2 = &global;
    ptr3 = &local;

    /*
    int - 4 bytes - 32 bits

    adresa - variabila - valoare
    ----------------------
    .data segment
    0x1000 - global - 321
    0x1004 - global2 - 5
    -----------------------
    .stack segment

    0x8000 - local - 20
    0x8004 - ptr1 - 0x8000
    0x8008 - ptr2 - 0x1000
    0x800c - ptr3 - 0x8000

    */

    local = 7; // la adresa 0x8000 se scrie valoarea 7

    *ptr1 = 75; // la adresa 0x8000 se scrie valoarea 75

    int a = *ptr1; // a = 75
    int b = *ptr1 + 5; // b = 80
    a = *ptr1 + *ptr2; // a = 396
    *ptr1 = local + 7 + *ptr2; // la adresa 0x8000 se scrie valoarea 333

    return 0;
}