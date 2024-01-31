#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 200

void remove_delimitators(char *string)
{
    char aux[SIZE + 1];

    char prev_ch = string[0];
    for(unsigned long i = 1; i < strlen(string); i++)
    {
        if(!isalpha(string[i]) && !isalpha(prev_ch) && (string[i] == prev_ch))
        {
            strcpy(aux, string + i + 1);
            strcpy(string + i, aux);

            i--;
        }
        else
        {
            prev_ch = string[i];
        }
    }
}

int main(void)
{
    char string[SIZE + 1];

    if(fgets(string, SIZE, stdin) == NULL)
    {
        perror("invalid input");
        exit(-1);
    }

    remove_delimitators(string);

    printf("%s", string);

    return 0;
}
