/*
Sa se scrie o functie cu urmatorul antent
char *string_replace_dynamic(const char *where, const char *what, const char *replace)
Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Funcția va returna noul string obținut, alocat dinamic, și NULL în caz de eroare sau în cazul în care string-ul what nu apare în string-ul where.

 char s1[] = "Acesta este un string si un string este terminat cu 0x00";
char s2[] = "string";
char s3[] = "sir de caractere";
char *p = string_replace(s1, s2, s3);
p devine un string alocat dinamic cu urmatorul continut: "Acesta este un sir de caractere si un sir de caractere este terminat cu 0x00";
s1, s2, s3 - raman neschimbate
r = 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

#define CHUNK 1000

char *string_replace(const char *where, const char *what, const char *replace)
{
    char *new_string = NULL;
    int allocated_size = 0;
    int index = 0;

    new_string = malloc(CHUNK * sizeof(char));
    new_string[0] = '\0';


    /*
    
    new_string - 0 - 14 din where

    0 - 14 - strstr(where, what) - where

    strcat(new_string, replace)

    new_string + 15 - 27 din where

    strcat(new_string, replace)

    new_string + 28 - final din where

    */

    if(strstr(where + index, what) == NULL)
    {
        return NULL;
    }

    while(1)
    {
    
        if(strstr(where + index, what) == NULL)
        {

            if(strlen(new_string) + strlen(where + index) >= allocated_size)
            {
                allocated_size += CHUNK;
                new_string = realloc(new_string, allocated_size * sizeof(char));

                if(new_string == NULL)
                {
                    printf("Not enough memory\n");
                    return NULL;
                }
            }

            strcat(new_string, where + index);
            break;
        }

        if(strlen(new_string) + strstr(where + index, what) - where - index + strlen(replace) >= allocated_size)
        {
            allocated_size += CHUNK;
            new_string = realloc(new_string, allocated_size * sizeof(char));

            if(new_string == NULL)
            {
                printf("Not enough memory\n");
                return NULL;
            }
        }

        strncat(new_string, where + index, strstr(where + index, what) - where - index);

        strcat(new_string, replace);

        index = strstr(where + index, what) - where + strlen(what);
    }
    
    return new_string;
}

int main(void)
{
    /*

    Acesta este un |sir de caractere| si un |sir de caractere| este terminat cu 0x00
    
    I - 15
    II - 28
    */

    char *s1 = "Acesta este un string si un string este terminat cu 0x00";
    char *s2 = "string";
    char *s3 = "sir de caractere";

    char *p = string_replace(s1, s2, s3);

    if(p == NULL)
    {
        printf("Error - stringul s2 nu apare in s1\n");
        return 1;
    }
    printf("%s\n", p);

    free(p);
    return 0;
}
