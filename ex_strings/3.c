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

    int n = 0, i, j, found = 0;
    
    scanf("%d\n", &n);

    for(i = 0; i < n; i++)
    {
        if(fgets(input, NAME_SIZE, stdin) == NULL)
            return -1;
        
        for(j = 0; j < i, !found; j++)
            if(strcmp((ptr + j)->nume, input) == 0)
                (ptr + j)->nr_aparitii++, found++;

        if(!found)
        {
            strcpy((ptr + i)->nume, input);
            (ptr + i)->nr_aparitii = 1;
        }
    }

    for(i = 0; i < n; i++)
        printf("%s ---> %u\n", (ptr + i)->nume, (ptr + i)->nr_aparitii);

    return 0;
}