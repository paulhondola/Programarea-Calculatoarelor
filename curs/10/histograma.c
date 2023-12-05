#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2000
#define ASCII_COUNT 127


int histograma(char *line, int *tab)
{
    int count = 0;

    for(int i = 0; i < strlen(line); i++)
    {
        tab[(int)line[i]]++;
        count++;
    }

    return count;
}


void print_histograma(int *tab, int count)
{
    for(int i = 32; i < 127; i++)
    {
        printf("%c -> %d -> %.3f\n", i, tab[i], 100 * (float)tab[i] / count);
    }
}

int main(void)
{
    FILE *file = NULL;

    if((file = fopen("input.txt", "r")) == NULL)
    {
        perror("eroare deschidere fisier\n");
        exit(-1);
    }




    int COUNT = 0;

    int tab[ASCII_COUNT];
    memset(tab, 0, sizeof(tab));

    char line[SIZE];

    while((fgets(line, SIZE, file)) != NULL)
    {
        COUNT += histograma(line, tab);

        printf("%s", line);
    }

    printf("Total caractere: %d\n", COUNT);

    print_histograma(tab, COUNT);

    if(fclose(file) == EOF)
    {
        perror("eroare inchidere fisier\n");
        exit(-1);
    }

    return 0;
}