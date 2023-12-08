/*
Să se scrie un program ce definește un tip de date utilizator ce modelează un număr complex și o serie de funcții ce realizeaza operațiile de bază cu numere complexe. Programul se va testa prin numere introduse de la tastatură

o funcție de adunare ce primește ca argument două numere complexe și returnează un număr complex ce reprezinta suma celor 2 numere complexe primite ca și argumente

o funcție de scadere ce primește ca argument două numere complexe și returnează un număr complex ce reprezinta diferența celor 2 numere complexe primite ca și argumente

o funcție de înmulțire ce primește ca argument două numere complexe și returnează un număr complex ce reprezinta produsul celor 2 numere complexe primite ca și argumente

o funcție de afișare a unui număr complex în formă algebrică: a+bj - primește ca argument numărul complex

o funcție de calcul a modulului unui număr compex - primește ca argument numărul complex și returnează un double ce reprezintă modulul numărului complex. Se va folosi functia sqrt din <math.h>. 

Pentru compilare se adauga parametrul -lm la gcc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHUNK 10

typedef struct {
    float real;
    float imag;
} Complex;

Complex sum(Complex *a, Complex *b)
{
    Complex value;
    value.real = a->real + b->real;
    value.imag = a->imag + b->imag;
    return value;
}

Complex dif(Complex *a, Complex *b)
{
    Complex value;
    value.real = a->real - b->real;
    value.imag = a->imag - b->imag;
    return value;
}

// (a + bi) * (c + di) = (a * c - b * c + (b * c + a * d)i)
Complex multiply(Complex *a, Complex *b)
{
    Complex value;
    value.real = (a->real * b->real) - (a->imag * b->imag);
    value.imag = (a->imag * b->real) + (a->real * b->imag);
    return value;
}

// (a + bi) / (c + di) = (ac + bd + (bc - ad)i) / (c * c + d * d)
// real - (ac + bd) / (cc + dd)
// imag - (bc - ad) / (cc + dd)
Complex division(Complex *a, Complex *b)
{
    if(b->real == 0 && b->imag == 0)
    {
        printf("Nu se poate imparti la 0\n");
        exit(1);
    }

    Complex value;
    value.real = ((a->real * b->real) * (a->imag * b->imag)) / ((b->real * b->real) * (b->imag * b->imag));
    value.imag = ((a->imag * b->real) * (a->real * b->imag)) / ((b->real * b->real) * (b->imag * b->imag));
    return value;
}

double module(Complex *number)
{
    return sqrt((number->real * number->real) + (number->imag * number->imag));
}


void print_complex(Complex *number)
{
    printf("Numarul complex este %.02f+%.02fi\n", number->real, number->imag);
}

int input(Complex *number)
{
    return scanf("%f%f", &number->real, &number->imag);
}


Complex *input_array(int *size)
{
    Complex *array = NULL;

    Complex input = {0, 0};

    int index = 0;
    int current_size = 0;
 
    while(1)
    {
        
        if(scanf("%f%f", &input.real, &input.imag) != 2)
        {
            break;
        }

        if(index == current_size)
        {
            current_size += CHUNK;
            array = realloc(array, current_size * sizeof(Complex));

            if(array == NULL)
            {
                printf("Nu s-a putut aloca memorie\n");
                exit(1);
            }
        }

        array[index++] = input;
    }

    * size = index;

    return array;
}

void print_array(Complex *array, int size)
{
    printf("Size: %d\n", size);
    for(int i = 0; i < size; i++)
    {
        print_complex(&array[i]);
    }
}

Complex sum_of_all(Complex *array, int size)
{
    Complex SUM = {0, 0};

    for(int i = 0; i < size; i++)
    {
        SUM = sum(&SUM, &array[i]);
    }

    return SUM;
}


int main(void)
{   
    Complex *array = NULL;

    int size = 0;

    array = input_array(&size);

    print_array(array, size);

    Complex SUM = {0, 0};

    SUM = sum_of_all(array, size);

    printf("Suma tuturor numerelor complexe este:\n");
    print_complex(&SUM);

    free(array);
    
    return 0;
}
