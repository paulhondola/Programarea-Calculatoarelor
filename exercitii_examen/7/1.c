#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

int main(void)
{
    char string[SIZE + 1];

    if(fgets(string, SIZE, stdin) == NULL)
    {
        perror("invalid input");
        exit(-1);
    }

    printf("%s", string);

    return 0;
}
