#include <stdio.h>

#define DEBUG

#define max(A, B) ((A) > (B)) ? (A) : (B)


#define NR 2
#define CALCUL (NR + 2)

int main(void)
{
    // PREPROCESORUL C

    // directiva #include <biblioteca.h> (sau "biblioteca.h")

    // ia fisierul biblioteca.h si il pune in locul directivei #include - tot continutul

    // trebuie sa fie in acelasi director sau in directorul include

    // cu " " - cauta in director
    // cu < > - cauta in directorul include (dupa care in directorul sistemului - gcc / clang / ...)

    

    // directiva #define - defineste un macro #define MACRO valoare - inlocuieste fiecare aparitie a lui MACRO cu valoare - search and replace

    int n;
    n = max(n, 2);

    // se inlocuieste cu n = n > 2 ? n : 2;




    // directiva #if / #ifdef / #ifndef / #else / #endif


    #ifndef DEBUG
        printf("Debugging is off\n");
    #endif
    
    #ifdef DEBUG
        printf("Debugging is on\n");
    #endif


    // CALCULELE STATICE SUNT EXECUTATE DE PREPROCESOR

    return 0;
}