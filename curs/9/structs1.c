#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct my_str
{
    int a;
    char ch;
};

int main(void)
{
    struct my_str str1 = { 10, 'a' };

    struct my_str str2;

    str2 = str1; // copiaza TOATA structura

    // echivalent cu

    memcpy(&str2, &str1, sizeof(struct my_str));

    // COMPARAREA STRUCTURILOR


    // NU
    if(memcmp(&str1, &str2, sizeof(struct my_str)) == 0)
    {
        printf("Structurile sunt egale\n");
    }
    else
    {
        printf("Structurile sunt diferite\n");
    }

    // SE FOLOSESC COMPARATII DE CAMPURI

    

    return 0;
}