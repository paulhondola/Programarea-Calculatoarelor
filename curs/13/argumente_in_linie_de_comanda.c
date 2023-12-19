#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) // sau char *argv[] - ambele sunt echivalente - array de string-uri (char*)
{
    /*
    
    ARGUMENTE IN LINIA DE COMANDA

    argc = argument count
    argv = argument vector (vector de argumente - pot fi string-uri, numere, etc.)


    ls -l -a -h -argumente pentru comanda ls


    ./exe ana are mere
    argc = 4
    argv[0] = ./exe - program executabil
    argv[1] = ana
    argv[2] = are
    argv[3] = mere


    valoarea minima pentru argc este 1 (numele programului executabil)

    fiecare argument este un string (char*)


    ./exe 123 15

    argc = 3

    123, 15 - string -> trebuie convertit in int cu strtol

    ./exe a b

    a, b - string

    argv[1][0] = 'a'
    argv[1][1] = '\0'

    argv[2][0] = 'b'
    argv[2][1] = '\0'

    trebuie verificat argc inainte de a accesa argv


    */

    printf("Numarul de argumente este: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Argumentul %d este: %s\n", i, argv[i]);
        printf("Lungimea argumentului %d este: %d\n", i, strlen(argv[i]));

    }

    return 0;
}