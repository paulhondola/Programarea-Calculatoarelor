// Un fișier html conține o serie de tag-uri, adică cuvinte cheie între simbolurile < și >.
/*
Aceste tag-uri (etichete) pot fi de două feluri:
- pereche (de exemplu <head>-început și </head>-încheiere)
- singulare (de exemplu <br>)
Se cere să se citească de la stdin un fișier html, folosind redirectare și funcția getchar, și să se numere câte tag-uri de început și câte tag-uri de încheiere conține fișierul.
*/

// <> - tag inceput
// </> - tag sfarsit

#include <stdio.h>


int main(void)
{
    char prev = 0;
    char ch = 0;

    int tag_start = 0;
    int tag_end = 0;

    prev = getchar();
    while((ch = getchar()) != EOF)
    {
        // tag inceput
        if(prev == '<' && ch != '/')
        {
            while(ch != '>')
                ch = getchar();
            tag_start++;
        }
            

        // tag sfarsit
        if(prev == '<' && ch == '/')
            tag_end++;

        prev = ch;
    }

    printf("Tag-uri de inceput: %d\n", tag_start);
    printf("Tag-uri de sfarsit: %d\n", tag_end);

    return 0;
}