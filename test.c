#include <stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(int A[], int n){
    for (int i = 1; i < n; i++){
        int key = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > key){
            A[(j--)+1] = A[j];
        }
        
        // improvisation
        while (j >= 0 && A[j] == key) {
            j--;
        }

        A[j+1] = key;
    }
}


void selectionSort(int A[], int n){
    for(int i = 0; i < n; i++){
        int k = i;
        for (int j = i; j < n; j++){
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}


void merge(int A[], int low, int mid, int high){
    int i = low, j = mid + 1, k = low; 
    int C[high - low +1];
    while (i <= mid && j <= high){
        if (A[i] < A[j])
            { C[k - low] = A[i]; i++; k++; }
        else
            { C[k - low] = A[j]; j++; k++; }
    }

    while (i <= mid)
        { C[k - low] = A[i]; i++; k++; }

    while (j <= high)
        { C[k - low] = A[j]; j++; k++; }

    for (int i = low; i <= high; i++){
        A[i] = C[i - low];
    }
}


void mergeSort(int A[], int low, int high){
    if (low < high){
        int mid = (low + high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int findmax(int A[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int A[], int n){
    int max = findmax(A, n);
    int count[max+1];
    
    for (int i = 0; i < n; i++)
        { count[i] = 0; }

    for(int i = 0; i < n; i++)
        { count[A[i]]++; }

    int i = 0, j = 0;
    while (j <= max){
        if (count[j] > 0){
            A[i++] = j;
            count[j]--;
        } else {
            j++;
        }
    }
}

int partition(int A[], int low, int high){
    int pivot_item = A[low];
    int left = low, right = high;

    while (left < right)
    {
        while (A[left] <= pivot_item && left != high){
            left++;
        }
        while (A[right] > pivot_item){
            right--;
        }
        if (left < right)
            swap(&A[left], &A[right]);
    }

    A[low] = A[right];
    A[right] = pivot_item;

    return right;
}

void quickSort(int A[], int low, int high){
    if (low < high){
        int part_ind = partition(A, low, high);
        quickSort(A, low, part_ind-1);
        quickSort(A, part_ind+1, high);
    }
}

int main(void){
    int A[] = {2,1,4,3,6,5,0,3,4,9,8,7}, n = 12;
    quickSort(A, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}