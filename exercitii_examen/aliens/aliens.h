#ifndef __ALIENS_H

#define __ALIENS_H
#include <stdint.h>
#include <stdio.h>

#define MAX_NAME_LENGTH 20

typedef struct
{
    char name[MAX_NAME_LENGTH];
    enum {RED, GREEN, BLUE} color;
    uint8_t day, month;
    uint16_t year;
    enum {NO, YES} senate_member;
} ALIEN_T;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int count;
    ALIEN_T *aliens;
} CITY_T;

FILE *open_file(char *filename, char *mode);

void close_file(FILE *file);

CITY_T *read_city_data(char *filename);

void print_all_aliens(CITY_T *city, char *filename);

CITY_T *make_copy(CITY_T *main_city);

CITY_T *sort_city(CITY_T *main_city);

#endif
