#include <stdio.h>
#include <string.h>
#define SIZE 10000
// afiseaza substringurile din s, delimitate

unsigned int check_delim(char ch, char *delim)
{
    for(unsigned int i = 0; i < strlen(delim); i++)
        if(ch == delim[i])
            return 1;

    return 0;
}

void my_strtok(char *text, char *delim)
{
    unsigned int len = strlen(text);

    if(!check_delim(text[0], delim))
        printf("%c", text[0]);

    for(unsigned int i = 1; i < len; i++)
    {
        if(!check_delim(text[i - 1], delim) && check_delim(text[i], delim))
            printf("\n");
        else if (check_delim(text[i - 1], delim) && check_delim(text[i], delim))
            ;
        else
            printf("%c", text[i]);
    }
}

void input(char *text)
{
    if(fgets(text, SIZE, stdin) == NULL)
    {
        printf("Eroare la input\n");
        return;
    }
}

int main(void)
{
    char text[SIZE];
    char delim[] = {' ', '.', ',', '?', '/', 0};

    input(text);

    printf("%s\n", text);

    my_strtok(text, delim);

    return 0;
}