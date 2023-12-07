#include <stdio.h>

#define TARGET 5

int main(void)
{
    /*
    
    1,2,3,4,5,6,6 - target = 5, number is 5
    1, 2, 3, 4 - target = 5, number is 0
    1, 2, 3, 4, 5 - target = 5, number is 5

    reads multiple lines and determines if the target is in the line, if not, print 0, if yes, print the number
    */

    int input = 0;
    int count_per_line = 0;

    while(1)
    {
        // check if a newline is entered

        if (scanf("%d", &input) == '\n')
        {
            // check if the target is in the line
            if (count_per_line == TARGET)
            {
                printf("%d\n", TARGET);
            }
            else
            {
                printf("0\n");
            }
            count_per_line = 0;
        }
        else
        {
            // check if the target is in the line
            if (input == TARGET)
            {
                count_per_line++;
            }
        }


        
        // check for EOF
        if (scanf("%d", &input) == EOF)
        {
            break;
        }
    }
    

    return 0;
}