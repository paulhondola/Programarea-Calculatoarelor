/*
Se citește de la intrarea standard un număr necunoscut de perechi de 2 numere despărțite prin . - punct (exemplu 34.21 17.88 90.100). Aceste perechi reprezintă coordonatele unor puncte în sistemul cartezian primul reprezentând abscisa (x) si al doilea ordonata (y). Se va proiecta și implementa o structură de date corespunzătoare și se vor stoca toate punctele citite într-un tablou. Nu se cunoaște numărul de perechi de numere astfel ca se va aloca dinamic tabloul și se va folosi minimul de memorie. Programul va afișa la ieșirea standard punctul cel mai apropiat de origine.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CHUNK 10

typedef struct
{
    int x;
    int y;
} point;

float distance(point *p)
{
    return sqrt(p->x * p->x + p->y * p->y);
}

point *input_point(void)
{
    point *p = NULL;

    if((p = malloc(sizeof(point))) == NULL)
    {
        return NULL;
    }

    if(scanf("%d.%d", &p->x, &p->y) != 2)
    {
        return NULL;
    }

    return p;
}

point ** input_array(void)
{
    point **array = NULL;

    int index = 0;
    int size = 0;

    while(1)
    {
        if(index == size)
        {
            size += CHUNK;

            if((array = realloc(array, size * sizeof(point *))) == NULL)
            {
                return NULL;
            }
        }

        if((array[index] = input_point()) == NULL)
        {
            break;
        }

        index++;
    }

    return array;
}

void print_points(point **array)
{
    point **iterator = array;

    printf("Points:\n");

    while(*iterator != NULL)
    {
        printf("%d.%d\n", (*iterator)->x, (*iterator)->y);
        iterator++;
    }
}


void free_array(point **array)
{
    point **iterator = array;

    while(*iterator != NULL)
    {
        free(*iterator);
        iterator++;
    }
}


void min_distance(point **array)
{
    float min = distance(*array);

    point ** iterator = array;

    while(*iterator != NULL)
    {
        if(min > distance(*iterator))
            min = distance(*iterator);

        iterator++;
    }

    printf("The minimum distance to origin is: %f\n", min);
}

int main(void)
{
    point **point_arr = NULL;

    point_arr = input_array();

    print_points(point_arr); 


    min_distance(point_arr);


    free_array(point_arr);
    free(point_arr);

    return 0;
}