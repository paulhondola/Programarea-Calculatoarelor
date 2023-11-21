#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hex_to_text(char *string)
{
    char *result = NULL;
    char aux[3];

    if(strlen(string) % 2 != 0)
    {
        printf("Invalid string\n");
        return NULL;
    }

    if((result = malloc((strlen(string) / 2 + 1) * sizeof(char))) == NULL)
    {
        printf("Malloc failed\n");
        return NULL;
    }

    int i, j = 0;
    char ch;
    for(i = 0; i < strlen(string); i += 2)
    {
        strncpy(aux, string + i, 2);
        ch = strtol(aux, NULL, 16);
        result[j++] = ch;
    }
    result[j] = 0;

    return result;
}

int main(void)
{
    char *string = NULL;
    if((string = malloc(1000 * sizeof(char))) == NULL)
    {
        printf("Malloc failed\n");
        return -1;
    }

    if(fgets(string, 1000, stdin) == NULL)
    {
        printf("Read error\n");
        return -1;
    }

    
    char *result = NULL;

    if((result = hex_to_text(string)) == NULL)
    {
        printf("Conversion failed\n");
        return -1;
    }

    printf("%s\n", result);

    free(string);

    // scanf("%s", string); <333 pc is life pc is love <333

    return 0;
}