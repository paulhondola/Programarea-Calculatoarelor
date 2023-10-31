#include <stdio.h>

int main()
{
    int n = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        else if(n < 0)
        {
            printf("Eroare! Introduceti un numar pozitiv\n");
        }
        else
        {
            if(n % 2)
                printf("Numarul este impar");
            else
                printf("Numarul este par");
        }
    }

    return 0;
}