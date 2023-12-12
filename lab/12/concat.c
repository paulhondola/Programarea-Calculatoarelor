/*
Să se scrie o funcție care primește două șiruri de caractere și le concatenează cu un spațiu între ele, folosind un bloc de memorie alocat dinamic pentru rezultat. Funcția va returna acest bloc de memorie. Să se verifice funcția cu două șiruri de caractere introduse de la tastatură, fiecare de maxim 100 de caractere.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

char *concat(char *s1, char *s2) 
{
    char *result = (char *)malloc(strlen(s1) + strlen(s2) + 2);
    strcpy(result, s1);
    strcat(result, " ");
    strcat(result, s2);
    return result;
}

int main(void) 
{
    char s1[MAX_SIZE], s2[MAX_SIZE];

    if(fgets(s1, MAX_SIZE, stdin) == NULL) 
    {
        printf("fgets() error\n");
        return -1;
    }

    if(s1[strlen(s1) - 1] == '\n')
        s1[strlen(s1) - 1] = '\0'; // remove '\n' from the end of the string

    if(fgets(s2, MAX_SIZE, stdin) == NULL) 
    {
        printf("fgets() error\n");
        return -1;
    }

    if(s2[strlen(s2) - 1] == '\n')
        s2[strlen(s2) - 1] = '\0'; // remove '\n' from the end of the string

    char *result = concat(s1, s2);

    printf("%s\n", result);
    free(result);
    
    return 0;
}
