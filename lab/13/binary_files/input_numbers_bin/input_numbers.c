/*
Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program ce citeste un astfel de fisier si scrie numerele citite intr-un alt fisier in format text hexazecimal cu 8 cifre hexa cate unul pe rand. Pentru testare se poate folosi fisierul descarcat prin urmatoarea comanda:
http://staff.cs.upt.ro/~valy/pt/integers.bin
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHUNK 4096

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



void move_data(FILE *source, FILE *destination)
{
    fseek(source, 0x00, SEEK_SET);
    fseek(destination, 0x00, SEEK_SET);
    
    int array[CHUNK];
    
    unsigned long long int read = 0;
    
    while(1)
    {
        read = fread(array, sizeof(int), CHUNK, source);
                
        if (read == 0)
            break;
        
        for(unsigned long long int i = 0; i < read; i++)
        {
            fprintf(destination, "%08X\n", array[i]);
        }
    }
}


int main(void)
{
    FILE *input = open_file("integers.bin", "rb");
    FILE *output = open_file("integers.txt", "a");
    
    move_data(input, output);
    
    close_file(input);
    close_file(output);
    
    return 0;
}
