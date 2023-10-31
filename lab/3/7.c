#include <stdio.h>

int main(void)
{
    int n = 0, aux = 0, nrcif_imp = 0;
    scanf("%d", &n);
    aux = n;
    while(aux)
    {
        if(aux % 2)
            nrcif_imp++;
        aux /= 10;
    }
    printf("Numarul %d are %d cifre impare.\n", n, nrcif_imp);

    return 0;
}