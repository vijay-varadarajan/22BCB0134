#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode{
    struct BSTNode* lchild;
    int value;
    struct BSTNode* rchild;
} BSTNode;


BSTNode* create(BSTNode* root, int value);
BSTNode* createfromarray(int values[], int start, int n);
BSTNode* createfromsortedarray(int values[], int start, int n);
BSTNode* createfromrandomarray(int values[], int start, int n);
BSTNode* insert(BSTNode* root, int value);
BSTNode* deleteroot(BSTNode* root);
BSTNode* deletemid(BSTNode* root, int value);
BSTNode* search(BSTNode* root, int value);
void preorder(BSTNode* root);
void inorder(BSTNode* root);
void postorder(BSTNode* root);
void levelOrder(BSTNode* root);


int main(void)
{
    BSTNode* root = NULL;
    int array[] = {5,2,3,6,3,4,1,8,7,9};
    
    root = createfromrandomarray(array, 0, 10);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    levelOrder(root);
}

int front = -1, rear = -1;

void push(BSTNode* queue[], BSTNode* root){
    if (rear > 9){
        printf("Queue overflow");
        return;
    }
    if (front == -1)
        front++;
    queue[++rear] = root;
}

BSTNode* front_node(BSTNode* queue[]){
    return queue[front];
}

void pop(BSTNode* queue[]){
    front++;
}

bool isempty(BSTNode* queue[]){
    if (rear == -1 || (front > rear))
        return true;
    return false;
}

void levelOrder(BSTNode* root){
    BSTNode* queue[10]; BSTNode* temp;
    push(queue, root);
    while(!isempty(queue)){
        temp = front_node(queue);
        pop(queue);
        printf("%d ", temp->value);
        if (temp -> lchild != NULL){
            push(queue, temp->lchild);
        } 
        if (temp -> rchild != NULL){
            push(queue, temp->rchild);
        }
    }
}


BSTNode* create(BSTNode* root, int value){
    root = (BSTNode*) malloc(sizeof(BSTNode));
    root -> value = value;
    root -> lchild = NULL;
    root -> rchild = NULL;

    return root;
}


// Creating a binary search tree from given sorted array
BSTNode* createfromsortedarray(int* values, int start, int n){
    if (start > n)
        return NULL;

    int mid = (start + n)/2;
    BSTNode* root = (BSTNode*) malloc(sizeof(BSTNode));
    root -> value = values[mid];
    root -> lchild = createfromsortedarray(values, start, mid - 1);
    root -> rchild = createfromsortedarray(values, mid + 1, n);

    return root;
}


//Creating a binary search tree from a random array
BSTNode* createfromrandomarray(int* values, int start, int n){
    BSTNode* root = NULL;
    for (int i = start; i < n; i++){
        root = insert(root, values[i]);
    }

    return root;
}


// Creating a normal binary tree from given array
BSTNode* createfromarray(int* values, int start, int n){
    if (start >= n)
        return NULL;

    BSTNode* root = (BSTNode*) malloc(sizeof(BSTNode));
    root -> value = values[start];
    
    root -> lchild = createfromarray(values, 2*start + 1, n);
    root -> rchild = createfromarray(values, 2*start + 2, n);
    
    return root;
}


// Inserting into a binary search tree
BSTNode* insert(BSTNode* root, int value){
    if (root == NULL) {
        BSTNode* root = (BSTNode*) malloc(sizeof(BSTNode));
        root -> value = value;
        root -> lchild = NULL;
        root -> rchild = NULL;
        return root;
    }

    if (value <= root->value) {
        root -> lchild = insert(root -> lchild, value);
    } else if (value > root->value) {
        root -> rchild = insert(root -> rchild, value);
    }

    return root;
}


// traversals - recursive
void inorder(BSTNode* root){
    if (root == NULL)
        return;
    
    inorder(root->lchild);
    printf("%d ", root->value);
    inorder(root->rchild);
}


void preorder(BSTNode* root){
    if (root != NULL){
        printf("%d ", root->value);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}


void postorder(BSTNode* root){
    if (root != NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->value);
    }
}


// searching a BST for an element
BSTNode* search(BSTNode* root, int value)
{
    if (root == NULL){
        printf("Element not present in tree");
        return root;
    }
    
    if (root->value == value)
        return root;
    else if (value < root->value)
        return search(root -> lchild, value);
    else
        return search(root -> rchild, value);
}


BSTNode* deleteroot(BSTNode *root){
    if (root -> lchild == NULL && root -> rchild == NULL){
        free(root);
        root = NULL;
    }

    else if (root -> lchild == NULL){
        BSTNode* temp = root;
        root = root -> rchild;
        free(temp);
    }
    else if (root -> rchild == NULL){
        BSTNode* temp = root;
        root = root -> lchild;
        free(temp);
    }

    else {
        BSTNode* nextroot = root -> lchild;
        while (nextroot -> rchild != NULL){
            nextroot = nextroot -> rchild;
        }
        root -> value = nextroot -> value;
        root -> rchild = deletemid(root -> lchild, nextroot -> value);
    }

    return root;
}


BSTNode* deletemid(BSTNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        root->lchild = deletemid(root->lchild, value);
    } else if (value > root->value) {
        root->rchild = deletemid(root->rchild, value);
    } else {
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if (root->lchild == NULL) {
            BSTNode* temp = root;
            root = root->rchild;
            free(temp);
            return root;
        } else if (root->rchild == NULL) {
            BSTNode* temp = root;
            root = root->lchild;
            free(temp);
            return root;
        } else {
            BSTNode* successor = root->lchild;
            while (successor->rchild != NULL) {
                successor = successor->rchild;
            }
            root->value = successor->value;
            root->lchild = deletemid(root->rchild, successor->value);
        }
    }
    return root;
}