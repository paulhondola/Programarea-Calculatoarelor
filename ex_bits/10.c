/*
Se citește o valoare de tip int. Se cere să se afișeze valoarea bitului de semn. Nu se cunoaște a priori dimensiunea tipului de date int.
*/

#include <stdint.h>
#include <stdio.h>

void sign_bit(int n)
{
    n = n >> (sizeof(int) * 8 - 1);

    if(n != 0)
        printf("Numarul este negativ\n");
    else
        printf("Numarul este pozitiv\n");
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    sign_bit(n);
    return 0;
}