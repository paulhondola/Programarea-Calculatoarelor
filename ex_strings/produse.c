// Se va citi un n<=10. Se vor citi apoi n produse, fiecare definit prin nume (un șir de caractere), cantitate (real) și preț unitar (real). Unele produse pot să fie date de mai multe ori, cu valori diferite. Să se calculeze pentru fiecare produs cantitatea și prețul total, iar în final să se calculeze și prețul global pentru toate produsele. Exemplu:     

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_SIZE 1000
#define SIZE 10

typedef struct
{
    char name[NAME_SIZE];
    double total_quantity;
    double total_price;
} Product;


unsigned int check_duplicate(Product *ptr, char *string, unsigned int size)
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(ptr[i].name, string) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int input(Product *ptr, unsigned int *num)
{
    char space = 0;

    char text[NAME_SIZE];
    double quantity = 0;
    double price = 0;

    unsigned int size = 0;

    for(int i = 0; i < *num; i++)
    {
        // citirea numelui

        space = getchar();
        space = getchar();

        if(fgets(text, NAME_SIZE, stdin) == NULL)
        {
            printf("Error at fgets\n");
            return -1;
        }

        // elimina \n de la finalul numelui

        text[strlen(text) - 1] = '\0';

        // citirea cantitatii

        space = getchar();

        if(scanf("%lf", &quantity) != 1)
        {
            printf("Error at scanf1\n");
            return -1;
        }

        // citirea pretului

        space = getchar();

        if(scanf("%lf", &price) != 1)
        {
            printf("Error at scanf2\n");
            return -1;
        }

        // verifica daca exista deja in product

        if(check_duplicate(ptr, text, size) == 1)
        {
            for(int j = 0; j < size; j++)
            {
                if(strcmp(ptr[j].name, text) == 0)
                {
                    ptr[j].total_quantity += quantity;
                    ptr[j].total_price += price * quantity;
                }
            }
        }
        else
        {
            strcpy(ptr[size].name, text);
            ptr[size].total_quantity = quantity;
            ptr[size].total_price = price * quantity;
            size++;
        }
    }

    *num = size;
    return 0;
}

int input_number_elements(unsigned int *ptr)
{
    if(scanf("%u", ptr) != 1)
    {
        printf("Error at scanf\n");
        return -1;
    }

    return 0;
}

void print_products(Product *ptr, unsigned int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("%s ", ptr[i].name);
        printf("%lf ", ptr[i].total_quantity);
        printf("%lf\n", ptr[i].total_price);
    }
}


float get_pret_global(Product *ptr, unsigned int num)
{
    float pret_global = 0;

    for(int i = 0; i < num; i++)
    {
        pret_global += ptr[i].total_price;
    }

    return pret_global;
}


int main(void)
{
    unsigned int num = 0;

    if(input_number_elements(&num) == -1)
    {
        printf("Error at input_number_elements\n");
        return -1;
    }

    Product arr[num];
    
    if(input(arr, &num) == -1)
    {
        printf("Error at input\n");
        return -1;
    }

    print_products(arr, num);

    printf("Pret global: %f\n", get_pret_global(arr, num));

    return 0;
}