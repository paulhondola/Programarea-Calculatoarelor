#include "header.h"

TIME_T get_min_time(TIME_T *times, uint32_t size)
{
    TIME_T smallest_time = times[0];
    for (uint32_t i = 1; i < size; i++)
    {
        if (times[i].ora < smallest_time.ora)
            smallest_time = times[i];
        else if (times[i].ora == smallest_time.ora)
        {
            if (times[i].minut < smallest_time.minut)
                smallest_time = times[i];
            else if (times[i].minut == smallest_time.minut)
            {
                if (times[i].secunda < smallest_time.secunda)
                    smallest_time = times[i];
            }
        }
    }
    return smallest_time;
}


TIME_T get_difference(TIME_T *time1, TIME_T *time2)
{
    TIME_T difference;
    difference.secunda = time1->secunda - time2->secunda;
    difference.minut = time1->minut - time2->minut;
    difference.ora = time1->ora - time2->ora;

    if (difference.secunda < 0)
    {
        difference.secunda += 60;
        difference.minut--;
    }
    if (difference.minut < 0)
    {
        difference.minut += 60;
        difference.ora--;
    }

    return difference;
}


uint8_t greater_time(TIME_T *time1, TIME_T *time2)
{
    if (time1->ora > time2->ora)
        return 1;
    else if (time1->ora == time2->ora)
    {
        if (time1->minut > time2->minut)
            return 1;
        else if (time1->minut == time2->minut)
        {
            if (time1->secunda > time2->secunda)
                return 1;
        }
    }
    return 0;
}


void sort_all_times(TIME_T *times, uint32_t size)
{
    TIME_T aux;
    uint8_t ok = 0;

    do
    {
        ok = 0;
        for(uint32_t i = 0; i < size - 1; i++)
            if(greater_time(&times[i], &times[i + 1]))
            {
                aux = times[i];
                times[i] = times[i + 1];
                times[i + 1] = aux;
                ok = 1;
            }

    } while (ok);
}
