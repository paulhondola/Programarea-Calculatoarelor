#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define CHUNK 1024

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


typedef struct
{
    int64_t size;
    uint8_t *nums;

} BIG_NUMBER_TYPE;



void read_array(FILE *input_file, BIG_NUMBER_TYPE *number)
{
    number->size = 0;
    number->nums = NULL;

    char ch = 0;

    int64_t counter = 0;

    int64_t capacity = 0;

    while(1)
    {
        ch = (char)fgetc(input_file);

        if(ch == '\n' || ch == EOF)
        {
            break;
        }


        if(counter == capacity)
        {
            capacity += CHUNK;

            number->nums = realloc(number->nums, (uint64_t)capacity * sizeof(uint8_t));

            if(number->nums == NULL)
            {
                perror("Error reallocating memory");
                exit(3);
            }
        }


        number->nums[counter++] = (uint8_t)ch - '0';
    }

    number->size = counter;
}


void print_array(FILE *output_file, BIG_NUMBER_TYPE *number)
{
    int64_t i = 0;

    if(i == 0 && number->nums[i] == 0)
    {
        i++;
    }


    for(;i < number->size; i++)
    {
        fprintf(output_file, "%hhu", number->nums[i]);
    }

    fprintf(output_file, "\n");
}



//     1 2 3 4 5 6 7 
// 1 2 3 4 5 6 7 8 9 

// 


BIG_NUMBER_TYPE add_numbers(BIG_NUMBER_TYPE *a, BIG_NUMBER_TYPE *b)
{
    BIG_NUMBER_TYPE result;

    result.size = 0;
    result.nums = NULL;

    if(b->size > a->size)
    {
        BIG_NUMBER_TYPE *tmp = a;
        a = b;
        b = tmp;
    }

    // A - MAXIMUL

    result.nums = malloc((uint64_t)(a->size + 1) * sizeof(uint8_t));

    result.size = a->size + 1;

    uint8_t carry = 0;

    
    for(int64_t b_index = b->size - 1, a_index = a->size - 1; b_index >= 0; b_index--, a_index--)
    {   
        result.nums[a_index + 1] = (a->nums[a_index] + b->nums[b_index] + carry) % 10;

        carry = (a->nums[a_index] + b->nums[b_index] + carry) / 10;
    }

    for(int64_t i = a->size - b->size - 1; i >= 0; i--)
    {
        result.nums[i + 1] = (a->nums[i] + carry) % 10;

        carry = a->nums[i] / 10;
    }

    result.nums[0] = carry;


    // 7 + 9 - 16 

    // 16 / 10 - 1 - carry
    // 16 % 10 - 6 - result

    return result;
}


int main(void)
{
    FILE *input_file = open_file("date.in", "r");
    FILE *output_file = open_file("date.out", "w");



    BIG_NUMBER_TYPE number_1, number_2;

    read_array(input_file, &number_1);

    read_array(input_file, &number_2);

    print_array(output_file, &number_1);

    print_array(output_file, &number_2);

    BIG_NUMBER_TYPE result = add_numbers(&number_1, &number_2);


    print_array(output_file, &result);

    free(number_1.nums);
    free(number_2.nums);
    free(result.nums);

    close_file(input_file);
    close_file(output_file);

    return 0;
}
