#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define READ_ARRAY_SIZE 4000
#define CHUNK 4000

typedef struct
{
    uint16_t data;
    uint32_t count;
} NUMBER;


int find_number(const NUMBER *array, int size, uint16_t number)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i].data == number)
        {
            return i;
        }
    }

    return -1;
}


NUMBER *add_to_array(NUMBER *array, int *size, const uint16_t *data_array, int data_array_size)
{
    static int index = 0;
    static int current_size = 0;
    int j = -1;

    for(int i = 0; i < data_array_size; i++)
    {
        if(index == current_size)
        {
            current_size += CHUNK;
            array = realloc(array, current_size * sizeof(NUMBER));

            if(array == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }

        if((j = find_number(array, index, data_array[i])) == -1)
        {
            array[index].data = data_array[i];
            array[index].count = 1;
        }
        else
        {
            array[j].count++;
        }
        

        index++;
    }

    *size = index;

    return array;
}



void print_array_to_file(NUMBER *array, int size, const char *filepath)
{
    FILE *output = NULL;

    output = fopen(filepath, "w");

    if(output == NULL)
    {
        perror(NULL);
        exit(-1);
    }



    for(int i = 0; i < size; i++)
    {
        fprintf(output, "%04x - %2d\n", array[i].data, array[i].count);
    }

    if(fclose(output) == EOF)
    {
        perror(NULL);
        exit(-1);
    }
}


int main(int argc, char **argv)
{
    FILE *input = NULL;
    uint16_t aux[READ_ARRAY_SIZE];
    NUMBER *array = NULL;
    int size = 0;

    unsigned long read = 0;

    if(argc != 3)
    {
        fprintf(stderr, "Numar incorect de argumente!\n");
        exit(-1);
    }

    

    input = fopen(argv[1], "rb");

    if(input == NULL)
    {
        perror(NULL);
        exit(-1);
    }


    while((read = fread(aux, sizeof(uint16_t), READ_ARRAY_SIZE, input)) > 0)
    {
        array = add_to_array(array, &size, aux, read);
    }

    if(fclose(input) == EOF)
    {
        perror(NULL);
        exit(-1);
    }

    print_array_to_file(array, size, argv[2]);

    free(array);

    //print_array(array, size);
    return 0;
}
