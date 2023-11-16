#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1000

int input_text(char *text, int size)
{
    int new_size = 0;
    while((text[new_size] = getchar()) != EOF)
    {
        if (text[new_size] == '.')
        {
            new_size++;
            break;
        }

        if(new_size == size)
            break;
            
        new_size++;
    }

    return new_size;
}

void cypher(char *text, int size, int increment)
{
    increment %= 26;
    for(int i = 0; i < size; i++)
    {
        if (isalpha(text[i]))
        {
            // litere mici
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] += increment;
                if(text[i] > 'z')
                    text[i] = text[i] - 26 ;
            }
            
            // litere mari
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] += increment;
                if(text[i] > 'Z')
                    text[i] = text[i] - 26;
            }
        } 
    }
}

void print_text(char *text, int size)
{
    for(int i = 0; i < size; i++)
        putchar(text[i]);

    putchar('\n');
}

int main(void)
{
    char message[SIZE];
    int new_size = input_text(message, SIZE);

    printf("Size: %d\n", new_size);

    print_text(message, new_size);
    
    cypher(message, new_size, 3);

    print_text(message, new_size);

    return 0;
}