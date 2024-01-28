/*
Fie un oras de extraterestri. Un oras are: nume si un vector alocat dinamic cu extraterestri. Fiecare extraterestru are: nume (maxim 20 de caractere), culoare (rosu, verde sau albastru), data nasterii (zi, luna si an) si daca este sau nu, membru in Senatul Extraterestrilor. Sa se implementeze cat mai abstract toate structurile de date din problema si sa se scrie o functie care primeste ca parametru un oras de extraterestrii si returneaza un pointer la un alt oras de extraterestrii care contine aceeasi extraterestrii ca cel primit ca parametru, sortati in ordine alfabetica.
Se va testa programul cu date hard-codate (setate in codul sursa), sau prin citire din fisier/tastatura.
*/

#include <stdio.h>
#include <stdlib.h>
#include "aliens.h"

int main(void)
{
    CITY_T *city = read_city_data("data.txt");

    print_all_aliens(city, "aliens.txt");

    
    CITY_T *sorted_city = sort_city(city);

    print_all_aliens(sorted_city, "sorted.txt");
    
    free(city->aliens);
    free(city);
    
    free(sorted_city->aliens);
    free(sorted_city);


    return 0;
}
