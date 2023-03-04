#include <stdio.h>

void printArray(int a[], int n);
void rrot(int a[], int n, int p);
int swap(int a, int b);


int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6}, p = 5, n = 6;
    printArray(a, n);
    rrot(a, n, p);

}


int swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;

    return a, b;
}


void rrot(int a[], int n, int p)
{
    int tmp;
    for (int i = 0; i < p; i++)
    {
        tmp = a[0];
        for (int j = 1; j <= n; j++)
        {
            a[j - 1] = a[j];
        }
        a[n-1] = tmp;
        printArray(a, n);
    }

    printArray(a, n);
}


void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", a[i]);
    printf("\n");
}
