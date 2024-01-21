#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ARRAY_SIZE 1000
#define MAX_LINE_SIZE 1000

char *read_line(void)
{
    char *line = malloc(MAX_LINE_SIZE * sizeof(char));

    if (line == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, MAX_LINE_SIZE, stdin) == NULL)
    {
        free(line);
        return NULL;
    }

    line[strlen(line) - 1] = '\0';

    return line;
}

char **create_array(int *size)
{
    char **array = malloc(MAX_ARRAY_SIZE * sizeof(char *));

    if (array == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int max_size = 0;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        array[max_size] = read_line();

        if (array[max_size] == NULL)
        {
            break;
        }

        max_size++;
    }

    *size = max_size;

    return array;
}


int check_float(char *string)
{
    // return 1 -> ii bun
    // return 0 -> nu ii bun

    // cifre -> .
    // . 
    // . -> cifre

    // cifre -> .

    int i;

    for(i = 0; i < strlen(string); i++)
    {
        //printf("%c ", string[i]);

        if(string[i] == '.')
        {
            break;
        }

        if(!isdigit(string[i]))
        {
            return 0;
        }
    }

    for(i++; i < strlen(string) - 1; i++)
    {

        if(!isdigit(string[i]))
        {
            return 0;
        }
    }

    return 1;
}


void free_array(char **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }

    free(array);
}

char *concat_floats(char **array, int size)
{
    char *result = malloc(MAX_LINE_SIZE * MAX_ARRAY_SIZE * sizeof(char));
    int result_size = 0;

    if (result == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }


    result[0] = '\0';

    for (int i = 0; i < size; i++)
    {
        if(check_float(array[i]) == 1)
        {
            result_size += strlen(array[i]) + 1;

            strcat(result, array[i]);
            strcat(result, " ");
        }
    }

    result = realloc(result, result_size * sizeof(char));

    return result;
}


int main(void)
{
    int size = 0;

    char **array = create_array(&size);

    char *result = concat_floats(array, size);

    printf("%s\n", result);

    free_array(array, size);

    free(result);

    return 0;
}