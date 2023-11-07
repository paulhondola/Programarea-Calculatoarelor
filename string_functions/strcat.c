#include <stdio.h>
#define SIZE 100

char *my_strcat(char *dst, char *src)
{
    char *p = dst;
    while(*p)
    {
        p++;
    }

    while(*src)
    {
        *p++ = *src++;
    }

    *p = 0;

    return dst;
}

int main(void)
{
    char str1[SIZE] = "Hello ";
    char str2[SIZE] = "World!";

    printf("Sirul concatenat --> \"%s\"\n", my_strcat(str1, str2));
    return 0;
}