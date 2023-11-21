#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct my_struct
{
    uint32_t a;
    uint16_t b;
    char ch;
};


struct my_struct2
{
    uint16_t b;
    uint32_t a;
    char ch;
};

int main(void)
{
    // tipul struct

    struct my_struct str1;
    struct my_struct str2;
    
    printf("deplasamentul a: %ld\n", (char *)(&str1.a) - (char *)(&str1));
    printf("deplasamentul b: %ld\n", (char *)(&str1.b) - (char *)(&str1));
    printf("deplassamentul ch: %ld\n", (char *)(&str1.ch) - (char *)(&str1));
    printf("size: %ld\n", sizeof(struct my_struct));

    printf("depl a: %ld\n", offsetof(struct my_struct, a));
    printf("depl b: %ld\n", offsetof(struct my_struct, b));
    printf("depl ch: %ld\n", offsetof(struct my_struct, ch));
    return 0;
}