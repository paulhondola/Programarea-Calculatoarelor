#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 1024

FILE *open_file(char *path, char *mode)
{
    FILE *file = fopen(path, mode);

    if (file == NULL)
    {
        perror(NULL);
        exit(1);
    }

    return file;
}


int *read_array(char *filepath, long long int *size)
{
    FILE *file = open_file(filepath, "r");

    int *array = NULL;
    int input = 0;

    long long int used_size = 0;
    long long int allocated_size = 0;

    while(1)
    {
        if(fscanf(file, "%d", &input) != 1)
        {
            break;
        }

        if (used_size == allocated_size)
        {
            allocated_size += CHUNK;
            array = realloc(array, allocated_size * sizeof(int));
        }

        array[used_size++] = input;
    }

    fclose(file);

    *size = used_size;

    return array;
}


void print_array(char *filepath, int *array, long long int size)
{
    FILE *file = open_file(filepath, "w");

    for (long long int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", array[i]);
    }

    fclose(file);
}


void quick_sort(int *array, long long int size)
{
    if(size <= 1)
        return;


    long long int i = 0, j = size - 1;
    int pivot = array[size / 2];


    while(i <= j)
    {
        while(array[i] < pivot)
        {
            i++;
        }

        while(array[j] > pivot)
        {
            j--;
        }

        if(i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
    }

    quick_sort(array, j + 1);
    quick_sort(array + i, size - 1);
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        perror("Not enough arguments");
        exit(1);
    }

    char *input_path = argv[1];
    char *output_path = argv[2];


    int *array = NULL;

    long long int size = 0;

    array = read_array(input_path, &size);

    quick_sort(array, size);

    print_array(output_path, array, size);

    free(array);

    return 0;
}
