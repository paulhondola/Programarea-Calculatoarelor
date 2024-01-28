#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 128

typedef struct
{
    char nume_producator[MAX_NAME_LENGTH];
    char nume_model[MAX_NAME_LENGTH];
    uint16_t pret_furnizor;
    uint16_t pret_vanzare;
    uint16_t greutate;
    enum {FRONTALA, VERTICALA} tip_incarcare;

    typedef union
    {
        typedef struct
        {
            uint16_t capacitate_incarcare;
            enum {CLASA_A, CLASA_B, CLASA_C, CLASA_D, CLASA_E} clasa_energetica;
            
        } frontala;

        typedef struct
        {
            char tip_afisaj[MAX_NAME_LENGTH];
            uint8_t numar_programe;

            
        } verticala;
        
    } detalii;

} MASINA_T;


FILE *open_file(char *filename, char *mode);
void close_file(FILE *f);

#endif