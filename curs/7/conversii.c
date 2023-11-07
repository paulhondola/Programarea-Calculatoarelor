#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int nr = 43;
    char t[] = "43";

    //printf("t convertit: %d\n", atoi(t));
    //printf("n convertit: %s\n", itoa(nr, t, 10));

    // atoi - caz particular

    // strtol - converteste un string in numar intreg

    char text_dec[] = "1234567890";
    char text_hex[] = "0x1234567890";
    char text_oct[] = "01234567";
    char text_bin[] = "01010101010101010101";

    int n = 0;
    n = strtol(text_dec, NULL, 10);
    printf("n: %d\n", n);
    n = strtol(text_hex, NULL, 16);
    printf("n: %d\n", n);
    n = strtol(text_oct, NULL, 8);
    printf("n: %d\n", n);
    n = strtol(text_bin, NULL, 2);
    printf("n: %d\n", n);

    // sprintf - converteste un numar in string

    char str[100];

    sprintf(str, "%x", 123);
    printf("str: %s\n", str);
    return 0;
}