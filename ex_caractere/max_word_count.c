// Scrieti un program care tipareste la iesire textul citit de la intrarea standard, modificat astfel incat orice litera de la inceputul unui cuvant e transcrisa ca litera mare. La sfarsit, programul va tipari numarul total de cuvinte si numarul maxim de cuvinte pe aceeasi linie. Cuvintele sunt secvenţe de caractere despărţite prin unul sau mai multe "spatii albe".

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch = 0, prev_ch = 0;
    int word_count = 0, word_count_per_line = 0, max_word_count = 0;
    
    prev_ch = getchar();
    if(islower(prev_ch))
        prev_ch = toupper(prev_ch);

    putchar(prev_ch);

    while((ch = getchar()) != EOF)
    {
        if(isspace(ch) && !isspace(prev_ch))
        {
            word_count++;
            word_count_per_line++;
            if(ch == '\n')
            {
                if(max_word_count < word_count_per_line)
                    max_word_count = word_count_per_line;
                    
                word_count_per_line = 0;
            }
            
                
        }
           
        if(isalpha(ch) && isspace(prev_ch))
        {
            if(islower(ch))
                ch = toupper(ch);
        }
        putchar(ch);

        prev_ch = ch;
    }

    printf("\nWord count: %d\n", word_count);
    printf("Max word count per line: %d\n", max_word_count);

    return 0;
}