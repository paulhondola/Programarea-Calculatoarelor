#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
union my_union
{
    uint32_t n; // 4 bytes
    char text[4]; // 4 bytes
};

int main(void)
{
    // memoria este impartita intre toti membrii structurii

    union my_union u;
    strcpy(u.text, "abc");

    printf("n: %0x\n", u.n);

    u.n++;

    printf("text: %s\n", u.text);

    return 0;
}