/*
Să se implementeze o bază de date ce modelează animale. Animelele pot fi insecte, păsări, mamifere și pești. O insectă se caracterizează prin număr picioare și durata medie de viată în zile, o pasăre prin viteza de zbor și lungimea aripilor, un mamifer prin greutate, înălțime și tip de mancare (carnivor, ierbivor, omnivor) iar un pește prin greutate, adâncimea maximă de înnot și salinitatea apei (în procentaj). Să se definnească structurile de date necesare cât mai abstract posibil și cu amprenta de memorie minima. Se va defini un tablou de astfel de structuri și se vor implementa funcții de adaugare animal, stergere animal și printare animale.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CHUNK 10

#pragma region DATA_STRUCTURES

typedef struct
{
    
    int nr_legs;
    int lifespan;

} INSECT_T;

typedef struct
{
    
    float flight_speed;
    float wing_span;

} BIRD_T;

typedef struct
{
    
    float weight;
    float height;
    enum {carnivore, herbivore, omnivore} food_type;

} MAMMAL_T;

typedef struct 
{

    float weight;
    float max_depth;
    float salinity;

} FISH_T;

typedef union
{
    INSECT_T insect;
    BIRD_T bird;
    MAMMAL_T mammal;
    FISH_T fish;

} ANIMAL_DETAILS_T;

typedef struct
{
    enum {INSECT = 1, BIRD, MAMMAL, FISH} type;
    ANIMAL_DETAILS_T animal;

} ANIMAL_T;


#pragma endregion

ANIMAL_T *add_to_database(ANIMAL_T *array, uint64_t *size)
{
    static uint64_t allocated_size = 0;

    ANIMAL_T input;

    printf("Enter animal type:\n");
    printf("1. Insect\n");
    printf("2. Bird\n");
    printf("3. Mammal\n");
    printf("4. Fish\n");

    if(scanf("%d", &input.type) != 1)
    {
        printf("Invalid input!\n");
        return array;
    }

    switch(input.type)
    {
        case INSECT:

            printf("Enter number of legs: ");
            if(scanf("%d", &input.animal.insect.nr_legs) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            printf("Enter lifespan: ");
            if(scanf("%d", &input.animal.insect.lifespan) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            break;

        case BIRD:

            printf("Enter flight speed: ");
            if(scanf("%f", &input.animal.bird.flight_speed) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            printf("Enter wing span: ");
            if(scanf("%f", &input.animal.bird.wing_span) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            break;

        case MAMMAL:

            printf("Enter weight: ");
            if(scanf("%f", &input.animal.mammal.weight) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            printf("Enter height: ");
            if(scanf("%f", &input.animal.mammal.height) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            printf("Enter food type: ");
            printf("1. Carnivore\n");
            printf("2. Herbivore\n");
            printf("3. Omnivore\n");

            if(scanf("%d", &input.animal.mammal.food_type) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            break;

        case FISH:

            printf("Enter weight: ");
            if(scanf("%f", &input.animal.fish.weight) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            printf("Enter max depth: ");
            if(scanf("%f", &input.animal.fish.max_depth) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            printf("Enter salinity: ");
            if(scanf("%f", &input.animal.fish.salinity) != 1)
            {
                printf("Invalid input!\n");
                return array;
            }

            break;

        default:
            printf("Invalid input!\n");
            return array;
    }

    if(*size == allocated_size)
    {
        allocated_size += CHUNK;
        array = realloc(array, allocated_size * sizeof(ANIMAL_T));
    }
    
    if(array != NULL)
    {
        array[*size] = input;
        (*size)++;
    }

    return array;
}


void print_array(ANIMAL_T *array, uint64_t size)
{
    for(uint64_t i = 0; i < size; i++)
    {
        switch (array[i].type)
        {
        case INSECT:

            printf("-------------------------------\n");
            printf("Insect\n");
            printf("Number of legs: %d\n", array[i].animal.insect.nr_legs);
            printf("Lifespan: %d\n", array[i].animal.insect.lifespan);
            printf("-------------------------------\n");
            break;
        
        case BIRD:
            
            printf("-------------------------------\n");
            printf("Bird\n");
            printf("Flight speed: %f\n", array[i].animal.bird.flight_speed);
            printf("Wing span: %f\n", array[i].animal.bird.wing_span);
            printf("-------------------------------\n");
            break;

        case MAMMAL:

            printf("-------------------------------\n");
            printf("Mammal\n");
            printf("Weight: %f\n", array[i].animal.mammal.weight);
            printf("Height: %f\n", array[i].animal.mammal.height);
            printf("Food type: ");

            switch (array[i].animal.mammal.food_type)
            {
            case carnivore:
                printf("Carnivore\n");
                break;
            
            case herbivore:
                printf("Herbivore\n");
                break;

            case omnivore:
                printf("Omnivore\n");
                break;

            default:
                break;
            }

            printf("-------------------------------\n");
            break;

        case FISH:

            printf("-------------------------------\n");
            printf("Fish\n");
            printf("Weight: %f\n", array[i].animal.fish.weight);
            printf("Max depth: %f\n", array[i].animal.fish.max_depth);
            printf("Salinity: %f\n", array[i].animal.fish.salinity);
            printf("-------------------------------\n");
            break;

        default:
            break;
        }
    }
}


void menu(ANIMAL_T *array, uint64_t size)
{
    uint8_t option = 0;

    while(option != 4)
    {
        printf("1. Add animal\n");
        printf("2. Print animals\n");
        printf("3. Delete animal\n");
        printf("4. Exit\n");

        if(scanf("%hhu", &option) != 1)
        {
            printf("Invalid input!\n");
            continue;
        }

        switch (option)
        {
        case 1:
            array = add_to_database(array, &size);
            break;
        
        case 2:
            print_array(array, size);
            break;

        case 3:
            break;

        case 4:
            break;

        default:
            printf("Invalid input!\n");
            break;
        }
    }
}


int main(void)
{
    ANIMAL_T *array = NULL;

    uint64_t size = 0;

    menu(array, size);

    free(array);

    return 0;
}
