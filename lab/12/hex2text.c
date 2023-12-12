/*
Să se scrie o funcție care primește ca argument un string ce conține în format text valori în hexazecimal pe două cifre hexazecimale fără prefixul 0x. Aceste valori reprezintă caractere conform tabelei ASCII. Funcția va decodifica textul și il va returna într-un string alocat dinamic. Antetul funcției poate fi următorul:
char *hex2text(const char *hexstring);
Exemplu: hexstring = "616263" -> funcția va returna string-ul "abc"

Această problemă reprezintă inversa funcției dezvoltate la problema anterioară.

Pentru testare se pot folosi datele din fisierul ce se poate descarca prin comanda urmatoare

wget http://staff.cs.upt.ro/~valy/pt/hexlines.txt
Se recomanda ca citirea datelor sa se faca prin redirectarea intrarii standard.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

char *input(void)
{
    char *hexstring = NULL;

    hexstring = (char *)malloc(MAX * sizeof(char));

    if(hexstring == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return NULL;
    }

    if(fgets(hexstring, MAX, stdin) == NULL)
    {
        return NULL;
    }

    hexstring[strlen(hexstring) - 1] = '\0';

    return hexstring;
}


char *hex2text(const char *hexstring)
{
    char *text = NULL;

    text = (char *)malloc(strlen(hexstring) / 2 + 1);

    if(text == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        return NULL;
    }

    // 61 62 63 - a b c
    // cream un byte - 61/0 / 62/0 / 63/0

    for(int i = 0; i < (int)strlen(hexstring); i += 2)
    {
        char byte[3] = {hexstring[i], hexstring[i + 1], 0};

        text[i / 2] = (char)strtol(byte, NULL, 16);
    }

    return text;
}


int main(void)
{
    char *hexstring = NULL;

    hexstring = input();

    if(hexstring == NULL)
    {
        printf("Eroare la citirea string-ului\n");
        return 1;
    }

    char *text_string = NULL;

    text_string = hex2text(hexstring);

    if (text_string == NULL)
    {
        printf("Eroare la conversia string-ului\n");
        return 1;
    }
    

    printf("%s", text_string);

    free(hexstring);
    free(text_string);

    return 0;
}
