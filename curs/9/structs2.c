#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct my_str
{
    uint32_t a;
    char ch;
};

int main(void)
{
    struct my_str s;
    struct my_str *str;

    s.a = 15;
    s.ch = 'b';

    str = malloc(sizeof(struct my_str));

    str->a = 10;
    str->ch = 'a';

    // (*str).a = 10; ---> nope
    // str->a ---> da

    free(str);

    return 0;
}