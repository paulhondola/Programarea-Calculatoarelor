#include "complex.h"
#include <stdio.h>

int count = 6;

COMPLEX read(void)
{
    COMPLEX result;

    scanf("%d %d", &result.real, &result.imag);

    return result;
}


void print_complex(COMPLEX number)
{
    printf("%d + %di\n", number.real, number.imag);
}
