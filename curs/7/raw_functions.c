#include <stdio.h>
#include <string.h>

int main(void)
{
    // memset - seteaza un numar de octeti cu o anumita valoare

    char str[100] = "Ana are mere";
    memset(str, 'a', 5);
    printf("str: %s\n", str);

    int a[100];
    memset(a, 0, 100 * sizeof(int));
    memset(a + 7, 1, 10 * sizeof(int));

    // memcpy - copiaza un numar de octeti dintr-un loc in altul

    char str2[100];
    memcpy(str2, str, 100);

    // memcmp - compara 2 zone de memorie - identic cu strcmp

    // returneaza 0 daca sunt egale
    // returneaza < 0 daca primul string este mai mic decat al doilea
    // returneaza > 0 daca primul string este mai mare decat al doilea

    char str3[100] = "Ana are mere";
    char str4[100] = "Ana are pere";

    printf("comparare: %d\n", memcmp(str3, str4, 100));

    return 0;
}