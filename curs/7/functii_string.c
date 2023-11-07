#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    if(fgets(str, 100, stdin) != NULL)
    {
        printf("string: %s\n", str);
    }
    else
    {
        printf("eroare la citire\n");
    }

    // FUNCTII

    // strlen - returneaza lungimea unui string

    printf("lungimea stringului: %ld\n", strlen(str));

    // strcpy - copiaza un string in alt string

    char str2[100];
    strcpy(str2, str);
    printf("str2: %s\n", str2);
    
    // strlen(str2) >= strlen(str)


    // strcat - concateneaza un string la alt string

    char str3[100] = "Hello ";
    char str4[] = "World!";
    strcat(str3, str4); // trebuie sa fiu sigur ca str3 are suficient spatiu pt str4

    printf("str3 + str4: %s\n", str3);

    // strchr - cauta un caracter intr-un string

    char text[128] = "Ana are mere";
    char *result = NULL;

    result = strchr(text, 'r');

    if(result == NULL)
    {
        printf("caracterul nu a fost gasit\n");
    }
    else
    {
        printf("caracterul a fost gasit la pozitia: %ld\n", result - text);
        printf("sirul de la pozitia gasita: %s\n", result);
    }

    // strcmp - compara 2 stringuri

    // returneaza 0 daca sunt egale
    // returneaza < 0 daca primul string este mai mic decat al doilea
    // returneaza > 0 daca primul string este mai mare decat al doilea

    // returneaza diferenta intre primele 2 caractere non identice - cod ascii

    char str5[] = "Ana";
    char str6[] = "Ana";
    char str7[] = "Ana are mere";

    printf("comparare: %d\n", strcmp(str5, str6));

    // strncmp - compara primele n caractere din 2 stringuri
    // strncat - concateneaza primele n caractere din 2 stringuri
    // strncpy - copiaza primele n caractere din 2 stringuri

    return 0;
}