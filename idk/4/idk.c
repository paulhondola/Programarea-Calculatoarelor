#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100
#define CODE_SIZE 8


int validare(char *cod)
{
    // LLL-lll\0
    // 012 3 456 7

    // 0 - 3 / 3 - 3 / 4 - 8

    for(int i = 0; i < CODE_SIZE / 2 - 1 ; i++)
    {
        if( !(cod[i] >= 'A' && cod[i] <= 'Z') )
        {
            printf("Cod incorect 1!\n");
            return 0;
        }
    }

    if(cod[CODE_SIZE / 2 - 1] != '-')
    {
        printf("Cod incorect 2!\n");
        return 0;
    }

    for(int i = CODE_SIZE / 2; i < CODE_SIZE - 1; i++)
    {
        if( !(cod[i] >= 'a' && cod[i] <= 'z') )
        {
            printf("Cod incorect 3!\n");
            return 0;
        }
    }


    return 1;
}


void input(char code_array[][CODE_SIZE], int *size)
{
    printf("Introduceti numarul de elemente:\n");

    if(scanf("%d", size) != 1)
    {
        printf("Nu ati introdus un numar!\n");
        exit(-1);
    }

    if(*size > ARRAY_SIZE)
    {
        printf("Prea multe elemente!\n");
        exit(-1);
    }

    char space;
    
    for(int i = 0; i < *size; i++)
    {
        while(1)
        {
            space = getchar();

            if(fgets(code_array[i], CODE_SIZE, stdin) == NULL)
            {
                printf("Cod invalid!\n");
                continue;
            }

            if(!validare(code_array[i]))
            {
                continue;
            }

            printf("%s\n", code_array[i]);
            
            break;
        }

    }


}


int main(void)
{
    char code_array[ARRAY_SIZE][CODE_SIZE];

    int size = 0;

    input(code_array, &size);



    return 0;
}
