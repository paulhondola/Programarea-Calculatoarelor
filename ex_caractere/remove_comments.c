// Scrieți un program, folosind getchar() și putchar(), care, primind la stdin redirectat un fișier ce conține un cod C, va printa la stdout același fișier dar fără comentarii. Practic, programul va elimina comentariile din fișierul C primit prin redirectare de stdin și va printa rezultatul la stdout

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char prev_prev_ch = 0, prev_ch = 0, ch = 0;
    prev_prev_ch = getchar();
    prev_ch = getchar();

    while((ch = getchar()) != EOF)
    {
        // case - //
        if (prev_prev_ch == '/' && prev_ch == '/')
        {
            while((ch = getchar()) != '\n');
        }
        putchar(ch);
        prev_prev_ch = prev_ch;
        prev_ch = ch;

    }

    return 0;
}