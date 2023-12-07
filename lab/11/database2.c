/*
Sa se implementeze o baza de date care contine urmatoarele tipuri de produse:
     - stick USB: interfata (A sau C), capacitate
     - baterie: voltaj
Fiecare produs va avea asociate un pret, stoc si un cod unic. Operatiile vor fi:
     - introducere - introduce un nou produs, inclusiv codul sau. Daca codul exista deja, se incrementeaza stocul, altfel se considera stoc=1
     - listare - se listeaza doar produsele existente pe stoc
     - stergere - se da un cod si se decrementeaza stocul. Produsele cu stoc 0 raman in baza de date. Daca deja este 0, se emite mesaj de atentionare.
Programul va folosi alocare dinamica, astfel incat sa se foloseasca doar strictul necesar de memorie. Utilizatorul va avea la dispozitie un meniu, de unde va putea apela fiecare functie.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHUNK 10

typedef enum
{
    A = 1,
    C = 2
} USB_INTERFACE_TYPE;

typedef enum
{
    USB = 1,
    BATTERY = 2
} PRODUCT_TYPE;

typedef union
{
     USB_INTERFACE_TYPE usb_interface;
     int battery_voltage;
} details;

typedef struct
{
     PRODUCT_TYPE type;

     details details;

     int price;

     int stock;

     int code;
} PRODUCT;


PRODUCT input_data(void)
{
     PRODUCT item;

     printf("Type:\n");
     printf("1. USB\n");
     printf("2. Battery\n");
     scanf("%d", &item.type);

     switch (item.type)
     {
     case USB:
          printf("Interface:\n");
          printf("1. A\n");
          printf("2. C\n");

          scanf("%d", &item.details.usb_interface);

          switch (item.details.usb_interface)
          {
          case A:
               item.details.usb_interface = A;
               break;

          case C:
               item.details.usb_interface = C;
               break;

          default:
               printf("Invalid interface!\n");
               break;
          }

          break;
     case BATTERY:
          printf("Voltage: ");
          scanf("%d", &item.details.battery_voltage);
          break;

     default:
          printf("Invalid type!\n");
          break;
     }

     printf("Price: ");
     scanf("%d", &item.price);

     item.stock = 1;

     printf("Code: ");
     scanf("%d", &item.code);

     return item;
}


uint8_t check_for_duplicate_product(PRODUCT *database, int size, PRODUCT item)
{
     for (int i = 0; i < size; i++)
     {
          if (database[i].code == item.code)
          {
               database[i].stock++;
               return 1;
          }
     }

     return 0;
}


PRODUCT *add_to_database(PRODUCT *database, int *size)
{
     static int allocated_size = 0;

     if(*size == allocated_size)
     {
          allocated_size += CHUNK;
          database = realloc(database, allocated_size * sizeof(PRODUCT));

          if(database == NULL)
          {
               printf("Error allocating memory!\n");
               exit(EXIT_FAILURE);
          }
     }

     if(database == NULL)
          return NULL;

     PRODUCT item = input_data();
     
     if(check_for_duplicate_product(database, *size, item) == 0)
     {
          database[*size] = item;
          (*size)++;
     }

     return database;
}

void print_database(PRODUCT *database, int size)
{
     for (int i = 0; i < size; i++)
     {
          switch (database[i].type)
          {
          case USB:
               printf("USB ");

               switch (database[i].details.usb_interface)
               {
               case A:
                    printf("A ");
                    break;

               case C:
                    printf("C ");
                    break;

               default:
                    break;
               }

               break;
          
          case BATTERY:
               printf("Battery ");

               printf("%d ", database[i].details.battery_voltage);
               break;
          default:
               break;
          }

          printf("%d %d %d\n", database[i].price, database[i].stock, database[i].code);
     }
}

int main(void)
{
     PRODUCT *database = NULL;

     int size = 0;

     database = add_to_database(database, &size);

     database = add_to_database(database, &size);

     database = add_to_database(database, &size);

     print_database(database, size);

     free(database);

     return 0;
}
