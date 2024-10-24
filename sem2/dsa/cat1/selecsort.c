// Selection sort in C

#include <stdio.h>

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    for (j = i, k = i; j < n; j++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[j] < array[k])
        k = j;
    }

    // put min at the correct position
    swap(&array[k], &array[i]);
  }
}

// function to print an array
void printArray(int array[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// driver code
int main() {
  int data[] = {3,5,2,4,1}; int n = 5;
  
  selectionSort(data, n);
  
  printArray(data, n);
}
