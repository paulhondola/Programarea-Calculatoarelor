#include <stdio.h>
#define SIZE 100000

void read_array(int *array, int *size)
{
    int new_size = 0;
    int *ptr = array;

    for(int i = 0; i < *size; i++)
    {
        if(scanf("%d", ptr++) != 1)
            break;
        else
            new_size++;
    }
    *size = new_size;
}

void print_array(int *array, int size)
{
    int *ptr = array;
    for(int i = 0; i < size; i++)
        printf("%d ", *ptr++);
    printf("\n");
}

void max_vector(int *array, int size, int *max)
{
    *max = *array;
    int *ptr = array;
    for(int i = 0; i < size; i++, ptr++)
        if(*max < *ptr)
            *max = *ptr;
}

void remove_at(int *array, int *size, int position)
{
    for(int i = position; i < *size - 1; i++)
        *(array + i) = *(array + i + 1);

    (*size)--;
}

void elim_pare(int *array, int *size)
{
    for(int i = 0; i < *size; i++)
        if(*(array + i) % 2 == 0)
            remove_at(array, size, i), i--;
}

int check_prime(int num)
{
    if(num == 0 || num == 1)
        return 0;
    
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0)
            return 0;

    return 1;
}

void insert_prime_array(int *array, int *size)
{
    int max_size = *size * 2;

    for(int i = max_size - 2, j = *size - 1; i >= 0; i -= 2, j--)
    {
        *(array + i) = *(array + j);
        *(array + i + 1) = check_prime(*(array + j));
    }

    *size = max_size;
}

void free_at(int *array, int *size, int position)
{
    for(int i = *size - 1; i >= position; i--)
        *(array + i + 1) = *(array + i);

    (*size)++;
}

void insert_prime_array_2(int *array, int *size)
{
    for(int i = 0; i < *size; i += 2)
    {
        free_at(array, size, i);
        *(array + i + 1) = check_prime(*(array + i));
    }
}

int main(void)
{
    static int array[SIZE];

    int n = 0;
    scanf("%d", &n);
    read_array(array, &n);

    printf("%d\n", n);
    print_array(array, n);

    int max = 0;
    max_vector(array, n, &max);
    printf("Maximul din vector este: %d\n", max);

    elim_pare(array, &n);
    print_array(array, n);

    printf("Vectorul cu elementele prime inserate este:\n");
    insert_prime_array(array, &n);
    print_array(array, n);

    printf("Vectorul cu elementele prime inserate (metoda 2) este:\n");
    insert_prime_array_2(array, &n);
    print_array(array, n);

    return 0;
}