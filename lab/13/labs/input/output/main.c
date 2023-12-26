#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BUFFER 1024

void quick_sort(int *array, uint64_t size)
{
    if(size <= 1)
        return;
    
    int pivot = array[size / 2];
    
    int *left = array;
    int *right = array + size - 1;
    
    while(left <= right)
    {
        if(*left < pivot)
        {
            left++;
            continue;
        }
        
        if(*right > pivot)
        {
            right--;
            continue;
        }
        
        int temp = *left;
        *left = *right;
        *right = temp;
        
        left++;
        right--;
    }
    
    quick_sort(array, right - array + 1);
    quick_sort(left, array + size - left);
}


FILE *open_file(char *filename, char *mode)
{   
    FILE *file = fopen(filename, mode);

    if(file == NULL)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    return file;
    
}

void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
}


int *input_array(uint64_t *size, FILE *file)
{
    uint64_t used_size = 0, allocated_size = 0;

    int *array = NULL;
    int input = 0;

    while(1)
    {
        if(fscanf(file, "%d", &input) != 1)
        {
            break;
        }    

        if(used_size == allocated_size)
        {
            allocated_size += BUFFER;
            array = realloc(array, allocated_size * sizeof(int));

            if(array == NULL)
            {
                perror("realloc error");
                exit(EXIT_FAILURE);
            }
        }

        array[used_size++] = input;

    }

    *size = used_size;

    return array;
}


void print_array(const int *array, const uint64_t size, FILE *file)
{
    for(uint64_t i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", array[i]);
    }
}

int main(void)
{
    FILE *input = NULL, *output = NULL;

    input = open_file("input.txt", "r");

    output = open_file("output.txt", "w");


    int *array = NULL;
    uint64_t size = 0;

    array = input_array(&size, input);

    quick_sort(array, size);

    print_array(array, size, output);  



    close_file(input);

    close_file(output);
    return 0;
}