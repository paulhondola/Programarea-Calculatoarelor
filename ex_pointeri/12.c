// Să se implementeze, fără a se folosi indecși, următorul program: se citește pe rând câte o valoare întreagă și se inserează într-un vector, astfel încât vectorul să fie mereu sortat crescător. După fiecare inserare se va afișa noul vector. Programul se termină la citirea valorii 0. Presupunem că vectorul va avea maxim 100 de elemente.

#include <stdio.h>

void print_array(int *array, unsigned size)
{
    for(unsigned i = 0; i < size; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

void free_at(int *array, unsigned int *size, int position)
{
    (*size)++;
    for(int i = *size - 2; i >= position; i--)
        *(array + i + 1) = *(array + i);
}

int main(void)
{
    int array[100];
    int input = 0;
    scanf("%d", &input);
    *array = input;

    unsigned int size = 1, i = 0;
    
    while(1)
    {
        if(scanf("%d", &input) == 0)
        {
            perror("scanf");
            return -1;
        }
        
        if(!input)
            break;

        for(i = 0; i < size; i++)
        {
            if(input < *(array + i))
            {
                free_at(array, &size, i);
                *(array + i) = input;
                break;
            }
        }

        if(size == i)
        {
            *(array + size) = input;
            size++;
        }
           
    }
    print_array(array, size);


    return 0;
}