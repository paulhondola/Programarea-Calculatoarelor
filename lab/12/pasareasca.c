#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
#define CHUNK 20


char * edit_string(char *string)
{
    char *edit = malloc((strlen(string) + 1) * sizeof(char));

    if(edit == NULL)
    {
        printf("Nu s-a putut aloca memorie pentru edit.\n");
        free(edit);
        exit(EXIT_FAILURE);
    }

    strcpy(edit, string);
    
    const char *vowels = "aeiouAEIOU";

    int allocated_size = strlen(edit);

    char *aux = NULL;

    for(int i = 0; i < strlen(edit); i++)
    {
        if(strchr(vowels, edit[i]) != NULL)
        {
            // check if there is enough space

            if(strlen(edit) + 2 >= allocated_size)
            {
                allocated_size += CHUNK;
                edit = realloc(edit, allocated_size * sizeof(char));

                if(edit == NULL)
                {
                    printf("Nu s-a putut realoca memorie pentru string.\n");
                    free(aux);
                    exit(EXIT_FAILURE);
                }
            }

        
            
            // move the string to the right

            aux = realloc(aux, (strlen(edit)) * sizeof(char));

            if(aux == NULL)
            {
                printf("Nu s-a putut aloca memorie pentru aux.\n");
                free(aux);
                exit(EXIT_FAILURE);
            }

            strcpy(aux, edit + i + 1);

            strcpy(edit + i + 3, aux);

            // insert the characters

            edit[i + 1] = 'p';

            edit[i + 2] = edit[i];
            

            printf("Size: %ld\n", strlen(edit));
            i += 2;
            
            
        }
    }

    if(aux != NULL)
        free(aux);

    return edit;
}


char *input_string(void)
{
    char *string = malloc(SIZE * sizeof(char));

    if(string == NULL)
    {
        perror("Nu s-a putut aloca memorie pentru string.\n");
        exit(EXIT_FAILURE);
    }

    printf("Introduceti un sir de caractere: ");

    if(fgets(string, SIZE, stdin) == NULL)
    {
        //printf("Nu s-a putut citi sirul de caractere.\n");
        return NULL;
    }


    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';


    return string;
}

int main(void)
{
    char *string = input_string();

    if(string == NULL)
    {
        perror("Nu s-a putut citi sirul de caractere.\n");
        return 1;
    }

    printf("Sirul citit este: %s\n", string);
    
    char * edit = edit_string(string);

    printf("Sirul modificat este: %s\n", edit);

    free(string);
    free(edit);

    return 0;
}
