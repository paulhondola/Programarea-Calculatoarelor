// Să se afișeze câte elemente negative sunt în vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși. (Fără indecși înseamnă că în cod nu va exista niciun v[i])

#include <stdio.h>

unsigned int negative_elements(int *array, unsigned int size)
{
    unsigned int count = 0, index = 0;
    while(index < size)
    {
        if(*(array + index) < 0)
            count++;
        
        index++;
    }
    return count;
}

int main(void)
{
    int array[] = {7, -5, 4, 3, -9, 2, -8};
    unsigned int size = sizeof(array) / sizeof(*array);
    printf("%u\n", negative_elements(array, size));
    
    return 0;
}