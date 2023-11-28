#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(void)
{
    /*
    
    CODURI DE EROARE STANDARD

    #include <errno.h>
    
    printf("%d\n", errno); - ultima eroare intalnita

    -> 0 - nu a aparut nicio eroare - succes

    man errno - coduri de eroare standard
    
    perror("mesaj"); - afiseaza mesajul si ultima eroare intalnita

    
    exit(status) - 0 - succes, altceva - eroare
    
    
    */

    int n = strtol("123", NULL, 100);

    perror("eroare vere");
    
    printf("%d\n", n);


    return 0;
}