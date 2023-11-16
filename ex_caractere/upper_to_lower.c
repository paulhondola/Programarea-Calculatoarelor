// Scrieți un program, folosind getchar() si putchar() care, primind la stdin un fișier text va tipari la iesirea standard acelasi fisier text dar va schimba literele mari intalnite in fisier in litere mici iar cele mici in litere mari.

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch = 0;

    while((ch = getchar()) != EOF)
    {
        if(islower(ch))
            putchar(toupper(ch));
        else if(isupper(ch))
            putchar(tolower(ch));
        else
            putchar(ch);
    }

    return 0;
}