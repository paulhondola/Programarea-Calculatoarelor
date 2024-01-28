#include "header.h"
#define CHUNK 16

TIME_T read_time(FILE *file)
{
    TIME_T time;

    fscanf(file, "%02hhu:%02hhu:%02hhu", &time.ora, &time.minut, &time.secunda);

    return time;
}


TIME_T *read_all_times(FILE *file, uint32_t *size)
{
    TIME_T *times = NULL;
    uint32_t index = 0;
    uint32_t allocated_size = 0;

    while (!feof(file))
    {
        if (index == allocated_size)
        {
            allocated_size += CHUNK;
            times = realloc(times, allocated_size * sizeof(TIME_T));

            if (times == NULL)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        times[index++] = read_time(file);
    }
    *size = index;

    return times;
}
