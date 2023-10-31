/*
O variabilă de tip char ocupă în memorie 8 biţi. Aceşti 8 biţi pot fi împărţiţi în 2 zone de câte 4 biţi. În fiecare zonă de câte 4 biţi s-ar putea memora câte un număr între 0 şi 15. Scrieţi un program care citeşte două numere între 1 şi 10 şi le memorează (împachetează) în cele două zone de câte 4 biţi ale unei variabile de tip char. După memorare, programul va despacheta valorile memorate şi le va afişa.
*/

#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint8_t n1 = 0, n2 = 0, ch = 0;

    printf("n1 = ");
    scanf("%hhu", &n1);

    printf("n2 = ");
    scanf("%hhu", &n2);

    ch = (n1 << 4) | n2;

    printf("Caracterul format din numerele %hhu si %hhu este %c", n1, n2, ch);
    
    return 0;
}