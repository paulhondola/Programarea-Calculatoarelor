#include <stdio.h>

int main()
{
    int x = 0, y = 0;
    scanf("%d%d", &x, &y);

    if(x * y >= 0)
    {
        if(x < 0 || y < 0)
            printf("Nu au acelasi semn");
        else 
            printf("Au acelasi semn");
    }
    else
        printf("Au acelasi semn");

    return 0;
}