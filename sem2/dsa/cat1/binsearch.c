#include <stdio.h>

int binsearch(int[], int, int, int);

int main(void){
    int n, num;
    int A[] = {1,2,3,4,5}; n = 5;

    printf("Enter number to search for: ");
    scanf("%d", &num);

    printf("At index: %d", binsearch(A, 0, n, num));    
}

int binsearch(int A[], int low, int high, int key){
    if (low == high){
        if (A[low] == key)
            return low;
        return -1;
    }

    int mid = (low + high)/2;
    if (key == A[mid])
        return mid;
    if (key < A[mid])
        return binsearch(A, low, mid - 1, key);
    else
        return binsearch(A, mid + 1, high, key);
}
