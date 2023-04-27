#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 15, b = 61;
    swap(&a, &b);
    printf("%d, %d", a, b);
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
