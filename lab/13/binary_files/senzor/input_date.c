#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


FILE *open_file(char *filepath, char *mode)
{
    FILE *file = fopen(filepath, mode);

    if(file == NULL)
    {
        perror("file not found");
        exit(EXIT_FAILURE);
    }

    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("cannot close file");
        exit(EXIT_FAILURE);
    }
}


int main(void)
{
    FILE *output = open_file("date.bin", "w");

    uint32_t nr_inregistrari = 6;

    uint16_t an[] = {2015, 2029, 2010, 2013, 2011, 2023};

    uint8_t luna[] = {1, 2, 3, 4, 5, 6};

    uint8_t zi[] = {17, 21, 30, 14, 5, 6};

    uint8_t idx_senzor[] = {1, 1, 2, 2, 4, 1};

    int16_t valoare[] = {1000, 1000, -1000, 1001, 1001, 1001};

    fwrite(&nr_inregistrari, sizeof(uint32_t), 1, output);

    for(int i = 0; i < nr_inregistrari; i++)
    {
        fwrite(&an[i], sizeof(uint16_t), 1, output);
        fwrite(&luna[i], sizeof(uint8_t), 1, output);
        fwrite(&zi[i], sizeof(uint8_t), 1, output);
        fwrite(&idx_senzor[i], sizeof(uint8_t), 1, output);
        fwrite(&valoare[i], sizeof(int16_t), 1, output);
    }


    close_file(output);
    return 0;
}