// Se va citi un n<=10. Se vor citi apoi pe rând n nume. Se cere ca în final să fie afișat numele cel mai lung și lungimea sa

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10000

int main(void)
{
    char text[SIZE], max_str[SIZE];
    unsigned int n = 0, max = 0;
    scanf("%d\n", &n);

    for(unsigned int i = 0; i < n; i++)
    {
        if(fgets(text, SIZE, stdin) == NULL)
        {
            printf("fgets error\n");
            return -1;
        }
        
        unsigned int new_size = strlen(text);
        if(new_size > max)
        {
            max = new_size;
            strcpy(max_str, text);
        }
    }
    
    printf("Stringul de lungimea maxima %u este: %s\n", max, max_str);

    return 0;
}