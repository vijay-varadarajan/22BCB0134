#include <stdio.h>

void inssort(int a[], int length);
void printArray(int A[], int n);

int main(void)
{
    int a[] = {4,1,5,2,7,6,3,4,9};
    int n = 9;
    inssort(a, n);
    printArray(a, n);
}

void printArray(int A[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void inssort(int a[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}
