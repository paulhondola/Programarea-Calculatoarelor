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

typedef struct idk {
    float real;
    float imag;
} Complex;


Complex sum(Complex a, Complex b)
{
    Complex value;
    value.real = a.real + b.real;
    value.imag = a.imag + b.imag;
    return value;
}

Complex dif(Complex a, Complex b)
{
    Complex value;
    value.real = a.real - b.real;
    value.imag = a.imag - b.imag;
    return value;
}

// (a + bi) * (c + di) = (a * c - b * c + (b * c + a * d)i)
Complex multiply(Complex a, Complex b)
{
    Complex value;
    value.real = (a.real * b.real) - (a.imag * b.imag);
    value.imag = (a.imag * b.real) + (a.real * b.imag);
    return value;
}

// (a + bi) / (c + di) = (ac + bd + (bc - ad)i) / (c * c + d * d)
// real - (ac + bd) / (cc + dd)
// imag - (bc - ad) / (cc + dd)
Complex division(Complex a, Complex b)
{
    if(b.real == 0 && b.imag == 0)
    {
        printf("Nu se poate imparti la 0\n");
        exit(1);
    }

    Complex value;
    value.real = ((a.real * b.real) * (a.imag * b.imag)) / ((b.real * b.real) * (b.imag * b.imag));
    value.imag = ((a.imag * b.real) * (a.real * b.imag)) / ((b.real * b.real) * (b.imag * b.imag));
    return value;
}

double module(Complex number)
{
    return sqrt((number.real * number.real) + (number.imag * number.imag));
}

void print_complex(Complex number)
{
    printf("Numarul complex este %.02f+%.02fi\n", number.real, number.imag);
}

int input(Complex *number)
{
    return scanf("%f%f", &number->real, &number->imag);
}

int main(void)
{   
    Complex a, b;
    
    if(input(&a) != 2)
        return -1;

    if(input(&b) != 2)
        return -1;

    print_complex(a);
    print_complex(b);

    Complex c;
    c = sum(a, b);

    printf("Suma -> ");
    print_complex(c);

    c = dif(a, b);

    printf("Diferenta -> ");
    print_complex(c);
    
   
    c = multiply(a, b);

    printf("Produsul -> ");
    print_complex(c);
    
    c = division(a, b);

    printf("Raportul -> ");
    print_complex(c);

    printf("Modulul lui a este -> %lf\n", module(a));
    printf("Modulul lui b este -> %lf\n", module(b));
    
    return 0;
}