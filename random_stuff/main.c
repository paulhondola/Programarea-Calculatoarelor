// savanah
// montanah

// h 1 h 2 a 1 a 2 
// h a n a -> a n a h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUFFIX 1000

char *extract_suffix(char *string1, char *string2)
{
    char *suffix = malloc(MAX_SUFFIX * sizeof(char));

    for(int i = strlen(string1), j = strlen(string2); i >= 0 && j >= 0; i--, j--)
    {
        if(string1[i] == string2[j])
        {
            suffix[strlen(suffix)] = string1[i];
        }
        else
        {
            break;
        }
    }

    suffix[strlen(suffix)] = '\0';

    return suffix;
}

void swap(char *string)
{
    for(int i = 0; i < strlen(string) / 2; i++)
    {
        char aux = string[i];
        string[i] = string[strlen(string) - i - 1];
        string[strlen(string) - i - 1] = aux;
    }
}

int main(void)
{
    char string1[] = "savanah";
    char string2[] = "montanah";

    char *suffix = extract_suffix(string1, string2);

    swap(suffix);

    printf("%s\n", suffix);

    free(suffix);

    return 0;
}
