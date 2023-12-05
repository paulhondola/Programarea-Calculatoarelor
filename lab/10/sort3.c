/*
2. Se citesc de la tastatură numere naturale până la citirea lui 0.
Numerele vor fi stocate într-un tablou folosind o funcție cu antetul:
    void citeste_numar(int *v, int *size, int max),
unde:     v reprezintă tabloul,
              size este dimensiunea curentă,
              max este dimensiunea maximă ce poate fi stocată în v.
Programul va sorta numerele stocate astfel:
    - numerele divizibile cu 3 vor fi plasate la început
    - numerele care dau restul 1 la împărțirea cu 3 vor fi mutate la mijloc
    - numerele care dau restul 2 la împărțirea cu 3 vor fi mutate la final.
Se va implementa o funcție de afișare a vectorului și se va apela după fiecare operație de mutare.
Se vor folosi pointeri pentru rezolvarea problemei, nu indecși.
*/

#include <stdio.h>
#include <stdlib.h>
# define MAX 100

void citeste_numar(int *array, int *size, int max)
{
    int input = 0;
    
    scanf("%d", &input);
    
    while(input)
    {

        if(*size < max)
        {
            *(array + (*size)++) = input;   
        }
        else
        {
            printf("Array is full!\n");
            break;
        }

        if(scanf("%d", &input) != 1)
            break;
    }
}


void afiseaza_numere(int *array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", *(array + i));

    printf("\n");
}


void sort3(int *array, int size)
{
    int aux, ok = 0;

    do
    {
        ok = 0;

        for(int i = 0; i < size - 1; i++)
            if (( *(array + i) % 3) > ( *(array + i + 1) % 3))
            {
                aux = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = aux;
                ok = 1;
            }
    } while (ok);

    afiseaza_numere(array, size);
}



int main(void)
{
    int v[MAX], size = 0, max = MAX;

    citeste_numar(v, &size, max);

    printf("Size: %d\n", size);

    sort3(v, size);
    
    return 0;
}