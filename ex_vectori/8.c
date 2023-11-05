// Se citește un număr n<=10 și apoi n numere întregi.
// Se cere să se șteargă din vector toate acele elemente care sunt urmate de un
// număr strict mai mare decât ele, păstrându-se ordinea elementelor

#include <stdint.h>
#include <stdio.h>

void read_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

void print_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void remove_element(int *array, int *size, int position)
{
    for(int i = position; i < (*size) - 1; i++)
        array[i] = array[i + 1];

    (*size)--;
}

void remove_bigger(int *array, int *size)
{
    for(int i = 0; i < *size - 2; i++)
        if(array[i] < array[i + 1])
        {
            remove_element(array, size, i + 1);
            i--;
            print_array(array, *size);
        }
}

int main(void)
{
    int size = 0;
    scanf("%d", &size);
    int array[size];

    read_array(array, size);
    print_array(array, size);

    remove_bigger(array, &size);
    print_array(array, size);
    return 0;
}