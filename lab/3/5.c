#include <stdio.h>

int main(void)
{
    int n = 0, m = 0, index = 0;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", index++);
        index %= (m+1);
    }

    return 0;
}