// Să se scrie un program care citește un număr n<10 iar apoi citește 2 vectori v1 și v2 de câte n elemente de tip int. Pentru citirea elementelor unui vector se folosește o funcție citire(v,n). Se va implementa o funcție egal(v1,v2,n), care testează dacă toate elementele din v1 sunt egale cu cele din v2 la poziții corespondente.

#include <stdio.h>

void read_array(int *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

unsigned short int equal_array(int *v1, int *v2, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
        if(v1[i] != v2[i])
            return 0;

    return 1;
}
int main(void)
{
    unsigned int size = 0;
    scanf("%u", &size);
    int v1[size], v2[size];

    read_array(v1, size);
    read_array(v2, size);

    printf("%hhu\n", equal_array(v1, v2, size));

    return 0;
}