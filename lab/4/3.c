// Să se scrie o funcție care primește ca parametru o cifră și afișează cifra astfel: dacă este în intervalul [0,9] o afișează direct, altfel afișează A pentru 10, B pentru 11, ... până la 15 inclusiv.
#include <stdio.h>

void hex_cifra(int cif)
{
    if (cif <= 9)
        printf("%d\n", cif);
    else if (cif <= 15)
        printf("%c\n", cif - 10 + 'A');
    else
        printf("In afara domeniului!\n");
}

int main(void)
{
    int cif = 0;
    scanf("%d", &cif);
    hex_cifra(cif);

    return 0;
}