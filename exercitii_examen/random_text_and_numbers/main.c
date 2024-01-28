/*
Se da fisierul “random_text_numbers.txt” si se cere sa se scrie intr-un alt fisier pe primul rand suma tuturor numerelor intregi din fisier,urmat de textul ramas prin eliminarea numerelor.Se puncteaza citirea eficienta din fisier.
*/

#include "files.h"
#include <stdint.h>
#define BUFFER_SIZE 1024

int main(void)
{
    FILE *input = open_file("random_text_numbers.txt", "r");
    FILE *output = open_file("output.txt", "w");

    uint64_t sum = 0;

    char buffer[BUFFER_SIZE];
    char aux[BUFFER_SIZE];

    aux[0] = '\0';

    while(1)
    {
        if(fgets(buffer, BUFFER_SIZE, input) == NULL)
        {
            break;
        }

        for(int i = 0; i < strlen(buffer); i++)
        {
            if(buffer[i] >= '0' && buffer[i] <= '9')
            {
                sum += buffer[i] - '0';
                strcpy(aux, buffer + i + 1);
                strcpy(buffer + i, aux);
                i--;
            }
        }

        fprintf(output, "%s", buffer);
    }

    fprintf(output, "\n%llu\n", sum);

    close_file(input);
    close_file(output);

    return 0;
}
