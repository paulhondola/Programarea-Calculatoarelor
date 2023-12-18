/*
Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului. Sa se scrie un program format din mai multe functii: o functie ce citeste un astfel de fisier si stocheaza numerele intr-un tablou. O functie care sorteaza acest tablou in ordine descrescatoare, o functie ce scrie un astfel de tablou intr-un alt fisier in format text, fiecare numar in zecimal pe un alt rand. Program testa functionalitatea prin citirea aceluiasi fisier ca si cel de la exercitiul anterior, va sorta datele obtinute si le va scrie in fisier conform cerintei.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHUNK 4096

FILE *open_file(char *filepath, char *mode)
{
    FILE *file = fopen(filepath, mode);
    
    if(file == NULL)
    {
        perror("file not found");
        exit(EXIT_FAILURE);
    }
    
    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("cannot close file");
        exit(EXIT_FAILURE);
    }
}


int *input_array(uint64_t *size, FILE *file)
{
    uint64_t used_size = 0, allocated_size = 0;
    
    int *array = NULL;
    
    int aux[CHUNK];
    
    uint64_t read = 0;
    
    while(1)
    {
        read = fread(aux, sizeof(int), CHUNK, file);
        
        if(read == 0)
            break;
        
        if(used_size == allocated_size)
        {
            allocated_size += read;
            
            array = realloc(array, allocated_size * sizeof(int));
        }
    
        
        for(uint64_t i = 0; i < read; i++)
        {
            array[used_size++] = aux[i];
        }
        
    }
    
    *size = used_size;
    
    return array;
}


void quick_sort(int *array, uint64_t size)
{
    if(size <= 1)
        return;
    
    int pivot = array[size / 2];
    
    int *left = array;
    int *right = array + size - 1;
    
    while(left <= right)
    {
        if(*left > pivot)
        {
            left++;
            continue;
        }
        
        if(*right < pivot)
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


void output_to_file(int *array, uint64_t size, FILE *file)
{
    for(uint64_t i = 0; i < size; i++)
        fprintf(file, "%llu -> %d\n", i + 1, array[i]);
}

int main(void)
{
    FILE *input = open_file("integers.bin", "rb");
    FILE *output = open_file("integers.txt", "w");
    
    int *array = NULL;
    uint64_t size = 0;
    
    array = input_array(&size, input);
    
    quick_sort(array, size);
    
    output_to_file(array, size, output);
    
    free(array);
    
    close_file(input);
    close_file(output);
    
    return 0;
}
