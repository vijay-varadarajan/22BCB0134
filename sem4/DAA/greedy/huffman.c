#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct minHeapNode {
    char letter;
    int freq;
    struct minHeapNode* left;
    struct minHeapNode* right;
} minHeapNode;

typedef struct minHeap {
    int size;
    int capacity;
    minHeapNode **arr;
} minHeap;

minHeapNode *buildHuffTree(char letters[], int freqs[], int size);
minHeap* createAndBuildMinHeap(char letters[], int freqs[], int size);
minHeap* createMinHeap(int capacity);
minHeapNode* createNewNode(char letter, int freq);
void heapify(minHeap* minheap, int idx);
void buildMinHeap(minHeap* minheap, int size);
void insertNode(minHeap* minheap, minHeapNode* minheapnode);
minHeapNode* extractMin(minHeap* minheap);
bool isSingleNode(minHeap* minheap);
void swap(minHeapNode** a, minHeapNode** b);


void printHuffCodes(minHeapNode* root, int arr[], int top){
    if(root -> left){
        arr[top] = 0;
        printHuffCodes(root -> left, arr, top + 1);
    }

    if(root -> right){
        arr[top] = 1;
        printHuffCodes(root -> right, arr, top + 1);
    }

    if (root -> left == NULL && root -> right == NULL){
        printf("%c: ", root -> letter);
        for(int i = 0; i < top; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}


int main(void){
    int n;
    printf("Enter the number of letters: ");
    scanf("%d", &n);
    getchar(); // consume the newline character

    char letters[n]; 
    for(int i = 0; i < n; i++){
        printf("Enter the letters: ");
        scanf(" %c", &letters[i]); // note the space before %c
    }

    printf("\n");
    int freqs[n];
    for(int i = 0; i < n; i++){
        printf("Enter the frequencies: ");
        scanf("%d", &freqs[i]);
        getchar(); // consume the newline character
    }
    
    int size = sizeof(letters)/sizeof(letters[0]);

    minHeapNode *root = buildHuffTree(letters, freqs, size);

    int arr[size], top = 0;
    printHuffCodes(root, arr, top);
}


minHeapNode *buildHuffTree(char letters[], int freqs[], int size){

    minHeapNode *left, *right, *top;
    minHeap *minheap = createAndBuildMinHeap(letters, freqs, size);

    while (!isSingleNode(minheap)){
        left = extractMin(minheap);
        right = extractMin(minheap);

        top = createNewNode('@', left -> freq + right -> freq);
        top -> left = left;
        top -> right = right;

        insertNode(minheap, top);
    }

    return extractMin(minheap);
}


void insertNode(minHeap* minheap, minHeapNode* minheapnode){
    if (minheap -> size == minheap -> capacity){
        exit(1);
    }

    minheap -> size += 1;
    int i = minheap -> size - 1;

    while(i != 0 && minheapnode -> freq < minheap -> arr[(i-1)/2] -> freq){
        minheap -> arr[i] = minheap -> arr[(i-1)/2];
        i = (i-1)/2;
    }

    minheap -> arr[i] = minheapnode;
}


minHeapNode* extractMin(minHeap* minheap){
    minHeapNode* temp = (minHeapNode*)malloc(sizeof(minHeapNode));
    if (temp == NULL){
        exit(1);
    }

    temp = minheap -> arr[0];
    minheap -> arr[0] = minheap -> arr[minheap -> size - 1];
    minheap -> size -= 1;

    heapify(minheap, 0);

    return temp;
}


bool isSingleNode(minHeap* minheap){
    return (minheap -> size == 1);
}

minHeap* createAndBuildMinHeap(char letters[], int freqs[], int size){
    minHeap* minheap = createMinHeap(size);

    for(int i = 0; i < size; i++){
        minheap -> arr[i] = createNewNode(letters[i], freqs[i]);
    }

    minheap -> size = size;
    buildMinHeap(minheap, size);

    return minheap;
}

void buildMinHeap(minHeap* minheap, int size){
    int n = size - 1;
    for (int i = (n-1)/2; i >= 0; i--){
        heapify(minheap, i);
    }
}

void heapify(minHeap* minheap, int idx){
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < minheap -> size && minheap -> arr[left] -> freq < minheap -> arr[smallest] -> freq){
        smallest = left;
    }
    if (right < minheap -> size && minheap -> arr[right] -> freq < minheap -> arr[smallest] -> freq){
        smallest = right;
    }

    if (smallest != idx){
        swap(&minheap -> arr[smallest], &minheap -> arr[idx]);
        heapify(minheap, smallest);
    }
}

void swap(minHeapNode** a, minHeapNode** b){
    minHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

minHeapNode* createNewNode(char letter, int freq){
    minHeapNode *newNode = (minHeapNode*)malloc(sizeof(minHeapNode));
    if(newNode == NULL){
        exit(1);
    }

    newNode -> letter = letter;
    newNode -> freq = freq;
    newNode -> left = newNode -> right = NULL;

    return newNode;
}


minHeap* createMinHeap(int capacity){
    minHeap *minheap = (minHeap*)malloc(sizeof(minHeap));

    minheap -> size = 0;
    minheap -> capacity = capacity;
    minheap -> arr = (minHeapNode**)malloc(capacity * sizeof(minHeapNode));

    return minheap;
}

