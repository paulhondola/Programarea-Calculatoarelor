// Scrieți o funcție recursivă care implementează șirul lui Fibonacci, apoi printați numărul de apeluri recursive pentru fiecare număr folosind un parametru dat prin adresă din main.

#include <stdio.h>

int fibo(int n, int *calls)
{
    (*calls)++;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1, calls) + fibo(n - 2, calls);
}

int main(void)
{
    int n = 0, calls = 0;
    scanf("%d", &n);
    int nth_element = fibo(n, &calls);
    printf("%d\n", calls);
    return 0;
}