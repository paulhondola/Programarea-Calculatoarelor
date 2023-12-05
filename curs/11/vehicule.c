#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef enum { 
    TIP_VEHICUL_TROTINETA, 
    TIP_VEHICUL_BICICLETA,
    TIP_VEHICUL_AUTOMOBIL,
    TIP_VEHICUL_AUTOBUZ
} TIP_VEHICUL;

typedef enum
{
    TIP_TROTINETA_CLASICA,
    TIP_TROTINETA_ELECTRICA
} TIP_TROTINETA;

typedef union 
{
    TIP_TROTINETA tip_trotineta;
    uint8_t nr_viteze;
    uint16_t an_fabricatie;
    uint8_t nr_locuri;

} TIP_CARACTERISTICA;



typedef struct
{
    uint8_t nr_roti;
    TIP_VEHICUL tip_vehicul;
    TIP_CARACTERISTICA caracteristica;

    // caracteristica

    /*

    tip trotineta - clasica / electrica - daca tip vehicul este trotineta

    nr viteze - daca tip vehicul este bicicleta

    an fabricatie - daca tip vehicul este automobil

    nr locuri - daca tip vehicul este autobuz

    */

} VEHICUL;



void print_vehicul(const VEHICUL *vehicul)
{
    printf("Vehicul cu %d roti - ", vehicul->nr_roti);

    switch (vehicul->tip_vehicul)
    {
        case TIP_VEHICUL_TROTINETA:

            printf("Trotineta ");

            switch (vehicul->caracteristica.tip_trotineta)
            {
                case TIP_TROTINETA_CLASICA:
                    printf("clasica\n");
                    break;
                case TIP_TROTINETA_ELECTRICA:
                    printf("electrica\n");
                    break;
            }
            break;

        case TIP_VEHICUL_BICICLETA:

            printf("Bicicleta ");
            printf("cu %d viteze\n", vehicul->caracteristica.nr_viteze);
            break;

        case TIP_VEHICUL_AUTOMOBIL:

            printf("Automobil ");
            printf("fabricat in anul %4d\n", vehicul->caracteristica.an_fabricatie);
            break;

        case TIP_VEHICUL_AUTOBUZ:

            printf("Autobuz ");
            printf("cu %2d locuri\n", vehicul->caracteristica.nr_locuri);
            break;

    }
}


void print_vehicul_array(const VEHICUL *vehicule, uint8_t nr_vehicule)
{
    for (uint8_t i = 0; i < nr_vehicule; i++)
    {
        print_vehicul(&vehicule[i]);
    }
}


int main(void)
{
    VEHICUL v[10];

    v[0].nr_roti = 2;
    v[0].tip_vehicul = TIP_VEHICUL_TROTINETA;
    v[0].caracteristica.tip_trotineta = TIP_TROTINETA_CLASICA;

    v[1].nr_roti = 2;
    v[1].tip_vehicul = TIP_VEHICUL_TROTINETA;
    v[1].caracteristica.tip_trotineta = TIP_TROTINETA_ELECTRICA;

    v[2].nr_roti = 2;
    v[2].tip_vehicul = TIP_VEHICUL_BICICLETA;
    v[2].caracteristica.nr_viteze = 18;

    v[3].nr_roti = 4;
    v[3].tip_vehicul = TIP_VEHICUL_AUTOMOBIL;
    v[3].caracteristica.an_fabricatie = 2023;

    v[4].nr_roti = 6;
    v[4].tip_vehicul = TIP_VEHICUL_AUTOBUZ;
    v[4].caracteristica.nr_locuri = 50;

    print_vehicul_array(v, 5);

    return 0;
}