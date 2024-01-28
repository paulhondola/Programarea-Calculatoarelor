#include "header.h"

void write_time(FILE *file, TIME_T *time)
{
    fprintf(file, "%02hhu:%02hhu:%02hhu\n", time->ora, time->minut, time->secunda);
}


void write_all_times(FILE *file, TIME_T *times, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
        write_time(file, &times[i]);
}

void write_difference(FILE *file, TIME_T *time1, TIME_T *time2)
{
    TIME_T difference = get_difference(time1, time2);
    fprintf(file, "+  %02hhu:%02hhu:%02hhu\n", difference.ora, difference.minut, difference.secunda);
}


void write_all_differences(FILE *file, TIME_T *times, uint32_t size)
{
    TIME_T min = get_min_time(times, size);

    for (uint32_t i = 0; i < size; i++)
        write_difference(file, &times[i], &min);
}
