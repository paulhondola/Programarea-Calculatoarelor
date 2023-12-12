#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define LINE_SIZE 4096
#define TITLE_SIZE 256

typedef struct
{
    uint16_t year;
    char title[TITLE_SIZE + 1];
    uint32_t budget;

} MOVIE;


int process_movie(char *line, MOVIE *movie)
{
    return 0;
}



int main(void)
{
    FILE *f = NULL;
    
    f = fopen("movies.csv", "r");

    if(f == NULL)
    {
        perror("Nu am putut deschide fisierul movies.csv");
        exit(-1);
    }

    MOVIE movie;
    char line[LINE_SIZE];

    while(fgets(line, LINE_SIZE, f) != NULL)
    {
        if(process_movie(line, &movie) != 0)
        {
            printf("Eroare la procesarea filmului %s\n", movie.title);
            continue;
        }
        else
        {
            printf("Am procesat filmul %s\n", movie.title);
        }
    }



    if(fclose(f) != 0)
    {
        perror("Eroare la inchiderea fisierului movies.csv");
        exit(-1);
    }

    return 0;
}