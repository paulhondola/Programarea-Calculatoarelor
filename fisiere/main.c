#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool line_comment(int prev_ch, int ch)
{
    return (prev_ch == '/' && ch == '/');
}

bool start_comment(int prev_ch, int ch)
{
    return (prev_ch == '/' && ch == '*');
}

bool end_comment(int prev_ch, int ch)
{
    return (prev_ch == '*' && ch == '/');
}

int main(void)
{
    int current_ch = 0, first_ch = 0, second_ch = 0;

    first_ch = getchar();
    second_ch = getchar();

    if (!line_comment(first_ch, second_ch))
    {
        putchar(first_ch);
        putchar(second_ch);
    }
        
    
    while((current_ch = getchar()) != EOF)
    {
        if (line_comment(first_ch, second_ch))
            while((current_ch = getchar()) != '\n');

        /*
        if (start_comment(prev_ch, ch))
        {
            while(!end_comment(prev_ch, ch) && (ch = getchar()) != EOF);
        }
        
        */
        if(line_comment(second_ch))

        putchar(current_ch);
        first_ch = second_ch;
        second_ch = current_ch;
    }

    return 0;
}    