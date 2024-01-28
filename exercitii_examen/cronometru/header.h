#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t ora;
    uint8_t minut;
    uint8_t secunda;
} TIME_T;

FILE *open_file(char *filename, char *mode);

void close_file(FILE *f);

TIME_T read_time(FILE *file);

TIME_T *read_all_times(FILE *file, uint32_t *size);

void write_time(FILE *file, TIME_T *time);

void write_all_times(FILE *file, TIME_T *times, uint32_t size);

TIME_T get_min_time(TIME_T *times, uint32_t size);

void write_all_differences(FILE *file, TIME_T *times, uint32_t size);

void sort_all_times(TIME_T *times, uint32_t size);

TIME_T get_difference(TIME_T *time1, TIME_T *time2);

#endif
