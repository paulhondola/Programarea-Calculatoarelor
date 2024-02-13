// 0x12 0x42        0x56 0xAB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define STRING_CHUNK 1024
#define HEX_NUMBER_SIZE 16

char *get_string(void)
{
    char *string = malloc(sizeof(char));

    if(string == NULL)
    {
        perror("memory allocation failed");
        exit(1);
    }

    // string gol -> 1 spatiu -> \0

    char buffer[STRING_CHUNK];

    while(1)
    {
        if(fgets(buffer, STRING_CHUNK, stdin) == NULL)
        {
            break;
        }


    // 0 + buffer = buffer + 1
        string = realloc(string, strlen(string) + strlen(buffer) + 1);

        if(string == NULL)
        {
            perror("memory allocation failed");
            exit(1);
        }

        strcat(string, buffer);
    }

    return string;
}


void edit_line(char *line)
{
    char *aux_line = malloc((strlen(line) + 1) * sizeof(char));

    if(aux_line == NULL)
    {
        perror("memory allocation failed");
        exit(1);
    }

    strcpy(aux_line, line);

    printf("LINE: %s\n", aux_line);
    
    
    char *word_token = strtok(aux_line, " ");

    while(word_token)
    {
        printf("WORD: %s\n", word_token);

        word_token = strtok(NULL, " ");
    }
    

    free(aux_line);
}


void edit_string(char *string)
{
    char *aux_string = malloc((strlen(string) + 1) * sizeof(char));

    if(aux_string == NULL)
    {
        perror("memory allocation failed");
        exit(1);
    }

    strcpy(aux_string, string);

    char *line_token = strtok(aux_string, "\n");
    
    while(line_token)
    {
        edit_line(line_token);

        line_token = strtok(NULL, "\n");
    }

    free(aux_string);
}


int main(void)
{
    char *string = get_string();

    edit_string(string);

    free(string);

    return 0;
}


/*
        word_token = strtok(aux_line_token, " ");
        hex_number_count = 0;

        max_value = 0;
        sum_value = 0;
        
        while(word_token)
        {

            hex_number = (unsigned int)strtol(word_token, NULL, 16);

            if(errno != 0)
            {
                perror("invalid hex number");
                exit(1);
            }

            hex_number_count++;

            printf("%d ", hex_number);

            if(hex_number > max_value)
            {
                max_value = hex_number;
            }

            sum_value += hex_number;

            if(hex_number_count % 3 == 0)
            {
                printf("\n");
            }

            word_token = strtok(NULL, " ");
        }

        if(hex_number_count != 0)
        {
            avg_value = (float)sum_value / hex_number_count;

            printf("\nmax: %d, sum: %d, avg: %.2f\n", max_value, sum_value, avg_value);
        }
        
        */
        //printf("%s", aux_line_token);
