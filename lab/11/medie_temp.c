/*
O structură conține ora (ca si o alta structura potrivita) la care s-a măsurat o anumită temperatură și valoarea acestei temperaturi (real). Se cere n<=10 și apoi n temperaturi. Se cere apoi o oră de început și una de sfârșit. Să se afișeze media temperaturilor care au fost măsurate în acel interval orar, inclusiv în capetele acestuia.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct {
    int ora;
    int temp;
} date;

int input(date arr[], unsigned int *n)
{
    unsigned int count = 0;
    count += scanf("%d", n);
    for (unsigned int i = 0; i < *n; i++)
    {
        count += scanf("%d %d", &arr[i].ora, &arr[i].temp);
    }

    return count;
}

float medie(date arr[], unsigned int n, unsigned int start, unsigned int end)
{
    float total = 0;
    unsigned int count = 0;

    for(unsigned int i = 0; i < n; i++)
    {
        if(arr[i].ora >= start && arr[i].temp <= end)
        {
            count++;
            total += arr[i].temp;
        }
    }

    return total / count;
}

int main(void)
{   
    unsigned int n = 0;
    date arr[MAX];

    if(input(arr, &n) != 2 * n + 1)
    {
        printf("Nu s-au citit toate datele!\n");
        return -1;
    }

    unsigned int ora_inceput = 0, ora_sfarsit = 0;

    printf("Introduceti ora de inceput: ");

    if(scanf("%d", &ora_inceput) != 1)
    {
        printf("Nu s-a citit ora de inceput!\n");
        return -1;
    }
    
    printf("Introduceti ora de sfarsit: ");

    if(scanf("%d", &ora_sfarsit) != 1)
    {
        printf("Nu s-a citit ora de sfarsit!\n");
        return -1;
    }

    printf("Media temp intre orele %d si %d este %.02f", ora_inceput, ora_sfarsit, medie(arr, n, ora_inceput, ora_sfarsit));

    return 0;
}