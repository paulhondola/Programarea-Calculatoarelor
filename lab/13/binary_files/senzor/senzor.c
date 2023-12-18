/*
Un fisier binar incepe cu un numar fara semn pe 32 de biti care reprezinta numarul de inregistrari din fisier. Dupa acesta urmeaza inregistrarile, implementate prin structura urmatoare:
- an - nr fara semn pe 16 biti
- luna - nr fara semn pe 8 biti
- zi - nr fara semn pe 8 biti
- idx senzor - nr fara semn pe 8 biti
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
    uint8_t idx_senzor;
    int16_t valoare;

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

int main(void)
{
    FILE *f = open_file("date.bin", "wb");

    uint32_t nr_inregistrari = 6;

    fwrite(&nr_inregistrari, sizeof(uint32_t), 1, f);

    


    close_file(f);

    return 0;
}
