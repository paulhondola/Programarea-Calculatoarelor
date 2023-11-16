#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// numarul de cuvinte din propozitia curenta

void word_count()
{
    char prev_ch = getchar();

    char ch = 0;
    int word_count = 0;
    int sentence_count = 0;

    while((ch = getchar()) != EOF)
    {
        if (ch == ' ' && prev_ch != ' ')
        {
            if(prev_ch != '.')
                word_count++;
        }
        else if (ch == '.' && prev_ch != '.')
        {
            word_count++;
            sentence_count++;
            printf("Proprozitia %d are %d cuvinte\n", sentence_count, word_count);

            word_count = 0;
        }

        prev_ch = ch;
    }
}

int main(void)
{
    word_count();


    return 0;
}