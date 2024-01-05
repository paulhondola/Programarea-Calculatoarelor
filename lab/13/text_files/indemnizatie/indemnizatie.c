/*
Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin semnul punct-virgulă. 
Fișierul conține informații statistice oferite de Institutul National de Statistica prin platforma OpenData a Guvernului Romaniei 
(https://data.gov.ro/) despre plata indemnizațiilor de creșterea copilului pe o anumită lună din anul 2021. Fișierul are următorul cap de tabel ce descrie câmpurile din liniile conținue
Judet;Populatie;Beneficiari plãtiti;Beneficiari suspendati la sfârsit de lunã;Suma totalã plãtitã drepturi curente;Alte plãþi
Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari platiti si 
suma total platita drepturi curente, si va stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare, de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa de asemenea o funcție de sortate dupa judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.

Fișierul se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/indemnizatie.csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define BUFFER 4096
#define CHUNK 10

typedef struct 
{
    char judet[32];
    uint32_t populatie;
    uint32_t beneficiari_platiti;
    uint32_t suma_totala_platita;
    uint32_t alte_plati;

} DATE_T;


FILE* open_file(char *filename, char *mode)
{
    FILE *file = NULL;

    file = fopen(filename, mode);

    if(file == NULL)
    {
        perror("cannot open file");
        exit(EXIT_FAILURE);
    }

    return file;
}


void close_file(FILE* file)
{
    if(fclose(file) == EOF)
    {
        perror("cannot close file");
        exit(EXIT_FAILURE);
    }
}


void create_header(FILE* file)
{
    char header[BUFFER];
    if(fgets(header, BUFFER, file) == NULL)
    {
        perror("file is empty");
        exit(EXIT_FAILURE);
    }

    // printf("JUDET | POPULATIE | BENEFICIARI PLATITI | SUMA TOTALA PLATITA | ALTE PLATI\n");
}


int input_item(DATE_T *item, FILE *file)
{
    char line[BUFFER];

    if(fgets(line, BUFFER, file) == NULL)
    {
        return 0;
    }

    char *token = NULL;

    token = strtok(line, ";");

    for(int i = 0; i < 6; i++)
    {
        if(token == NULL)
        {
            perror("invalid format");
            exit(EXIT_FAILURE);
        }

        switch(i)
        {
            case 0:
                strcpy(item->judet, token);
                break;
            case 1:
                item->populatie = (uint32_t)strtol(token, NULL, 10);

                if(errno != 0)
                {
                    perror("invalid format");
                    exit(EXIT_FAILURE);
                }
                
                break;
            case 2:
                item->beneficiari_platiti = (uint32_t)strtol(token, NULL, 10);

                if(errno != 0)
                {
                    perror("invalid format");
                    exit(EXIT_FAILURE);
                }

                break;
            case 4:
                item->suma_totala_platita = (uint32_t)strtol(token, NULL, 10);

                if(errno != 0)
                {
                    perror("invalid format");
                    exit(EXIT_FAILURE);
                }

                break;
            case 5:
                item->alte_plati = (uint32_t)strtol(token, NULL, 10);

                if(errno != 0)
                {
                    perror("invalid format");
                    exit(EXIT_FAILURE);
                }

                break;
            default:
                break;
        }
        
        token = strtok(NULL, ";");
    }

    return 1;
}


DATE_T *read_items(uint64_t *size, FILE *file)
{
    DATE_T *items = NULL;
    DATE_T item;

    uint64_t used_size = 0, allocated_size = 0;

    while(1)
    {
        if(!input_item(&item, file))
            break;

        if(used_size == allocated_size)
        {
            allocated_size += CHUNK;
            items = realloc(items, allocated_size * sizeof(DATE_T));

            if(items == NULL)
            {
                perror("cannot allocate memory");
                exit(EXIT_FAILURE);
            }
        }

        items[used_size++] = item;
    }

    *size = used_size;

    return items;
}


void sort_by_judet(DATE_T *items, uint64_t size)
{
    uint8_t ok = 0;
    DATE_T aux;

    do
    {
        ok = 0;

        for(uint64_t i = 0; i < size - 1; i++)
        {
            if(strcmp(items[i].judet, items[i + 1].judet) > 0)
            {
                aux = items[i];
                items[i] = items[i + 1];
                items[i + 1] = aux;

                ok = 1;
            }
        }

    } while (ok);
    
}


void sort_by_suma_totala_platita(DATE_T *items, uint64_t size)
{
    uint8_t ok = 0;
    DATE_T aux;

    do
    {
        ok = 0;

        for(uint64_t i = 0; i < size - 1; i++)
        {
            if(items[i].suma_totala_platita > items[i + 1].suma_totala_platita)
            {
                aux = items[i];
                items[i] = items[i + 1];
                items[i + 1] = aux;

                ok = 1;
            }
        }

    } while (ok);
    
}


void print_items(DATE_T *items, uint64_t size, FILE *file)
{
    for(uint64_t i = 0; i < size; i++)
    {
        fprintf(file, "%s | %d | %d | %d | %d\n", items[i].judet, items[i].populatie, items[i].beneficiari_platiti, items[i].suma_totala_platita, items[i].alte_plati);
    }
}


void print_max_populatatie_suma_totala(DATE_T *items, uint64_t size)
{
    FILE *file = open_file("rezultat.txt", "w");

    uint32_t max_populatie = 0, max_suma_totala = 0;

    for(uint64_t i = 0; i < size; i++)
    {
        if(items[i].populatie > max_populatie)
        {
            max_populatie = items[i].populatie;
        }

        if(items[i].suma_totala_platita > max_suma_totala)
        {
            max_suma_totala = items[i].suma_totala_platita;
        }
    }

    for(uint64_t i = 0; i < size; i++)
    {
        if(items[i].populatie == max_populatie)
        {
            fprintf(file, "Judetul cu cea mai mare populatie: %s\n", items[i].judet);
        }

        if(items[i].suma_totala_platita == max_suma_totala)
        {
            fprintf(file, "Judetul cu cea mai mare suma totala: %s\n", items[i].judet);
        }
    }

    close_file(file);
}


void out(DATE_T *items, uint64_t size)
{
    FILE *file1 = open_file("out1.txt", "w");
    FILE *file2 = open_file("out2.txt", "w");

    sort_by_judet(items, size);
    print_items(items, size, file1);

    sort_by_suma_totala_platita(items, size);
    print_items(items, size, file2);
    
    close_file(file1);
    close_file(file2);
    
}


int main(void)
{
    FILE *file = open_file("indemnizatie.csv", "r");
    DATE_T *items = NULL;
    uint64_t size = 0;

    create_header(file);

    items = read_items(&size, file);

    print_items(items, size, stdout);

    out(items, size);

    print_max_populatatie_suma_totala(items, size);

    close_file(file);

    free(items);

    return 0;
}
