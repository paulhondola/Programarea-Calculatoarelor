#include <stdio.h>
#define SIZE 100

int my_strcmp(char *str1, char *str2)
{
    while(*str1 && *str2)
    {
        if(*str1 - *str2)
            return *str1 - *str2;
        
        str1++;
        str2++;
    }
    if(*str1)
        return 1;
    if(*str2)
        return -1;

    return 0;
}

int main(void)
{
    char str1[SIZE] = "abcd";
    char str2[SIZE] = "abcde";

    if(my_strcmp(str1, str2) == 0)
        printf("Sirurile sunt egale\n");
    else if (my_strcmp(str1, str2) < 0)
        printf("Sirul 1 este mai mic lexicografic ca si sirul 2\n");
    else
        printf("Sirul 1 este mai mare lexicografic ca si sirul 2\n");
    return 0;
}