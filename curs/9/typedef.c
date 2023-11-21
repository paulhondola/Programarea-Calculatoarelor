#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// TYPEDEF

typedef uint64_t PC;

typedef struct //my_str - este optional
{
    uint32_t a;
    char ch;
} MYSTR;

int main(void)
{
    PC a = 3;

    MYSTR str;

    str.a = 10;

    return 0;
}