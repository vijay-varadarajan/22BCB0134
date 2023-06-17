#include <stdio.h>
#define max 20

void reorder(int A[], int n){
    int temp = A[n];
    int i = n;
    while(i > 0 && temp < A[(i-1)/2]){
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }
    A[i] = temp;
}

void swap(int A[], int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void max_heapify(int A[], int n, int i){
    int largest = i, l = 2*i + 1, r = 2*i + 2;

    if (l <= n && A[l] > A[largest])
        largest = l;
    else if (r <= n && A[r] > A[largest])
        largest = r;
    if (largest != i){
        swap(A, i, largest);
        max_heapify(A, n, largest);
    }
}

void min_heapify(int A[], int n, int i){
    int smallest = i, l = 2*i + 1, r = 2*i + 2;

    if (l <= n && A[l] < A[smallest])
        smallest = l;
    else if (r <= n && A[r] < A[smallest])
        smallest = r;
    if (smallest != i){
        swap(A, i, smallest);
        min_heapify(A, n, smallest);
    }
}

void delete(int A[], int n){
    A[0] = A[n];
    n-- ; int i = 0; int larger_index = 0;

    while(i<n){
        int left = A[2*i + 1];
        int right = A[2*i + 2];
        int larger = left > right ? left : right;
        if (larger == left){
            larger_index = 2*i + 1;
        } else {
            larger_index = 2*i + 2;
        }

        if (A[i] < larger){
            swap(A, i, larger_index);
            i = larger_index;
        } else {
            return;
        }
    }
}

void delete_recur(int A[], int n){
    int last = A[n-1]; A[0] = last; n--;
    min_heapify(A, n, 0);
}

void buildheap(int A[], int n){
    for (int i = (n/2)-1; i > 0; i--){
        max_heapify(A, n, i);
    }
}

int main(void){
    int A[max], n, elem;
    printf("Enter the number of elements: "); scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    buildheap(A, n);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Element to be inserted: "); scanf("%d", &elem);
    A[n] = elem;

    reorder(A, n);

    for (int i = 0; i < n+1; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    delete_recur(A, n+1);

    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}
