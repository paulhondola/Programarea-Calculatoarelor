#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define ASCII_COUNT 127

FILE *open_file(char *path, char *mode)
{
    FILE *file = fopen(path, mode);

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


void print_histoline(FILE *input, FILE *output)
{
    char line[BUFFER_SIZE];

    int counter[ASCII_COUNT];

    memset(counter, 0, sizeof(counter));

    long long int total = 0;

    while(1)
    {
        // read a line, if eof is reached, break

        if(fgets(line, BUFFER_SIZE, input) == NULL)
        {
            break;
        }

        // create the histogram

        for(unsigned long i = 0; i < strlen(line); i++)
        {
            if(isalpha(line[i]))
            {
                total++;

                if(islower(line[i]))
                    counter[(int)line[i]]++;
                else
                    counter[(int)line[i] - 'A' + 'a']++;
                
            }
        }
    }

    printf("%lld\n", total);

    for(int i = 0; i < ASCII_COUNT; i++)
    {
        if(islower(i))
            fprintf(output, "%c -> %f\n", i, 100 * (float)counter[i] / total);
    }

}







int main(int argc, char **argv)
{
    if(argc != 3)
    {
        perror("Invalid parameters");
        exit(EXIT_FAILURE);
    }

    char *input_path = argv[1];
    char *output_path = argv[2];
   

    FILE *input = open_file(input_path, "r");
    FILE *output = open_file(output_path, "w");


    print_histoline(input, output);

    close_file(input);
    close_file(output);
    

    return 0;
}
