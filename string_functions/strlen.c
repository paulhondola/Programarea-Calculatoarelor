#include <stdio.h>
#define SIZE 100

int my_strlen(char *text)
{
    int index = 0;
    while(*(text + index))
    {
        index++;
    }

    return ++index;
}

int main(void)
{
    char str1[SIZE] = "Hello ";
    char str2[SIZE] = "World!";

    printf("Sirul \"%s\" are lungimea --> %d\n", str1, my_strlen(str1));

    return 0;
}