#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 26

void print_array(int *array, int size)
{
    char ch = 'a';
    for(int i = 0; i < size; i++)
        printf("%c ---> %d\n", ch + i, array[i]);
    
    printf("\n");
}


void input_array(int *array, int size)
{
    char ch = 0;

    while((ch = getchar()) != EOF)
    {
        if(islower(ch))
        {
            printf("Read!!!!!!!!!!!!!!!!!\n");
            array[ch - 'a']++;
        }
            
    }
}


int main(void)
{
    int frecv[SIZE];

    memset(frecv, 0, sizeof(frecv));

    input_array(frecv, SIZE);

    print_array(frecv, SIZE);

    return 0;
}