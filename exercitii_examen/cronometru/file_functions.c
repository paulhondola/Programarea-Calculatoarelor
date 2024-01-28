#include "header.h"


FILE *open_file(char *filename, char *mode)
{
    FILE *f = fopen(filename, mode);
    if (f == NULL) 
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    return f;
}


void close_file(FILE *f)
{
    if (fclose(f) == EOF)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}


