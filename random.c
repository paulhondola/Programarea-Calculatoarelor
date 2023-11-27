#include <stdio.h>

void input(int *a, int *b)
{
    scanf ("%d %d", a, b);
}

void suma(int a, int b, int *c) 
{
    *c=a+b;
}
int main(void)
{   
    int c;
    int a = 0, b = 0;
    input(&a,&b);

    printf("%d %d\n",a,b);

    scanf("%d", &c);

    suma(a,b,&c);

    printf("%d",c);

    return 0;
}