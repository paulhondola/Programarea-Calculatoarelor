// Să se citească de la tastatură un număr n<=5 iar apoi
// n valori de tip intreg. Să se afișeze toate valorile ale căror modul
// (valoare absolută) este strict mai mare decat 10.

#include <stdint.h>
#include <stdio.h>
#include <math.h>

void read_array(int *array, unsigned int *size)
{
    for(unsigned int i = 0; i < *size; i++)
    {
        if(scanf("%d", &array[i]) != 1)
        {
            *size = i;
            break;
        }
    }
}

void print_array(int *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void show_abs_greater_10(int *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
        if(abs(array[i]) > 10)
            printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    unsigned int size = 0;
    scanf("%u", &size);
    int array[size];

    read_array(array, &size);
    print_array(array, size);

    return 0;
}