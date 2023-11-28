#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /*
    referentiat prin cale absoluta sau relativa

    r - read
    w - write - daca exista - sterge tot ce e in el - daca nu exista fisierul, il creeaza
    a - append - daca nu exista fisierul, il creeaza - se adauga la final

    b - binary - se citeste si se scrie in mod binar


    fopen - deschide un fisier
    fclose - inchide un fisier

    malloc + free


    cursor - cand fisierul se deschide in modul r, cursorul este la inceputul fisierului

    pe pozitia 0


    cursorul va citi de pe pozitia in care a ramas ultima data

    cursorul semnaleaza EOF (end of file) cand ajunge la finalul fisierului
    */
    FILE *f = NULL;

    // nu ii pot accesa membrii la structura

    if ((f = fopen("input.txt", "r")) == NULL)
    {
        perror("eroare deschidere fisier");
        exit(-1);
    }
    else
    {
        printf("fisier deschis cu succes\n");
    }


    if(fclose(f) == EOF)
    {
        perror("eroare inchidere fisier");
        exit(-1);
    }
    else
    {
        printf("fisier inchis cu succes\n");
    }

    return 0;
}