#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Se citește un text care este alcătuit doar din litere. Să se afișeze pentru fiecare literă de câte ori apare în text

#define SIZE 26
#define TEXT_SIZE 10000

int main(void)
{
    char text[TEXT_SIZE];
    unsigned int count[SIZE];

    memset(count, 0, SIZE * sizeof(unsigned int));

    if(fgets(text, TEXT_SIZE, stdin) == NULL)
        return -1;

    printf("Textul citit este: %s\n", text);
    printf("Lungimea textului este: %ld\n", strlen(text) - 1);

    for(int i = 0; i < strlen(text); i++)
        if(isalpha(text[i]))
            count[tolower(text[i]) - 'a']++;

    for(int i = 0; i < SIZE; i++)
        if(count[i])
            printf("Litera %c ---> %d\n", i + 'a', count[i]);

    return 0;
}