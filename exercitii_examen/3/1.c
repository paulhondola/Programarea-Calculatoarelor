#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CHUNK 1024

char *read_string(void)
{
    char *string = malloc(sizeof(char));

    if(string == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    string[0] = 0;

    char buffer[CHUNK];

    while(1)
    {
        if(fgets(buffer, CHUNK, stdin) == NULL)
        {
            break;
        }

        string = realloc(string, strlen(string) + strlen(buffer) + 2);

        if(string == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        strcat(string, buffer);

        if(string[strlen(string) - 1] == '\n')
        {
            string[strlen(string) - 1] = 0;
            break;
        }
    }

    return string;
}

char *cypher(char *string, int key)
{
    char *cyphered = malloc(strlen(string) + 1);

    key %= 26;

    if(cyphered == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < (int)strlen(string); i++)
    {
        cyphered[i] = string[i] + (char)key;

        if(islower(string[i]) && cyphered[i] > 'z')
        {
            cyphered[i] -= 26;
        }

        if(isupper(string[i]) && cyphered[i] > 'Z')
        {
            cyphered[i] -= 26;
        }
    }

    return cyphered;
}

int main(void)
{
    char *string = read_string();

    char *cyphered = cypher(string, 3);

    printf("%s\n", string);

    printf("%s\n", cyphered);

    free(string);

    free(cyphered);

    return 0;
}
