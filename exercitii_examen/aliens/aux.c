#include "aliens.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 16


FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if(file == NULL)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }

    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
}


ALIEN_T read_alien_data(FILE *file)
{
    ALIEN_T alien;

    // TODO : NAME

    if(fgets(alien.name, MAX_NAME_LENGTH, file) == NULL)
    {
        perror("name");
        exit(EXIT_FAILURE);
    }

    if(alien.name[strlen(alien.name) - 1] == '\n')
        alien.name[strlen(alien.name) - 1] = '\0';

    // TODO : COLOR

    int color;

    if(fscanf(file, "%d", &color) != 1)
    {
        perror("color");
        exit(EXIT_FAILURE);
    }

    switch(color)
    {
        case 0:
            alien.color = RED;
            break;
        case 1:
            alien.color = GREEN;
            break;
        case 2:
            alien.color = BLUE;
            break;
        default:
            perror("invalid color");
            exit(EXIT_FAILURE);
    }

    // TODO : DAY / MONTH / YEAR
    
    if(fscanf(file, "%hhu %hhu %hu", &alien.day, &alien.month, &alien.year) != 3)
    {
        perror("date");
        exit(EXIT_FAILURE);
    }

    // TODO : SENATE MEMBERS

    int senate_member;

    if(fscanf(file, "%d", &senate_member) != 1)
    {
        perror("senate member");
        exit(EXIT_FAILURE);
    }

    switch(senate_member)
    {
        case 0:
            alien.senate_member = NO;
            break;
        case 1:
            alien.senate_member = YES;
            break;
        default:
            perror("invalid senate member");
            exit(EXIT_FAILURE);
    }

    // TODO : SPACE

    fgetc(file);

    return alien;
}


void print_alien_data(ALIEN_T *alien, FILE *file)
{
    fprintf(file, "Name: %s\n", alien->name);

    switch(alien->color)
    {
        case RED:
            fprintf(file, "Color: Red\n");
            break;
        case GREEN:
            fprintf(file, "Color: Green\n");
            break;
        case BLUE:
            fprintf(file, "Color: Blue\n");
            break;
    }

    fprintf(file, "Date of birth: %hhu/%02hhu/%hu\n", alien->day, alien->month, alien->year);

    switch(alien->senate_member)
    {
        case NO:
            fprintf(file, "Senate member: No\n");
            break;
        case YES:
            fprintf(file, "Senate member: Yes\n");
            break;
    }
}


void print_all_aliens(CITY_T *city, char *filename)
{
    FILE *file = open_file(filename, "w");

    fprintf(file, "City name: %s\n", city->name);

    for(int i = 0; i < city->count; ++i)
    {
        fprintf(file, "\n");
        print_alien_data(&city->aliens[i], file);
    }

    close_file(file);
}


CITY_T *read_city_data(char *filename)
{
    FILE *file = open_file(filename, "r");
    CITY_T *city = malloc(sizeof(CITY_T));

    city->aliens = NULL;

    if(fgets(city->name, MAX_NAME_LENGTH, file) == NULL)
    {
        perror("city name");
        exit(EXIT_FAILURE);
    }
    
    if(city->name[strlen(city->name) - 1] == '\n')
        city->name[strlen(city->name) - 1] = '\0';


    ALIEN_T alien;
    int index = 0;
    int allocated_size = 0;

    while(!feof(file))
    {
        if(index == allocated_size)
        {
            allocated_size += CHUNK;
            city->aliens = realloc(city->aliens, allocated_size * sizeof(ALIEN_T));
            if(city->aliens == NULL)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        alien = read_alien_data(file);
        city->aliens[index++] = alien;
    }

    city->count = index;

    close_file(file);

    return city;
}


CITY_T *make_copy(CITY_T *main_city)
{
    CITY_T *copy = NULL;

    copy = malloc(sizeof(CITY_T));

    copy->aliens = malloc(main_city->count * sizeof(ALIEN_T));

    strcpy(copy->name, main_city->name);
    copy->count = main_city->count;

    for(int i = 0; i < main_city->count; i++)
    {
        copy->aliens[i] = main_city->aliens[i];
    }

    return copy;
}


CITY_T *sort_city(CITY_T *main_city)
{
    CITY_T *sorted_city = make_copy(main_city);

    ALIEN_T aux;
    int ok = 0;

    do
    {
        ok = 0;

        for(int i = 0; i < sorted_city->count - 1; i++)
            if(strcmp(sorted_city->aliens[i].name, sorted_city->aliens[i + 1].name) > 0)
            {
                aux = sorted_city->aliens[i];
                sorted_city->aliens[i] = sorted_city->aliens[i + 1];
                sorted_city->aliens[i + 1] = aux;
                ok = 1;
            }

    } while (ok);
    
    return sorted_city;
}
