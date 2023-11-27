/*
Se consideră o structură Persoana care are un câmp nume și altul varsta. Să se scrie o funcție care primește ca parametru o persoană și îi modifică numele astfel încât prima literă să fie mare iar restul mici. Să se testeze funcția cu o persoană citită de la tastatură.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    char nume[MAX];
    int varsta;
} Persoana;

int input(Persoana *input)
{
    // numele

    if(fgets(input->nume, MAX, stdin) == NULL)
    {
        printf("eroare la citirea numelui\n");
        return -1;
    }

    input->nume[strlen(input->nume) - 1] = 0;

    if(scanf("%d", &input->varsta) != 1)
    {
        printf("eroare la citirea varstei\n");
        return -1;
    }

    return 1;
}

void output(Persoana output)
{
    printf("Numele persoanei -> %s / Varsta -> %d\n", output.nume, output.varsta);
}




void modify(Persoana *pers)
{
    unsigned int len = strlen(pers->nume);

    if(isalpha(pers->nume[0]))
        pers->nume[0] = toupper(pers->nume[0]);

    for(unsigned int i = 1; i < len; i++)
        if(!isalpha(pers->nume[i - 1]) && isalpha(pers->nume[i]))
        {
            if(islower(pers->nume[i]))
                pers->nume[i] = toupper(pers->nume[i]);
        }
        else if(isalpha(pers->nume[i - 1]) && isalpha(pers->nume[i]))
        {
            if(isupper(pers->nume[i]))
                pers->nume[i] = tolower(pers->nume[i]);
        }
}


int main(void)
{
    Persoana pers;

    if(input(&pers) == -1)
        return -1;

    output(pers);

    modify(&pers);

    output(pers);

    return 0;
}