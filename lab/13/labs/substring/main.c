// afiseaza toate aparitiile unui subsir intr-un sir de caractere, linia si locul in string unde apare

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 4096

FILE *open_file(char *filename, char *mode)
{
    FILE *f = fopen(filename, mode);
    if (f == NULL) 
    {
        printf("Eroare la deschiderea fisierului %s\n", filename);
        exit(1);
    }
    return f;
}

void close_file(FILE *f)
{
    if(fclose(f) == EOF)
    {
        printf("Eroare la inchiderea fisierului\n");
        exit(1);
    }
}


void print_apparitions(FILE *input, FILE *output, char *substring)
{
    char line[BUFFER];
    int line_number = 0;

    while(1)
    {
        if(fgets(line, BUFFER, input) == NULL)
            break;

        line_number++;

        char *p = strstr(line, substring);

        while(1)
        {
            if(p == NULL)
                break;

            fprintf(output, "Line %d / Col %ld\n", line_number, p - line + 1);
            p = strstr(p + 1, substring);
        }
        
    }
}


int main(void)
{
    FILE *input = open_file("Luceafarul.txt", "r");
    FILE *output = open_file("output.txt", "w");

    print_apparitions(input, output, "luna");

    return 0;
}