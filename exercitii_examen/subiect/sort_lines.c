#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024
#define CHUNK 64

int greater(char *a, char *b) 
{
    return strcmp(a, b) > 0;
}


char *read_line(void)
{
    char *line = NULL;

    line = malloc(sizeof(char));

    if (line == NULL) 
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    line[0] = '\0';

    char buffer[BUFFER];

    while (fgets(buffer, BUFFER, stdin) != NULL) 
    {
        line = realloc(line, (strlen(line) + strlen(buffer) + 1) * sizeof(char));

        if (line == NULL) 
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        strcat(line, buffer);

        if (line[strlen(line) - 1] == '\n') 
        {
            line[strlen(line) - 1] = '\0';
            break;
        }
    }

    return line;
}


char **read_all_lines(uint64_t *size)
{
    char **lines = NULL;

    char *line = NULL;

    uint64_t allocated_size = 0;

    while(1)
    {
        line = read_line();

        if (line[0] == '\0') 
        {
            free(line);
            break;
        }
        
        if(*size == allocated_size)
        {
            allocated_size += CHUNK;
            lines = realloc(lines, allocated_size * sizeof(char*));

            if (lines == NULL) 
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        lines[(*size)++] = line;
    }

    return lines;
}


void free_lines(char **lines, uint64_t size)
{
    for (uint64_t i = 0; i < size; i++) 
    {
        free(lines[i]);
    }

    free(lines);
}


void print_lines(char **lines, uint64_t size, uint64_t *vowel_count)
{
    for (uint64_t i = 0; i < size; ++i) 
    {
        printf("%s -> %llu\n", lines[i], vowel_count[i]);
    }
}


uint64_t number_vowels(char *line)
{
    const char *vowels = "aeiouAEIOU";

    uint64_t count = 0;

    for (uint64_t i = 0; i < strlen(line); ++i) 
    {
        if (strchr(vowels, line[i]) != NULL) 
        {
            count++;
        }
    }

    return count;
}


uint64_t * create_vowel_count_array(char **lines, uint64_t size)
{
    uint64_t *vowel_count = malloc(size * sizeof(uint64_t));

    if (vowel_count == NULL) 
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (uint64_t i = 0; i < size; ++i) 
    {
        vowel_count[i] = number_vowels(lines[i]);
    }

    return vowel_count;
}


void sort_lines(char **lines, uint64_t *vowel_count, uint64_t size)
{
    char *aux_line = NULL;

    uint64_t aux_count = 0;

    uint8_t ok = 0;

    do
    {
        ok = 0;
        for(uint64_t i = 0; i < size - 1; i++)
            if(vowel_count[i] > vowel_count[i + 1])
            {
                aux_line = lines[i];
                lines[i] = lines[i + 1];
                lines[i + 1] = aux_line;

                aux_count = vowel_count[i];
                vowel_count[i] = vowel_count[i + 1];
                vowel_count[i + 1] = aux_count;

                ok = 1;
            }
            else if(vowel_count[i] == vowel_count[i + 1])
            {
                if(greater(lines[i], lines[i + 1]))
                {
                    aux_line = lines[i];
                    lines[i] = lines[i + 1];
                    lines[i + 1] = aux_line;

                    ok = 1;
                }
            }
    } while(ok);
}


int main(void)
{
    uint64_t size = 0;
    char **lines = read_all_lines(&size);
    uint64_t *vowel_count = create_vowel_count_array(lines, size);

    print_lines(lines, size, vowel_count);

    sort_lines(lines, vowel_count, size);

    printf("Sorted:\n");

    print_lines(lines, size, vowel_count);

    free(vowel_count);
    free_lines(lines, size);

    return 0;
}
