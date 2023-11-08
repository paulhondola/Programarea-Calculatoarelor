// Se citește un n<=10 și apoi n nume de persoane, fiecare nume putând apărea de mai multe ori. Să se afișeze de câte ori apare fiecare nume

#include <stdio.h>
#include <string.h>

#define NAME_SIZE 10000
#define SIZE 10
int main(void)
{
    static struct date
    {
        char nume[NAME_SIZE];
        unsigned int nr_aparitii;

    } persoane[SIZE];

    struct date *ptr = persoane;

    char input[NAME_SIZE];

    unsigned int n = 0, i, j;
    
    scanf("%d\n", &n);

    for(i = 0; i < n; i++)
    {
        if(fgets(input, NAME_SIZE, stdin) == NULL)
            return -1;
        
        strcpy(*ptr++->nume, input);

    }

    for(i = 0; i < n; i++)
        printf("%s\n", *(ptr + i)->nume);

    return 0;
}