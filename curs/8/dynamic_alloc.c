#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // la runtime, nu se aloca / dezaloca memorie - ramane statica

    // pe stiva / pe .data / pe .bss


    // pe heap se aloca blocuri de memorie dinamice

    // malloc / calloc / realloc / free

    // malloc - aloca un bloc de memorie de o anumita dimensiune (in bytes)

    // - returneaza adresa de inceput a blocului de memorie

    // free - elibereaza un bloc de memorie

    // realloc - realoca un bloc de memorie - pentru a creste / micsora dimensiunea
    

    // int *int_ptr = NULL;

    // int_ptr = malloc(sizeof(int));

    // *int_ptr = 5;

    // printf ("value of int_ptr: %d\n", *int_ptr);

    // free(int_ptr);

    int *p = NULL;

    p = malloc(sizeof(int));

    *p = 5;

    printf ("value of p: %d\n", *p);


    int *array = NULL;

    array = malloc(1000 * sizeof(int));

    for (int i = 0; i < 1000; i++)
    {
        array[i] = i * i;
    }

    printf ("array values: ");

    for (int i = 0; i < 1000; i++)
    {
        printf ("%d ", array[i]);
    }


    // calloc - aloca un bloc de memorie de o anumita dimensiune (in bytes) - pt array-uri / structuri + initializeaza cu 0

    // are aceeasi functionalitate ca malloc + memset(ptr, 0, lenght * sizeof(type))

    // timp de executie mult mai mare decat malloc



    // realloc - realoca un bloc de memorie - pentru a creste / micsora dimensiunea

    int *array2 = NULL;

    array2 = realloc(array, 2000 * sizeof(int));

    for (int i = 0; i < 2000; i++)
    {
        array2[i] = i * i;
    }

    printf ("array2 values: ");

    for (int i = 0; i < 2000; i++)
    {
        printf ("%d ", array2[i]);
    }

    printf("\narray2 values after realloc: ");

    array2 = realloc(array2, 10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        printf ("%d ", array2[i]);
    }

    free(array2);

    printf("\n");

    // muta blocul (cu date cu tot) - RAMAN DATELE IN BLOCUL DE MEMORIE

    // daca nu exista spatiu in continuare, se aloca un nou bloc de memorie, se copiaza datele din blocul vechi in cel nou si se elibereaza blocul vechi

    // daca exista spatiu in continuare, se realoca blocul curent

    // daca dimensiunea este mai mica, se elibereaza spatiul in plus

    // daca dimensiunea este mai mare, se aloca spatiu in plus

    // daca pointerul este NULL, se aloca un bloc nou de memorie

    // daca dimensiunea este 0, se elibereaza blocul de memorie



    // free - elibereaza un bloc de memorie

    // nu modifica pointerul



    // valgrind - tool pentru detectarea memory leaks
    
    return 0;
}