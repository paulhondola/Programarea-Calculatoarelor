// Să se citească o linie de la tastatură. Linia conține cuvinte care sunt formate doar din litere, cuvintele fiind despărțite prin orice alte caractere ce nu sunt litere. Să se capitalizeze prima literă din fiecare cuvânt și să se afișeze șirul rezultat

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10000

int main(void)
{
    char text[SIZE];
    if(fgets(text, SIZE, stdin) == NULL)
        return -1;
    
    printf("Sirul original: %s\n", text);

    unsigned int new_size = strlen(text);

    if(isalpha(text[0]))
        text[0] = toupper(text[0]);

    for(unsigned int i = 1; i < new_size; i++)
    {
        if(!isalpha(text[i - 1]) && isalpha(text[i]))
            text[i] = toupper(text[i]);
    }
    
    printf("Sirul formatat: %s\n", text);

    return 0;
}