#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch = 0, prev_ch = 0, word_count = 0;
    while((ch = getchar()) != EOF)
    {
        if(isspace(ch) && !isspace(prev_ch))
            word_count++;

        prev_ch = ch;
    }

    printf("Word count: %d\n", word_count);

    return 0;
}