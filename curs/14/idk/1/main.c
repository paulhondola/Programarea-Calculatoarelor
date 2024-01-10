#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int num;
    int denom;

} FRACTION_TYPE;


FILE *open_file(const char *file_path, const char *mode)
{
    FILE *file = fopen(file_path, mode);

    if (file == NULL)
    {
        perror(file_path);
        exit(1);
    }

    return file;
}


void close_file(FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("Error closing file");
        exit(2);
    }
}


void read_array(FILE *file, FRACTION_TYPE *array, int *size)
{
    int counter = 0;

    FRACTION_TYPE ratio;

    while(fscanf(file, "%d %d", &ratio.num, &ratio.denom) == 2)
    {
        array[counter++] = ratio;
    }

    *size = counter;
}


void print_array(FILE *file, FRACTION_TYPE *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d/%d\n", array[i].num, array[i].denom);
    }
}


// a / b + c / d ---> (a * d + b * c) / (b * d)

FRACTION_TYPE add(FRACTION_TYPE *a, FRACTION_TYPE *b)
{
    FRACTION_TYPE result;

    result.num = a->num * b->denom + a->denom * b->num;
    result.denom = a->denom * b->denom;

    return result;
}


FRACTION_TYPE multiply(FRACTION_TYPE *a, FRACTION_TYPE *b)
{
    FRACTION_TYPE result;

    result.num = a->num * b->num;
    result.denom = a->denom * b->denom;

    return result;
}



FRACTION_TYPE add_all(FRACTION_TYPE *array, int size)
{
    FRACTION_TYPE result = array[0];

    for (int i = 1; i < size; i++)
    {
        result = add(&result, &array[i]);
    }

    return result;
}


FRACTION_TYPE multiply_all(FRACTION_TYPE *array, int size)
{
    FRACTION_TYPE result = array[0];

    for (int i = 1; i < size; i++)
    {
        result = multiply(&result, &array[i]);
    }

    return result;
}


int main(void)
{
    FRACTION_TYPE array[MAX_SIZE];
    int size = 0;

    FILE *input_file = open_file("date.in", "r");
    FILE *output_file = open_file("date.out", "w");


    read_array(input_file, array, &size);

    print_array(output_file, array, size);


    FRACTION_TYPE sum = add_all(array, size);

    FRACTION_TYPE product = multiply_all(array, size);

    fprintf(output_file, "Sum: %d/%d\n", sum.num, sum.denom);

    fprintf(output_file, "Product: %d/%d\n", product.num, product.denom);
    

    close_file(input_file);
    close_file(output_file);

    return 0;
}
