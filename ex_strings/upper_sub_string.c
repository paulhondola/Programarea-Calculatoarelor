#include <stdio.h>
#include <string.h>

void modify_string(char *text, unsigned int start, unsigned int end)
{
    for(unsigned int i = start; i < end; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] - 'a' + 'A';
        }
    }
}

int upper_sub_string(char *text_1, char *text_2)
{
    int num_apparitions = 0;

    unsigned int len_1 = strlen(text_1);
    unsigned int len_2 = strlen(text_2);
    for(unsigned int i = 0; i < len_1;)
    {
        char *ptr = strstr(text_1 + i, text_2);

        if(ptr == NULL)
            break;

        num_apparitions++;

        i = ptr - text_1;

        modify_string(text_1, i, i + len_2);

        i += len_2;
    }

    return num_apparitions;
}

int main(void)
{
    char s1[] = "Acesta este un stringstring si stringul este terminat cu 0x00";
    char s2[] = "string";
    int r = upper_sub_string(s1, s2);

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("r = %d\n", r);
    return 0;
}



