#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define CHUNK 32

char *read_text(FILE *file)
{
    char buffer[BUFFER_SIZE];
    char *string = malloc(sizeof(char));

    string[0] = 0;

    while(fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        string = realloc(string, strlen(string) + strlen(buffer) + 1);

        strcat(string, buffer);
    }

    return string;
}

int split_silabe(char *string)
{
    int nr_silabe = 0;

    const char *vowels = "aeiouAEIOU";

    char *aux = malloc((strlen(string) + 1) * sizeof(char));

    unsigned long allocated_size = strlen(string) + 1;

    for(unsigned int i = 2; i < strlen(string) - 1; i++)
    {
        if((strchr(vowels, string[i - 2]) != NULL && strchr(vowels, string[i - 1]) != NULL && string[i] != ' ') || (strchr(vowels, string[i - 2]) == NULL && isalpha(string[i - 2]) && strchr(vowels, string[i - 1]) == NULL && isalpha(string[i - 1]) && string[i] != ' '))
        {
            
            if(allocated_size == strlen(string) + 2)
            {
                allocated_size += CHUNK;
                string = realloc(string, allocated_size * sizeof(char));
                aux = realloc(aux, allocated_size * sizeof(char));
            }

            strcpy(aux, string + i);
            strcpy(string + i + 1, aux);

            string[i] = '_';
            
            nr_silabe++;
        }
    }

    free(aux);

    return nr_silabe;
}

int main(void)
{
    char *string = read_text(stdin);

    printf("%s\n", string);

    int nr_silabe = split_silabe(string);

    printf("Nr silabe: %d\n", nr_silabe);

    printf("%s\n", string);

    free(string);

    return 0;
}
