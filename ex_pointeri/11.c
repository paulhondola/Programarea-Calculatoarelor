/*
Să se implementeze, fără a se folosi variabile index, un program cu următorul meniu:
1. Citire - citește o valoare reală și o adaugă într-un vector cu maxim 100 de elemente
2. Afișare - afișează toate valorile din vector
3. Ștergere - citește o valoare și șterge toate elementele egale cu valoarea citită
4. Ieșire
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

void citire(float *array, int *size)
{
    float input = 0;

    printf("Introduceti un numar:\n");

    if(scanf("%f", &input) != 1)
    {
        perror("scanf");
        exit(-1);
    }

    *(array + *size) = input;

    (*size)++;
}


void afisare(float *array, const int size)
{
    if(size == 0)
    {
        printf("Vectorul este gol.\n\n");
        return;
    }

    float *iterator = array;
    for(int i = 0; i < size; i++)
        printf("%.2f ", *(iterator++));

    printf("\n\n");
}

void erase_at_position(float *array, int *size, int position)
{
    for(int i = position; i < *size - 1; i++)
    {
        *(array + i) = *(array + i + 1);
    }

    (*size)--;
}


void erase_item(float *array, int *size)
{
    if(*size == 0)
    {
        printf("Vectorul este gol.\n\n");
        return;
    }

    float item = 0;

    printf("Introduceti un numar:\n");
    if(scanf("%f", &item) != 1)
    {
        perror("citire item / erase_item");
        exit(-1);
    }

    for(int i = 0; i < *size; i++)
        if(*(array + i) == item)
        {
            erase_at_position(array, size, i);
            i--;
        }
}


int main(void)
{
    float array[SIZE];
    int size = 0;

    int option = 1;

    while(option != 4)
    {
        printf("Introduceti optiunea:\n");
        printf("1. Citire\n");
        printf("2. Afișare\n");
        printf("3. Ștergere\n");
        printf("4. Ieșire\n");

        if(scanf("%d", &option) != 1)
        {
            perror("scanf option");
            exit(-1);
        }

        switch (option)
        {
        // citire
        case 1:
            citire(array, &size);
            break;
        
        // afisare
        case 2:
            afisare(array, size);
            break;

        // stergere
        case 3:
            erase_item(array, &size);
            break;

        // exit
        case 4:
            break;
        default:
            break;
        }
    }

    return 0;
}
