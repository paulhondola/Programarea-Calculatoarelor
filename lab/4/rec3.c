// Scrieți o funcție recursivă care primește ca paramteru un număr natural n și returnează numărul format selectând doar cifrele pare ale acelui număr.

#include <stdio.h>

int form_new_num(int n)
{
    if (n == 0)
        return 0;
    else
    {
        if(n % 2 == 0)
            return 10 * form_new_num(n / 10) + (n % 10);
        else
            return form_new_num(n / 10);
    }
         
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", form_new_num(n));
    return 0;
}