// : Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste numere în ordine descrescătoare utilizând pointeri, fără indecși. (Inclusiv citirea se va face cu pointeri.)

#include <stdio.h>

void read_array(int *array, unsigned size)
{
    for(unsigned i = 0; i < size; i++)
        scanf("%d", array + i);
}

void print_array(int *array, unsigned size)
{
    for(unsigned i = 0; i < size; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

void sort(int *array, unsigned size)
{
    unsigned i = 0;
    int aux = 0;
    unsigned short ok = 0;

    do
    {
        ok = 0;
        for(i = 0; i < size - 1; i++)
            if(*(array + i) < *(array + i + 1))
            {
                aux = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = aux;
                ok = 1;
            }
    } while (ok);
}

int main(void)
{
    unsigned size = 0;
    scanf("%u", &size);

    int array[size];
    read_array(array, size);

    sort(array, size);
    print_array(array, size);

    return 0;
}