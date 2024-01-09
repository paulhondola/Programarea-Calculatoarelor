#ifndef __COMPLEX_H

#define __COMPLEX_H
#include <stdint.h>

typedef struct
{
    int32_t real;
    int32_t imag;
} COMPLEX;

extern int count;

COMPLEX read(void);
void print_complex(COMPLEX c);

#endif
