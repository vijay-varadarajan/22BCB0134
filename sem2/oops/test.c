#include <stdio.h>
#define N 5

int main(void)
{
    // Create empty arrays
    int int_array[5];
    float float_array[5];
    double double_array[5];
    char char_array[5];

    // Get input values
    printf("Enter 5 integer values: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &int_array[i]);
    }

    printf("Enter 5 float values: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &float_array[i]);
    }

    printf("Enter 5 double values: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &double_array[i]);
    }

    printf("Enter 5 characters: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &char_array[i]);
    }

    // Print given values
    for(int i = 0; i < N; i++)
    {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%.2f ", float_array[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%lf ", double_array[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%c ", char_array[i]);
    }
    printf("\n");
}