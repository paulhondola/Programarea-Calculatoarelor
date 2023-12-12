/*
Să se scrie o funcție care primește ca argument un string și returnează un alt string alocat dinamic în care fiecare caracter din string-ul inițial va fi înlocuit cu valoarea în hexazecimal a caracterului conform tabelei ASCII în format text pe strict două cifre hexazecimale fără prefixul 0x. Antetul funcției poate fi următorul
char *text2hex(const char *string);
Exemplu: string = "abc" -> funcția va returna un string de forma "616263"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

char *text2hex(const char *string)
{
    char *hex = NULL;

    hex = (char *)malloc(strlen(string) * 2 + 1);

    if(hex == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return NULL;
    }

    for (int i = 0; i < (int)strlen(string); ++i)
        sprintf(hex + 2 * i, "%0x", string[i]);

    return hex;
}

int main(void)
{
    char string[MAX];

    if(fgets(string, MAX, stdin) == NULL)
    {
        printf("Eroare la citirea string-ului\n");
        return 1;
    }

    string[strlen(string) - 1] = '\0';



    char *hex = NULL;

    hex = text2hex(string);

    printf("%s\n", hex);

    free(hex);

    return 0;
}
