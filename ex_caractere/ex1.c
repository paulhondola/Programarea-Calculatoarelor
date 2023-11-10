// Scrieți un program, folosind getchar() și putchar() prin care se numără cuvintele de la stdint. Se consideră un cuvânt ca fiind o secvență de litere mici și/sau mari care despărțite prin unul sau mai multe spații, tab-uri, linii noi și EOF. Testarea se va face atât clasic prin scriere la stdin cât și prin redirectare cu un fișier text realizat inainte ca și caz de test catre intrarea standard a programului
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch = 0, prev_ch = 0, word_count = 0;
    while((ch = getchar()) != EOF)
    {
        if(isspace(ch) && !isspace(prev_ch))
            word_count++;

        prev_ch = ch;
    }

    printf("Word count: %d\n", word_count);

    return 0;
}