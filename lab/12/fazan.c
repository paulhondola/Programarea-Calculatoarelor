/*
Jocul fazan: se citesc de la tastatură cuvinte separate prin spaţii albe (spaţiu, TAB sau ENTER), până la întâlnirea cuvântului vid. Pornind de la cuvintele citite, se construieşte un şir de caractere după următoarele reguli:
    - Primul cuvânt citit se adaugă la şirul de caractere
    - Fiecare din următoarele cuvinte citite se adaugă la şirul de caractere dacă ultimele două litere ale şirului coincid cu primele două litere ale cuvântului (nu se face distincţie între literele mici şi cele mari);
Cuvintele adăugate la şirul de caractere sunt despărţite de caracterul ’-’. Să se afişeze şirul astfel construit. Programul va folosi alocare dinamică astfel încât spaţiul de memorie utilizat să fie minim.
Spre exemplu, pentru intrarea:

Fazan Antic Noe icoana Egipt naftalina nimic Narcisa trei altceva santier iarba Caine Pisica erudit

se afişează:

Fazan-Antic-icoana-naftalina-Narcisa-santier-erudit
*/

// citim primul cuvant

// il adaug in sirul aloct dinamic

// citim urmatorul cuvant

// daca ultimele 2 litere din sirul dinamic coincid cu primele 2 litere din cuvantul citit

// adaugam cuvantul citit in sirul dinamic

// altfel

// continuam citirea

// afisam sirul dinamic

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_CHUNK 100
#define STRING_CHUNK 1000

char *input_word(void)
{
    char *word = NULL;
    int size = 0;
    int allocated_size = 0;
    char c = 0;

    while(1)
    {
        if(scanf("%c", &c) != 1)
        {
            break;
        }

        if(size == allocated_size)
        {
            allocated_size += WORD_CHUNK;
            word = realloc(word, allocated_size * sizeof(char));

            if(word == NULL)
            {
                printf("Not enough memory\n");
                return NULL;
            }
        }

        word[size++] = c;

        if(c == ' ' || c == '\t' || c == '\n')
        {
            break;
        }
    }

    if(size == 0)
    {
        free(word);
        return NULL;
    }

    word[size - 1] = '\0';

    return word;
}

char *fazan_string(void)
{
    char *main_string = NULL;
    char *word = NULL;

    int main_string_allocated_size = 0;

    // fill in the first word

    if((word = input_word()) == NULL)
    {
        return NULL;
    }

    main_string = malloc(STRING_CHUNK * sizeof(char));
    
    if(main_string == NULL)
    {
        printf("Not enough memory\n");
        return NULL;
    }

    strcpy(main_string, word);

    main_string_allocated_size = STRING_CHUNK;

    free(word);

    // fill in the rest of the words
    
    while(1)
    {
        if((word = input_word()) == NULL)
        {
            break;
        }

        if(strlen(main_string) + strlen(word) + 1 >= main_string_allocated_size)
        {
            main_string_allocated_size += STRING_CHUNK;
            main_string = realloc(main_string, main_string_allocated_size * sizeof(char));

            if(main_string == NULL)
            {
                printf("Not enough memory\n");
                return NULL;
            }
        }
        
        if(tolower(main_string[strlen(main_string) - 2]) == tolower(word[0]) && tolower(main_string[strlen(main_string) - 1]) == tolower(word[1]))
        {
            strcat(main_string, "-");
            strcat(main_string, word);
        }
        
        free(word);
    }

    return main_string;
}

int main(void)
{
    char *string = fazan_string();

    if(string == NULL)
    {
        return -1;
    }

    printf("%s\n", string);

    free(string);

    return 0;
}
