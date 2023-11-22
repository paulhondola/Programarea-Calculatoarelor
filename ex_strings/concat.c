// Se citește n din intervalul [3,10] și apoi n nume de persoane. Să se concateneze primele n-1 nume folosind „, ”, ultimul nume cu „ si ”, iar apoi să se adauge „invata.”. Să se afișeze propoziția rezultată.
// Exemplu: n=3, numele: Ion Ana Maria
// Propoziție rezultata: Ion, Ana și Maria invata.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_SIZE 1000
#define CHUNK 100

int main(void)
{
    unsigned int n = 0;

    scanf("%u", &n);
    char space = getchar();
    if(n < 3 || n > 10)
        return -1;

    char name[NAME_SIZE];
    char *text = NULL;

    if((text = malloc(n * NAME_SIZE * sizeof(char))) == NULL)
    {
        return -1;
    }

    text[0] = 0;

    //printf("text = %s\n", text);

    for(unsigned int i = 0; i < n - 2; i++)
    {
        

        if(fgets(name, NAME_SIZE, stdin) == NULL)
        {
            free(text);
            return -1;
        }

        if(name[strlen(name) - 1] == '\n')
            name[strlen(name) - 1] = 0;

        
        strcat(text, name);
        strcat(text, ", ");
    }

    // penultimul nume
    if(fgets(name, NAME_SIZE, stdin) == NULL)
    {
        free(text);
        return -1;
    }

    if(name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = 0;

    strcat(text, name);
    strcat(text, " si ");

    // ultimul nume

    if(fgets(name, NAME_SIZE, stdin) == NULL)
    {
        free(text);
        return -1;
    }

    if(name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = 0;
    strcat(text, name);
    strcat(text, " invata.");

    printf("%s\n", text);

    return 0;
}