/*
Un fisier binar incepe cu un numar fara semn pe 32 de biti care reprezinta numarul de inregistrari din fisier. Dupa acesta urmeaza inregistrarile, implementate prin structura urmatoare:
- an - nr fara semn pe 16 biti
- luna - nr fara semn pe 8 biti
- zi - nr fara semn pe 8 biti
- id senzor - nr fara semn pe 8 biti
- valoare - nr cu semn pe 16 biti
O inregistrare codifica valoarea citita de un senzor la o anumita data. Valorile corecte pot fi in intervalul [-1000,1000]. Daca un senzor da din cand in cand valori in afara intervalului, atunci se considera ca are probleme. Daca toate valorile sunt in afara intervalului, atunci senzorul este defect.
Cerinte:
- sa se scrie o functie care creaza un fisier de test, ce cuprinde valori pentru un senzor care merge, altul care are probleme
si altul defect.
- sa se citeasca fisierul de test si sa se afiseze care senzor merge, care are probleme si care e defect.
- se cere de la tastatura un an si o luna. Se cere sa se afiseze toate valorile senzorilor din acel an/luna.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct
{
    uint16_t an;
    uint8_t luna;
    uint8_t zi;
    uint8_t id_senzor;
    int16_t valoare;
    enum {OK, PROBLEME, DEFECT} stare;

} INREGISTRARE;

FILE *open_file(char *filename, char *mode)
{
    FILE *f = fopen(filename, mode);
    if (f == NULL)
    {
        printf("Eroare la deschiderea fisierului %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return f;
}

void close_file(FILE *f)
{
    if(fclose(f) == EOF)
    {
        printf("Eroare la inchiderea fisierului\n");
        exit(EXIT_FAILURE);
    }
}


INREGISTRARE * read_data(FILE *f, uint32_t *size)
{
    unsigned long read = 0;

    read = fread(size, sizeof(uint32_t), 1, f);

    if(read != 1)
    {
        printf("Eroare la citirea numarului de inregistrari\n");
        exit(EXIT_FAILURE);
    }

    INREGISTRARE *reg = NULL;

    reg = (INREGISTRARE *)malloc(*size * sizeof(INREGISTRARE));

    if(reg == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(EXIT_FAILURE);
    }

    for(unsigned long i = 0; i < *size; i++)
    {
        read = fread(&reg[i].an, sizeof(uint16_t), 1, f);
        if(read != 1)
        {
            printf("Eroare la citirea anului\n");
            exit(EXIT_FAILURE);
        }

        read = fread(&reg[i].luna, sizeof(uint8_t), 1, f);
        if(read != 1)
        {
            printf("Eroare la citirea lunii\n");
            exit(EXIT_FAILURE);
        }

        read = fread(&reg[i].zi, sizeof(uint8_t), 1, f);
        if(read != 1)
        {
            printf("Eroare la citirea zilei\n");
            exit(EXIT_FAILURE);
        }

        read = fread(&reg[i].id_senzor, sizeof(uint8_t), 1, f);
        if(read != 1)
        {
            printf("Eroare la citirea id-ului senzorului\n");
            exit(EXIT_FAILURE);
        }

        read = fread(&reg[i].valoare, sizeof(int16_t), 1, f);
        if(read != 1)
        {
            printf("Eroare la citirea valorii\n");
            exit(EXIT_FAILURE);
        }
    }

    return reg;
}

void check_state(INREGISTRARE *reg, uint32_t size)
{
    typedef struct
    {
        uint8_t aparitii_senzor;
        uint8_t probleme;
    } SENZOR;
    
    SENZOR *data_array = NULL;

    data_array = (SENZOR *)malloc(size * sizeof(SENZOR));

    if(data_array == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(EXIT_FAILURE);
    }

    for(uint32_t i = 0; i < size; i++)
    {
        data_array[i].aparitii_senzor = 0;
        data_array[i].probleme = 0;
    }

    for(uint32_t i = 0; i < size; i++)
    {
        data_array[reg[i].id_senzor].aparitii_senzor++;

        if(reg[i].valoare < -1000 || reg[i].valoare > 1000)
        {
            data_array[reg[i].id_senzor].probleme++;
        }
    }

    for(uint32_t i = 0; i < size; i++)
    {
        if(data_array[i].aparitii_senzor == 0)
        {
            continue;
        }
        
        if(data_array[i].probleme == 0)
        {
            reg[i].stare = OK;
        }
        else if(data_array[i].probleme < data_array[i].aparitii_senzor)
        {
            reg[i].stare = PROBLEME;
        }
        else
        {
            reg[i].stare = DEFECT;
        }
    }

    for(uint32_t i = 0; i < size; i++)
    {
        if(data_array[i].aparitii_senzor == 0)
        {
            continue;
        }

        printf("Senzorul %d este ", i);
        switch(reg[i].stare)
        {
            case OK:
                printf("OK\n");
                break;
            case PROBLEME:
                printf("cu probleme\n");
                break;
            case DEFECT:
                printf("defect\n");
                break;
        }

        printf("Numar defecte: %d\nNumar total inregistrari: %d\n", data_array[i].probleme, data_array[i].aparitii_senzor);
    }

    free(data_array);
}



int main(void)
{
    FILE *file = open_file("date.bin", "rb");

    uint32_t nr_inregistrari = 0;

    INREGISTRARE *reg = read_data(file, &nr_inregistrari);

    check_state(reg, nr_inregistrari);
    
    free(reg);

    close_file(file);

    return 0;
}
