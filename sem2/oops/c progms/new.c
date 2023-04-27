#include <stdio.h>
#define N 5

int main(void)
{
    char char_array[5];
    
    printf("Enter 5 characters: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &char_array[i]);
    }

    for(int i = 0; i < N; i++)
    {
        printf("%c ", char_array[i]);
    }
    printf("\n");
}
