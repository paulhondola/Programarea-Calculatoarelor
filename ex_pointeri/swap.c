// Scrieți un program care interschimbă valorile a două variabile de tip întreg utilizând pointeri

#include <stdio.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(void)
{
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}