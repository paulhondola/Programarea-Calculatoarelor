/*
Se consideră un fișier text ce conține in general text, de o dimensiune necunoscută, programul considerând-o infinită. Să se scrie un program care citește acest fișier și scrie în fișierul histo.txt histragama literelor din fișier. Prin histrograma literelor (mari și mici) se înțelege distribuția în procente a acestora, procentul de apariție din total. În fișierul histo.txt se vor scrie linii sub forma : litera - numar apariții. Exemplu:
a - 16 %
b - 2 %
c - 17.8 %
Fișierul de test se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/scrisoare.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define BUFFER 4096
#define SIZE 26

FILE* open_input(void)
{
    FILE *file = NULL;

    file = fopen("scrisoare.txt", "r");

    if(file == NULL)
    {
        perror("Eroare la deschiderea fisierului\n");
        exit(-1);
    }

    return file;
}


void close_input(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("eroare inchidere fisier\n");
        exit(-1);
    }
}


FILE* open_output(void)
{
    FILE *file = NULL;

    file = fopen("histo.txt", "w");

    if(file == NULL)
    {
        perror("Eroare la deschiderea fisierului\n");
        exit(-1);
    }

    return file;
}


void close_output(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("eroare inchidere fisier\n");
        exit(-1);
    }
}


void create_histo_array(uint64_t * array, uint8_t size, FILE *file)
{
    memset(array, 0, size * sizeof(uint64_t));

    char line[BUFFER];

    while(1)
    {
        if(fgets(line, BUFFER, file) == NULL)
        {
            break;
        }

        uint16_t len = (unsigned short)strlen(line);

        for(uint16_t i = 0; i < len; i++)
        {
            if(isalpha(line[i]))
            {
                array[tolower(line[i]) - 'a']++;
            }
        }

    }
    
}


void print_histo_array(uint64_t *array, uint8_t size, FILE *file)
{
    uint64_t total = 0;

    for(uint8_t i = 0; i < size; i++)
    {   
        total += array[i];
    }

    for(uint8_t i = 0; i < size; i++)
    {
        fprintf(file, "%c -> %f\n", i + 'a', (float) array[i] * 100 / total);
    }
}


int main(void)
{
    FILE *input = NULL;

    input = open_input();

    uint64_t histo_array[SIZE];

    create_histo_array(histo_array, SIZE, input);

    close_input(input);


    FILE *output = NULL;

    output = open_output();

    print_histo_array(histo_array, SIZE, output);

    close_output(output);

    return 0;
}
