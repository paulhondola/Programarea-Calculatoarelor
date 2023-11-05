// Să se citească de la tastatură două variabile de tip double (se citește cu %lf, nu cu %g!!!) și să se afișeze numele variabilei care se află la adresa cea mai mică de memorie utilizând pointeri.

#include <stdio.h>

int main(void)
{
    double a = 0, b = 0;
    scanf("%lf %lf", &a, &b);

    if(&a < &b)
        printf("a ---> %p\n", &a);
    else
        printf("b ---> %p\n", &b);

    return 0;
}