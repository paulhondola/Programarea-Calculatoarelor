/*
Să se implementeze o bază de date ce modelează animale. Animelele pot fi insecte, păsări, mamifere și pești. O insectă se caracterizează prin număr picioare și durata medie de viată în zile, o pasăre prin viteza de zbor și lungimea aripilor, un mamifer prin greutate, înălțime și tip de mancare (carnivor, ierbivor, omnivor) iar un pește prin greutate, adâncimea maximă de înnot și salinitatea apei (în procentaj). Să se definnească structurile de date necesare cât mai abstract posibil și cu amprenta de memorie minima. Se va defini un tablou de astfel de structuri și se vor implementa funcții de adaugare animal, stergere animal și printare animale.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 10

enum animal_type {Insect = 1, Bird, Mammal, Fish};

#pragma region database

typedef struct
{
    
    int nr_legs;
    int lifespan;

} insect;

typedef struct
{
    
    float flight_speed;
    float wing_span;

} bird;

typedef struct
{
    
    float weight;
    float height;
    enum {carnivore, herbivore, omnivore} food_type;

} mammal;

typedef struct 
{

    float weight;
    float max_depth;
    float salinity;

} fish;

#pragma endregion

#pragma region functions -> print

void print_insect(insect *insect)
{
    printf("Insect: \n");
    printf("Number of legs: %d\n", insect->nr_legs);
    printf("Lifespan: %d\n", insect->lifespan);
}

void print_bird(bird *bird)
{
    printf("Bird: \n");
    printf("Flight speed: %f\n", bird->flight_speed);
    printf("Wing span: %f\n", bird->wing_span);
}

void print_mammal(mammal *mammal)
{
    printf("Mammal: \n");
    printf("Weight: %f\n", mammal->weight);
    printf("Height: %f\n", mammal->height);
    printf("Food type: %d\n", mammal->food_type);
}

void print_fish(fish *fish)
{
    printf("Fish: \n");
    printf("Weight: %f\n", fish->weight);
    printf("Max depth: %f\n", fish->max_depth);
    printf("Salinity: %f%%\n", fish->salinity);
}

#pragma endregion

#pragma region functions -> add

insect *add_insect(void)
{
    insect *insect = NULL;

    if((insect = malloc(sizeof(insect))) == NULL)
    {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }

    printf("Number of legs: ");
    if(scanf("%d", &insect->nr_legs) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Lifespan: ");
    if(scanf("%d", &insect->lifespan) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    return insect;
}

bird *add_bird(void)
{
    bird *bird = NULL;

    if((bird = malloc(sizeof(bird))) == NULL)
    {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }

    printf("Flight speed: ");
    if(scanf("%f", &bird->flight_speed) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Wing span: ");
    if(scanf("%f", &bird->wing_span) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    return bird;
}

mammal *add_mammal(void)
{
    mammal *mammal = NULL;

    if((mammal = malloc(sizeof(mammal))) == NULL)
    {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }

    printf("Weight: ");
    if(scanf("%f", &mammal->weight) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Height: ");
    if(scanf("%f", &mammal->height) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Food type: ");
    if(scanf("%d", &mammal->food_type) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    return mammal;
}

fish *add_fish(void)
{
    fish *fish = NULL;

    if((fish = malloc(sizeof(fish))) == NULL)
    {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }

    printf("Weight: ");
    if(scanf("%f", &fish->weight) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Max depth: ");
    if(scanf("%f", &fish->max_depth) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Salinity: ");
    if(scanf("%f", &fish->salinity) != 1)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    return fish;
}

#pragma endregion


void **allocate_memory(void)
{
    void **database = NULL;

    if((database = malloc(CHUNK * sizeof(void *))) == NULL)
    {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }

    return database;
}


void **realloc_memory(void **database, int *size)
{
    if((database = realloc(database, (*size + CHUNK) * sizeof(void *))) == NULL)
    {
        printf("Error reallocating memory!\n");
        exit(EXIT_FAILURE);
    }

    *size += CHUNK;

    return database;
}

void add_animal(char **database, int *size)
{
    int option = -1;

    printf("What type of animal do you want to add?\n");
    printf("1. Insect\n");
    printf("2. Bird\n");
    printf("3. Mammal\n");
    printf("4. Fish\n");
    printf("0. Exit\n");

    scanf("%d", &option);

    switch (option)
    {
        case Insect:
            printf("Insect\n");

            if(*size % CHUNK == 0)
            {
                database = realloc_memory(database, *size * sizeof(void *));
            }

            database[*size] = add_insect();
            (*size)++;

            break;
        case Bird:
            printf("Bird\n");

            if(*size % CHUNK == 0)
            {
                database = realloc_memory(database, *size * sizeof(void *));
            }

            database[*size] = add_bird();
            (*size)++;

            break;
        case Mammal:
            printf("Mammal\n");

            if(*size % CHUNK == 0)
            {
                database = realloc_memory(database, *size * sizeof(void *));
            }

            database[*size] = add_mammal();
            (*size)++;

            break;
        case Fish:
            printf("Fish\n");

            if(*size % CHUNK == 0)
            {
                database = realloc_memory(database, *size * sizeof(void *));
            }

            database[*size] = add_fish();
            (*size)++;

            break;
        default:
            printf("Exit\n");
            break;
    }
}


void free_all(void **database, int * size)
{
    for(int i = 0; i < *size; i++)
    {
        free(database + i);
    }

    *size = 0;
}

int main(void)
{
    void **database = NULL;
    int size = 0;

    database = allocate_memory();

    //add_animal(database);


    free_all(database, &size);
    free(database);

    return 0;
}


