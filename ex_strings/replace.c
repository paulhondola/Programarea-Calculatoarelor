/*
uint32_t string_replace(char *where, const char *what, const char *replace)
Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Se considera ca zona de memorie a lui where este suficient de mare ca sa poata contine noul string. Functia returneaza numarul de inlocuiri

char s1[1000];
char s2[] = "string";
char s3[] = "sir de caractere";
strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");
int r = string_replace(s1, s2, s3);
s1 devine "Acesta este un sir de caractere si un sir de caractere este terminat cu 0x00";
s2, s3 - raman neschimbate
r = 2
*/

#include <stdio.h>
#include <string.h>
#define SIZE 1000

int string_replace(char *main_text, char *str_to_replace, char *str_replacement)
{
    int nr_replacements = 0;
    

    for(unsigned int i = 0; i < strlen(main_text); i++)
    {
        char empty_string[SIZE];

        char *ptr = strstr(main_text + i, str_to_replace);

        //printf("%c\n", *ptr);
        // daca nu mai gasesc subsiruri de inlocuit

        if(ptr == NULL)
            return nr_replacements;

        nr_replacements++;

        // in empty string pun mai intai stringul de inlocuire

        strcpy(empty_string, str_replacement);

        strcat(empty_string, ptr + strlen(str_to_replace));

        strcpy(main_text + (ptr - main_text), empty_string);


        i += ptr - main_text;
    }

    return nr_replacements;
}

int main(void)
{
    char s1[SIZE];
    char s2[] = "string";
    char s3[] = "sir de caractere";
    strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");

    int r = string_replace(s1, s2, s3);

    printf("%d\n", r);
    printf("%s\n", s1);

    return 0;
}