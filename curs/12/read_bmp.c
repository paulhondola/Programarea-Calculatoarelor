#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    // ftell - imi spune unde sunt in fisier, returneaza pozitia curenta

    // frewind - ma duce la inceputul fisierului

    // fseek - ma duce la o anumita pozitie in fisier (FILE *fileptr, long offset, int whence)

    // whence - SEEK_SET, SEEK_CUR, SEEK_END

    // SEEK_SET - inceputul fisierului 
    // SEEK_CUR - pozitia curenta
    // SEEK_END - sfarsitul fisierului

    FILE *f = NULL;
    char header_field[2];

    f = fopen("electro.bmp", "rb");

    if(f == NULL)
    {
        perror("Nu am putut deschide fisierul electro.bmp");
        exit(-1);
    }



    if(fread(header_field, sizeof(char), 2, f) != 2)
    {
        perror("Eroare la citirea header field-ului");
        exit(-1);
    }


    for(int i = 0; i < 2; i++)
    {
        printf("Header: %c ", header_field[i]);
    }

    printf("\n");


    uint32_t bmp_size = 0;


    if(fread(&bmp_size, sizeof(uint32_t), 1, f) != 1)
    {
        perror("Eroare la citirea bmp_size-ului");
        exit(-1);
    }

    printf("BMP size: %u\n", bmp_size);


    if(fseek(f, 0x0E, SEEK_SET) != 0)
    {
        perror("Eroare la fseek");
        exit(-2);
    }

    uint32_t DIB_size = 0;

    if(fread(&DIB_size, sizeof(uint32_t), 1, f) != 1)
    {
        perror("Eroare la citirea DIB_size-ului");
        exit(-1);
    }

    printf("DIB size: %u\n", DIB_size);


    uint32_t width = 0, height = 0;


    if(fread(&width, sizeof(uint32_t), 1, f) != 1)
    {
        perror("Eroare la citirea width-ului");
        exit(-1);
    }

    if(fread(&height, sizeof(uint32_t), 1, f) != 1)
    {
        perror("Eroare la citirea height-ului");
        exit(-1);
    }

    printf("Resolution: %ux%u\n", width, height);



    if(fclose(f) != 0)
    {
        perror("Eroare la inchiderea fisierului");
        exit(-1);
    }

    return 0;
}
