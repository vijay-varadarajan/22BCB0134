#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} Heap;

void init(Heap *h){
    h->size = 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert an element into the heap
void insert(Heap *h, int key){
    if(h->size == MAX){
        printf("Heap is full\n");
        return;
    }
    h->data[h->size] = key;
    int i = h->size;
    while(i > 0 && h->data[i] < h->data[(i-1)/2]){
        swap(&h->data[i], &h->data[(i-1)/2]);
        i = (i-1)/2;
    }
    h->size++;
}

// Delete the minimum element from the heap
int deleteMin(Heap *h){
    if(h->size == 0){
        printf("Heap is empty\n");
        return -1;
    }
    int min = h->data[0];
    h->data[0] = h->data[h->size-1];
    h->size--;
    int i = 0;
    while(2*i+1 < h->size){
        int j = 2*i+1;
        if(j+1 < h->size && h->data[j+1] < h->data[j]){
            j++;
        }
        if(h->data[i] < h->data[j]){
            break;
        }
        swap(&h->data[i], &h->data[j]);
        i = j;
    }
    return min;
}

// Print the heap
void print(Heap *h){
    for(int i = 0; i < h->size; i++){
        printf("%d ", h->data[i]);
    }
    printf("\n");
}   

int main(void){
    Heap h;
    init(&h);
    insert(&h, 5);
    insert(&h, 3);
    insert(&h, 7);
    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 6);
    insert(&h, 4);
    print(&h);
    printf("%d\n", deleteMin(&h));
    printf("%d\n", deleteMin(&h));
    printf("%d\n", deleteMin(&h));
    printf("%d\n", deleteMin(&h));

    return 0;

}