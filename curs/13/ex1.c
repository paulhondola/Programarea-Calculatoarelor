#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
    long a;
    long b;

    if(argc != 3)
    {
        fprintf(stderr, "Numar incorect de argumente!"); // printeaza in fisierul stderr
        printf("Numar incorect de argumente!"); // printeaza in fisierul stdout
        perror("Numar incorect de argumente!"); // printeaza in fisierul stderr
        return 1;
    }

    a = strtol(argv[1], NULL, 10);

    if (errno != 0)
    {
        perror(NULL);
        printf("Eroare la conversie la a!\n");
        exit(1);
    }

    b = strtol(argv[2], NULL, 10);

    if (errno != 0)
    {
        perror(NULL);
        printf("Eroare la conversie la b!\n");
        exit(1);
    }

    printf("Suma %ld + %ld = %ld\n", a, b, a + b);

    return 0;
}
