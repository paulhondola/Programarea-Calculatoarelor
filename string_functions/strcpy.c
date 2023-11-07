#include <stdio.h>
#define SIZE 100

char *my_strcpy(char *dst, char *src)
{
    char *ptr = dst;
    while(*src)
    {
        *ptr++ = *src++;
    }
    
    return dst;
}

int main(void)
{
    char str1[SIZE] = "Hello ";
    char str2[SIZE] = "World!";
    
    printf("Sirul 1 copiat in 2 --> \"%s\"\n", my_strcpy(str2, str1));

    return 0;
}