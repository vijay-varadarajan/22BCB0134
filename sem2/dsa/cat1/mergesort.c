#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int c[high + 1];
    int i = low, j = mid + 1, k = low;
    
    while (i <= mid && j <= high){
        if (a[i] < a[j])
            c[k] = a[i++]; 
        else
            c[k] = a[j++];
        k++;
    }

    for (; i <= mid;)
        c[k++] = a[i++]; 
    
    for (; j <= high;)
        c[k++] = a[j++]; 

    for (int l = low; l < high + 1; l++)
        a[l] = c[l];
}

void mergesort(int a[], int low, int high)
{
    if (low < high){
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main(void)
{
    int a[] = {3,2,8,6,1,9,3,4}, n = 8;
    
    mergesort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}