/*
Se citește de la intrarea standard un număr necunoscut de perechi de 2 numere despărțite prin . - punct (exemplu 34.21 17.88 90.100). Aceste perechi reprezintă coordonatele unor puncte în sistemul cartezian primul reprezentând abscisa (x) si al doilea ordonata (y). Se va proiecta și implementa o structură de date corespunzătoare și se vor stoca toate punctele citite într-un tablou. Nu se cunoaște numărul de perechi de numere astfel ca se va aloca dinamic tabloul și se va folosi minimul de memorie. Programul va afișa la ieșirea standard punctul cel mai apropiat de origine.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CHUNK 20

typedef struct
{
    int64_t x;
    int64_t y;
} point;

double distance(point *p)
{
    return sqrt(p->x * p->x + p->y * p->y);
}

point *input_array(uint64_t *size)
{
    point element;
    point *array = NULL;

    uint64_t index = 0;
    uint64_t current_size = 0;

    while(1)
    {
        if(scanf("%lld.%lld", &element.x, &element.y) != 2)
        {
            printf("Input ended\n");
            break;
        }

        if(index == current_size)
        {
            current_size += CHUNK;
            array = realloc(array, current_size * sizeof(point));

            if(array == NULL)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        *(array + index) = element;
        index++;
    }
    if(array != NULL)
        *size = index;
    
    return array;
}

void print_array(point *array, uint64_t size)
{
    for(uint64_t i = 0; i < size; i++)
    {
        printf("x = %lld , y = %lld\n", (array + i)->x, (array + i)->y);
    }
    printf("\n");
}


void closest_to_origin(point *array, uint64_t size)
{
    double min = distance(array);
    point *closest = array;

    for(uint64_t i = 1; i < size; i++)
    {
        if(distance(array + i) < min)
        {
            min = distance(array + i);
            closest = array + i;
        }
    }

    printf("Closest to origin: x = %lld , y = %lld , distance = %lf\n", closest->x, closest->y, min);
}

int main(void)
{
    point *array = NULL;
    uint64_t size = 0;
    array = input_array(&size);

    if(array == NULL)
    {
        printf("Array is empty\n");
        return 0;
    }

    print_array(array, size);

    closest_to_origin(array, size);
    
    free(array);
    
    return 0;
}
