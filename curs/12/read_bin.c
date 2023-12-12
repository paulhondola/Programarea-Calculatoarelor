#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZE 100

int main(void)
{
    FILE *f = NULL;

    f = fopen("integers.bin", "rb");

    if(f == NULL)
    {
        perror("Nu am putut deschide fisierul integers.bin");
        exit(-1);
    }

    uint32_t number = 0;
    int read = 0;
    uint32_t array[SIZE];

    while ((read = fread(array, sizeof(uint32_t), SIZE, f)) > 0)
    {
        for(int i = 0; i < read; ++i)
        {
            printf("%u ", array[i]);
        }
    }
    
    

    if(fclose(f) != 0)
    {
        perror("Eroare la inchiderea fisierului");
        exit(-1);
    }


    return 0;
}