#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int *x, int *y);
void printArray(int A[], int n);

int main(void)
{
    int a[] = {1,4,5,2,7,6,3,4,9};
    int length = 9;

    quicksort(a, 0, length-1);
    printArray(a, length);
}


void printArray(int A[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(a, low, high);
        quicksort(a, low, pivot_index - 1);
        quicksort(a, pivot_index + 1, high);
    }
}


int partition(int a[], int low, int high)
{
    int pivot_item = a[low];
    int left = low, right = high;

    while (left < right){
        while (a[left] <= pivot_item && left != high)
            left++;
        while (a[right] > pivot_item)
            right--;
        if (left < right)
            swap(&a[left], &a[right]);
    }

    a[low] = a[right];
    a[right] = pivot_item;

    return right;
}
