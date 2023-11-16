// Scrieți un program, folosind getchar() pentru citire, care, primind la stdin redirectat un fișier text va tipari la iesirea standard histograma literelor, adica distributia in procente a literelor din fisier. Se considera in calcul doar litere mari si litere mici. Programul va printa pe cate un rand litera si procentajul de aparitie.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

int total_char(int *array)
{
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
        sum += array[i];

    return sum;
}

void percentage(int *array)
{
    int total = total_char(array);
    for(int i = 0; i < SIZE; i++)
    {
        printf("%c --> %f%%\n", 'a' + i, (float) array[i] * 100 / total);
    }
}

void input()
{
    int freq_array[SIZE];
    memset(freq_array, 0, sizeof(freq_array)); // 4 bytes per int * 26 elements = 104 bytes

    char ch = 0;
    while((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                freq_array[ch - 'A']++;
            }
            else
            {
                freq_array[ch - 'a']++;
            }
        }
    }

    percentage(freq_array);
}



int main(void)
{
    input();
    return 0;
}