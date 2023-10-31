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