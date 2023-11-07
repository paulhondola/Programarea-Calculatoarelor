#include <stdio.h>
#define SIZE 100

char *my_strchr(char *text, char ch)
{
    char *ptr = text;
    while(*ptr)
    {
        if(*ptr == ch)
            return ptr;
        ptr++;
    }
    return NULL;
}

int main(void)
{
    char str[SIZE] = "Hello World!";
    char ch = 'a';

    printf("%s\n", my_strchr(str, ch));

    return 0;
}