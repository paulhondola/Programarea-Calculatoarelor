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
        perror("eroare deschidere fisier\n");
        exit(-1);
    }
    else
    {
        printf("fisier deschis cu succes\n");
    }

    
    // fgetc - citeste un caracter din fisier - returneaza EOF cand ajunge la finalul fisierului

    /*
    char c = 0;

    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    */

    // fgets - citeste o linie din fisier - returneaza NULL cand ajunge la finalul fisierului

    // fgets - citeste si \n
    char *s = NULL;
    
    s = malloc(100 * sizeof(char));

    while ((s = fgets(s, 100, f)) != NULL)
    {
        printf("%s", s);
    }


    /*
    
    fputc - scrie un caracter in fisier

    ungetc - pune un caracter inapoi in fisier

    fputs - scrie un string in fisier



    feof - verifica daca cursorul a ajuns la finalul fisierului - returneaza 0 sau 1


    fprintf - scrie in fisier la fel ca printf



    */

    fscanf(f, "%s", s);

    fprintf(f, "ceva\n");

    sprintf(s, "ceva\n"); // scrie in s la fel ca printf


    sscanf(s, "%s", s); // citeste din s la fel ca scanf








    if(fclose(f) == EOF)
    {
        perror("\n\neroare inchidere fisier");
        exit(-1);
    }
    else
    {
        printf("\nfisier inchis cu succes\n");
    }

    return 0;
}