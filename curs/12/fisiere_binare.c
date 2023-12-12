#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    /*
    
    FREAD

    FWRITE

    - citeste / scrie bytes din / in fisier


    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

    size - numarul de bytes pe care vrem sa ii citim per element
    nmemb - numarul de elemente de size bytes pe care vrem sa le citim
    ptr - pointer la zona de memorie unde vrem sa scriem bytesii cititi - este de tip void* pentru ca poate sa fie orice tip de date

    returneaza numarul de elemente de size bytes citite cu succes


    citeste 10 elemente a cate 4 bytes din fisierul f - citeste maxim 10 elemente, sau pana la EOF
    - iti returneaza numarul de elemente citite cu succes




    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);


    */










    FILE *f = NULL;

    f = fopen("integers.bin", "rb");

    if(f == NULL)
    {
        perror("Nu am putut deschide fisierul integers.bin");
        exit(-1);
    }


    // little endian
    // 4 bytes - 32 bits

    // 47 00 00 00 - in fisier

    // n = 00 00 00 47 - in memorie


    // size - numarul de bytes pe care vrem sa ii citim per element

    // nmemb - numarul de elemente de size bytes pe care vrem sa le citim

    // 1 element de 4 bytes
    uint32_t n = 0;
    uint32_t numbers_read = 0;

    numbers_read = (uint32_t)fread(&n, sizeof(uint32_t), 1, f);

    if(numbers_read != 1)
    {
        perror("Eroare la citirea din fisier a numarului");
        exit(-1);
    }

    // pointerul este avansat cu 4 bytes (numbers_read * size) - numbers_read <= nmemb
    // egalitate in cazul in care am citit exact nmemb elemente

    printf("%08x\n", n);

    if(fclose(f) != 0)
    {
        perror("Eroare la inchiderea fisierului");
        exit(-1);
    }
    
    return 0;
}
