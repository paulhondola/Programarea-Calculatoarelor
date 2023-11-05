// Se citesc două variabile, a și b, de tip întreg. Să se stocheze într-un pointer adresa variabilei care conține valoarea maximă și apoi să se afișeze valoarea pointată

#include <stdio.h>

int main(void)
{
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);

    int *ptr_max = &a;
    if(a < b)
        ptr_max = &b;

    printf("%d\n", *ptr_max);

    return 0;
}