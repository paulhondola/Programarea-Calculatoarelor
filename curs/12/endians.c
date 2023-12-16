#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
    
    ENDIANS

    - ordinea in care sunt stocate octetii unui numar in memorie

    - DOAR LA NIVEL HARDWARE, NU ARE LEGATURA CU C

    

    LITTLE ENDIAN -> Intel x86, x64, ARM

    octetul cel mai putin semnificativ este stocat la adresa cea mai mica

    u32 - 0x13  7B  A9  CE 
            x+3 x+2 x+1 x


    x | x+1 | x+2 | x+3
    CE | A9 | 7B | 13


    13 - msb
    CE - lsb


    BIG ENDIAN -> PowerPC, SPARC, MIPS

    u32 - 0x13  7B  A9  CE 
              x x+1 x+2 x+3

    x | x+1 | x+2 | x+3
    13 | 7B | A9 | CE



    noi o sa lucram cu little endian

    */


    return 0;
}