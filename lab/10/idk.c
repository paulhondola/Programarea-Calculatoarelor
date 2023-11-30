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
# define MAX 10

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

        scanf("%d", &input);
    }
}

void afiseaza_numar(int *array, int size)
{
    printf("Size: %d\n", size);
    for(int i = 0; i < size; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

int main(void)
{
    int v[MAX], size = 0, max = MAX;

    citeste_numar(v, &size, max);

    afiseaza_numar(v, size);
    
    return 0;
}