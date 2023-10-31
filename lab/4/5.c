// Scrieți o funcție care primește 3 parametri de tip float și îi afișează în ordine descrescătoare.

#include <stdio.h>

void print3(float a, float b, float c)
{
    printf("%f >= %f >= %f\n", a, b, c);
}

void sort3(float a, float b, float c)
{
    if(a >= b && a >= c)
    {
        if(b >= c)
            print3(a, b, c);
        else
            print3(a, c, b);
    }
    else if(b >= a && b >= c)
    {
        if(a >= c)
            print3(b, a, c);
        else
            print3(b, c, a);
    }
    else
    {
        if(a >= b)
            print3(c, a, b);
        else
            print3(c, b, a);
    }
}

int main(void)
{
    float a = 0, b = 0, c = 0;
    scanf("%f%f%f", &a, &b, &c);
    sort3(a, b, c);
}