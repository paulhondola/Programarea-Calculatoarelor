// Se citesc de la tastatura 2 stringuri. Sa se scrie o functie care returneaza un string alocat dinamic format din caracterele comune din cele 2 stringuri luate o singura data alfabetic ordonate. Ex: s1 = Andrei s2 = anais -> s = in

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *common_letters(const char *s1, const char *s2)
{
    char *str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));

    unsigned int len = 0;

    for(unsigned int i = 0; i < strlen(s1); i++)
    {
        if(strchr(s2, s1[i]) != NULL && strchr(str, s1[i]) == NULL)
            str[len++] = s1[i];
    }

    str[len] = '\0';

    char aux;
    int ok;

    do
    {
        ok = 0;
        for(unsigned int i = 0; i < strlen(str) - 1; i++)
        {
            if(str[i] > str[i + 1])
            {
                aux = str[i];
                str[i] = str[i + 1];
                str[i + 1] = aux;
                ok = 1;
            }
        }

    } while (ok);
    

    return str;
}

int main(void)
{
    const char *s1 = "Andrei";
    const char *s2 = "anais";

    char *s = common_letters(s1, s2);

    printf("%s\n", s);

    free(s);

    return 0;
}
