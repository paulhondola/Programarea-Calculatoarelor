#include "files.h"

FILE *open_file(char *filename, char *mode) 
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) 
    {
        perror(filename);
        exit(1);
    }
    return file;
}

void close_file(FILE *file) 
{
    if(fclose(file) == EOF) 
    {
        perror(NULL);
        exit(1);
    }
}
