#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char first_ch = 0, second_ch = 0, current_ch = 0;

    while((current_ch = getchar()) != EOF)
    {
        // single line comment
        if(first_ch == '/' && second_ch == '/')
        {
            while(current_ch != '\n')
                current_ch = getchar();
        }
        
        // multi line comments
        else if (first_ch == '/' && second_ch == '*')
        {
            while(!(first_ch == '*' && second_ch == '/'))
            {
                current_ch = getchar();
                first_ch = second_ch;
                second_ch = current_ch;
            }
        }

        first_ch = second_ch;
        second_ch = current_ch;
        putchar(current_ch);
    }

    return 0;
}