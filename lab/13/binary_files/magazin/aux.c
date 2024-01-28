/*
Să se scrie un program care ţine evidenţa mașinilor de spălat dintr-un magazin. Pentru fiecare produs se specifică în parte: producător, model, pret de furnizor, preț de vânzare, greutate, tip încărcare (frontală/verticală). În functie de tipul de încărcare introdus de la tastatură se vor citi următoarele caracteristici:
- Pentru încărcare frontală: capacitate de încărcare (kg), clasa de eficiență energetică,programe;
- Pentru încărcare verticală: tip afișaj, număr programe, selector centrifugare, nivel de zgomot la spălare;
Să se creeze un meniu care să conţină următoarele operaţii:
1. Citirea produselor deja salvate aflate în fișierul „magazin.bin” si afișarea acestora pe ecran
2. Adăugarea unui nou produs în stocul magazinului și salvarea acestuia în fișierul „magazin.bin” (nu se va crea un nou fisier deoarece pot exista produse adăugate anterior)
3. Afişarea tuturor mașinilor de spălat pe tipuri de încărcare din magazin.
4. Crearea unui fișier numit „oferta.txt” și salvarea tuturor mașinilor de spălat care au un preț mai mic dat de la tastatură.Nota: In cadrul fisierului oferta.txt informatia va fi structurata astfel incat fiecare linie din cadrul fisierului oferta.txt sa contina informatia completa despre o masina de spalat. Informatiile vor fi separate prin spatii astfel:
- pentru masinile de spalat cu incarcare frontala : producator model pret_de_furnizare tip_de_incarcare capacitate_de_incarcare clasa_de_eficienta programe
- pentru masinile de spalat cu incarcare verticala:
producator model pret_de_furnizare tip_de_incarcare tip_afisaj numar_programe selector_centrifugare nivel_de_zgomot
5. Cautarea unei mașini de spălat dupa greutate.
6. Sortarea categoriei încărcare frontală după clasa de eficiență energetică.
7. Să se afișeze toate mașinile de spălat de la un anumit producător precizând tipul de încărcare.
8. Iesire
*/
#include "header.h"

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }
    return file;
}


