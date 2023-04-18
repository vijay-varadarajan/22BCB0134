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

int main(void)
{
    int nums[] = {1,1,4,2,1,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    mergesort(nums, 0, n - 1);
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
        int mid = (l + r)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
}

void merge(int nums[], int l, int mid, int r)
{
    int tmp[r + 1];
    int i, j, k;
    i = l; j = mid + 1; k = l;
    while (i <= mid && j <= r)
    {
        if (nums[i] < nums[j]){
            tmp[k] = nums[i];
            i++; k++;
        }
        else{
            tmp[k] = nums[j];
            j++; k++;
        }
    }

    for (; i <= mid; i++)
    {
        tmp[k] = nums[i];
        k++;
    }
    for (; j <= r; j++)
    {
        tmp[k] = nums[j];
        k++;
    }

    for(int i = l; i <= r; i++)
        nums[i] = tmp[i];
}