// Se va citi un n<=10. Se vor citi apoi n produse, fiecare definit prin nume (un șir de caractere), cantitate (real) și preț unitar (real). Unele produse pot să fie date de mai multe ori, cu valori diferite. Să se calculeze pentru fiecare produs cantitatea și prețul total, iar în final să se calculeze și prețul global pentru toate produsele. Exemplu:     

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_SIZE 1000

struct produs
{
    char nume[NAME_SIZE];
    double cantitate;
    double pret_unitar;
};

int input(struct produs *ptr, int size)
{
    char name[NAME_SIZE];
    double ammount;
    double price;
    
    for(int i = 0; i < size; i++)
    {
        char space = getchar();

        // citim numele

        if(fgets(name, NAME_SIZE, stdin) == NULL)
        {
            printf("Eroare la citirea numelui\n");
            return -1;
        }

        printf("name = %s\n", name);

        // citim cantitatea

        if(scanf("%lf", &ammount) != 1)
        {
            printf("Eroare la citirea cantitatii\n");
            return -1;
        }

        printf("ammount = %lf\n", ammount);

        // citim pretul unitar

        if(scanf("%lf", &price) != 1)
        {
            printf("Eroare la citirea pretului unitar\n");
            return -1;
        }

        printf("price = %lf\n", price);
    }

    return 0;
}

int main(void)
{
    unsigned int n = 0;

    scanf("%u", &n);
    char space = getchar();
    if(n > 10)
    {
        printf("Wrong input\n");
        return -1;
    }
        
    static struct produs produse[10];



    return 0;
}
