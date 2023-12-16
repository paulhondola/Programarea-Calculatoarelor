#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define SIZE 1000

int main(void)
{
    // SIRURI DE CARACTERE

    char nume_string[SIZE];
    char string1[] = {'P', 'A', 'U', 'L', 0};
    char string2[] = {'P', 'A', 'U', 'L', '\0'};
    printf("%s\n", string1);

    char string3[] = "PAUL";
    char *string4 = "PAUL"; // READ ONLY - NEMODIFICABIL

    // string4[0] = 'B'; --> ERROR

    printf("%s\n", string4);

    // TXT[0] - PRIMUL CARACTER / *TXT
    // TXT[1] - AL DOILEA CARACTER / *(TXT + 1)
    // TXT[2] - AL TREILEA CARACTER / *(TXT + 2)
    // TXT[3] - AL PATRULEA CARACTER / *(TXT + 3)

    char empty_string[] = ""; // memorat pe un byte
    printf("%d\n", strlen(empty_string));
    // CITIREA DE LA TASTATURA A UNUI SIR DE CARACTERE

    char input[10];
    scanf("%9s", input); 
    printf("string: %s\n", input);

    if(input[9] == 0)
    {
        printf("sirul este complet\n");
    }
    else
    {
        printf("sirul nu este complet\n");
    }

    // SCANF - SE OPRESTE LA SPATIU / ENTER / EOF

    // fgets - citeste pana la \n / EOF

    //fgets(input, 50, stdin); // citeste n - 1 caractere

    // fgets - returneaza stringul citit sau NULL in caz de eroare

    
    if(fgets(input, 50, stdin) != NULL)
    {
        printf("string: %s\n", input);
    }
    else
    {
        printf("eroare la citire\n");
    }
    

    return 0;
}