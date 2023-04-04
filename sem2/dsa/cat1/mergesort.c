#include <stdio.h>
#include <stdlib.h>

/*
If only one number
    Quit
Else
    Sort left half of number
    Sort right half of number
    Merge sorted halves
*/

void mergesort(int nums[], int l, int r);
void printArray(int A[], int n);
void merge(int nums[], int l, int mid, int r);

void sort(int *nums, int numsSize)
{
    int l = 0;
    int r = numsSize - 1;
    mergesort(nums, l, r);
}

int main(void)
{
    int nums[] = {1,1,4,2,1,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    sort(nums, n);
    printArray(nums, n);
}

void printArray(int A[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void mergesort(int nums[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
}

void merge(int nums[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = nums[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = nums[mid + j + 1];

    int i = 0; int j = 0; int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        nums[k] = L[i];
        i++; k++;
    }
    while (j < n2)
    {
        nums[k] = R[j];
        j++; k++;
    }
}