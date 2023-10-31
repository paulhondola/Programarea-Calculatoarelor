#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch = 0, prev_ch = 0;
    int newline_count = 0, ch_count = 0, word_count = 0;

    while((ch = getchar()) != EOF)
    {
        // check for empty space or newline
        if(isspace(ch) && !isspace(prev_ch))
        {
            word_count++;

            // check for newline
            if(ch == '\n')
            newline_count++;
        }
        else
            ch_count++;    

        prev_ch = ch;
    }

    printf("New line count %7d\n", newline_count);
    printf("Word count %7d\n", word_count);
    printf("Character count %7d\n", ch_count);

    return 0;
}