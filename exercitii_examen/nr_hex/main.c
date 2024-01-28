// Să se implementeze o funcție transform(const char *srcfile, const char *destfile) care primeste ca parametrii cai către un fișier de intrare și un fisier de ieșire. Programul citește din fisierul de intrare numere pe 32 de biti fără semn în format hexazecimal și afișează în fisierul de ieșire numerele transformate în binar, cu prefixul “0b”. Se vor folosi cât mai multe funcții în implementarea programului. Se va testa programul cu fisierul de intrare “nr_hex.txt”.

// Exemplu: 1A2B3546 -> 0b 0001 1010 0010 1011 0011 0101 0100 0110

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void hex_to_bin(FILE *output, uint32_t input)
{
    uint32_t mask = 1 << 31;

    fprintf(output, "0b");
    while(mask)
    {
        fprintf(output, "%u", (input & mask) != 0);
        mask >>= 1;
    }

    fprintf(output, " ");
}

void transform(const char *srcfile, const char *destfile) 
{
    FILE *src = fopen(srcfile, "r");
    FILE *dest = fopen(destfile, "w");

    if(src == NULL)
    {
        perror(srcfile);
        exit(EXIT_FAILURE);
    }

    if(dest == NULL)
    {
        perror(destfile);
        exit(EXIT_FAILURE);
    }

    uint32_t input = 0;

    while(1)
    {
        if(fscanf(src, "%x", &input) != 1)
            break;

        hex_to_bin(dest, input);
    }

    if(fclose(src) == EOF)
    {
        perror(srcfile);
        exit(EXIT_FAILURE);
    }

    if(fclose(dest) == EOF)
    {
        perror(destfile);
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    transform("nr_hex.txt", "nr_bin.txt");
    return 0;
}
