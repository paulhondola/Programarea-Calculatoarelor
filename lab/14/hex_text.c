#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *text_to_hex(char *text)
{
    char *result = malloc((strlen(text) * 2 + 1) * sizeof(char));

    // abc -> 616263

    result[0] = 0;

    char aux[3];

    for(unsigned long i = 0; i < strlen(text); i++)
    {
        sprintf(aux, "%02X", text[i]);
        strcat(result, aux);
    }

    return result;
}


char *hex_to_text(char *text)
{
    // 6 + 1 - 3 + 1
    char *result = malloc((strlen(text) / 2 + 1) * sizeof(char));

    result[0] = 0;

    // 616263 -> abc

    char aux[3];
    char ch;
    int index = 0;

    for(unsigned long i = 0; i < strlen(text); i += 2)
    {
        aux[0] = text[i];
        aux[1] = text[i + 1];
        aux[2] = 0;

        ch = (char) strtol(aux, NULL, 16);

        if(errno != 0)
        {
            perror(NULL);
            exit(EXIT_FAILURE);
        }

        result[index++] = ch;
    }

    result[index] = 0;

    return result;
}

int main(int argc, char ** argv)
{
    if(argc != 4)
    {
        perror("Invalid number of arguments");
        exit(1);
    }

    char * hex_text = argv[1];
    char * char_text = argv[2];
    char *path = argv[3];

    FILE *file = fopen(path, "w");

    char *result = NULL;


    result = text_to_hex(char_text);

    fputs(result, file);


    result = hex_to_text(hex_text);

    fputs(result, file);





    fclose(file);
    free(result);
    
    return 0;
}
