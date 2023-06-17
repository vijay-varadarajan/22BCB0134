#include <stdio.h>
#include <stdlib.h>

typedef struct BSTreeNode{
    struct BSTreeNode* lchild;
    int value;
    struct BSTreeNode* rchild;
} BSTreeNode;


BSTreeNode* create(BSTreeNode* root, int value);
BSTreeNode* createfromarray(int values[], int start, int n);
BSTreeNode* createfromsortedarray(int values[], int start, int n);
BSTreeNode* createfromrandomarray(int values[], int start, int n);
BSTreeNode* insert(BSTreeNode* root, int value);
BSTreeNode* deleteroot(BSTreeNode* root);
BSTreeNode* deletemid(BSTreeNode* root, int value);
BSTreeNode* search(BSTreeNode* root, int value);
void preorder(BSTreeNode* root);
void inorder(BSTreeNode* root);
void postorder(BSTreeNode* root);
void levelOrder(BSTreeNode* root);


int main(void)
{
    BSTreeNode* root = NULL;
    int array[] = {5,2,3,6,3,4,1,8,7,9};
    
    root = createfromrandomarray(array, 0, 10);
    inorder(root);
    printf("\n");
    preorder(root);

    printf("\n%d \n", search(root, 4) -> value);

    root = deletemid(root, 6);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    levelOrder(root);
}

int front = -1, rear = -1;

void push(BSTreeNode* queue[], BSTreeNode* root){
    if (rear > 9){
        printf("Queue overflow");
        return;
    }
    if (front == -1)
        front++;
    queue[++rear] = root;
}

BSTreeNode* front_node(BSTreeNode* queue[]){
    return queue[front];
}

void pop(BSTreeNode* queue[]){
    front++;
}

void levelOrder(BSTreeNode* root){
    BSTreeNode* queue[10]; BSTreeNode* temp;
    push(queue, root);
    while(front != rear){
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


BSTreeNode* create(BSTreeNode* root, int value){
    root = (BSTreeNode*) malloc(sizeof(BSTreeNode));
    root -> value = value;
    root -> lchild = NULL;
    root -> rchild = NULL;

    return root;
}


// Creating a binary search tree from given sorted array
BSTreeNode* createfromsortedarray(int* values, int start, int n){
    if (start > n)
        return NULL;

    int mid = (start + n)/2;
    BSTreeNode* root = (BSTreeNode*) malloc(sizeof(BSTreeNode));
    root -> value = values[mid];
    root -> lchild = createfromsortedarray(values, start, mid - 1);
    root -> rchild = createfromsortedarray(values, mid + 1, n);

    return root;
}


//Creating a binary search tree from a random array
BSTreeNode* createfromrandomarray(int* values, int start, int n){
    BSTreeNode* root = NULL;
    for (int i = start; i < n; i++){
        root = insert(root, values[i]);
    }

    return root;
}


// Creating a normal binary tree from given array
BSTreeNode* createfromarray(int* values, int start, int n){
    if (start >= n)
        return NULL;

    BSTreeNode* root = (BSTreeNode*) malloc(sizeof(BSTreeNode));
    root -> value = values[start];
    
    root -> lchild = createfromarray(values, 2*start + 1, n);
    root -> rchild = createfromarray(values, 2*start + 2, n);
    
    return root;
}


// Inserting into a binary search tree
BSTreeNode* insert(BSTreeNode* root, int value){
    if (root == NULL) {
        BSTreeNode* root = (BSTreeNode*) malloc(sizeof(BSTreeNode));
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
void inorder(BSTreeNode* root){
    if (root == NULL)
        return;
    
    inorder(root->lchild);
    printf("%d ", root->value);
    inorder(root->rchild);
}


void preorder(BSTreeNode* root){
    if (root != NULL){
        printf("%d ", root->value);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}


void postorder(BSTreeNode* root){
    if (root != NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->value);
    }
}


// searching a BST for an element
BSTreeNode* search(BSTreeNode* root, int value)
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


BSTreeNode* deleteroot(BSTreeNode *root){
    if (root -> lchild == NULL && root -> rchild == NULL){
        free(root);
        root = NULL;
    }

    else if (root -> lchild == NULL){
        BSTreeNode* temp = root;
        root = root -> rchild;
        free(temp);
    }
    else if (root -> rchild == NULL){
        BSTreeNode* temp = root;
        root = root -> lchild;
        free(temp);
    }

    else {
        BSTreeNode* nextroot = root -> lchild;
        while (nextroot -> rchild != NULL){
            nextroot = nextroot -> rchild;
        }
        root -> value = nextroot -> value;
        root -> rchild = deletemid(root -> lchild, nextroot -> value);
    }

    return root;
}


BSTreeNode* deletemid(BSTreeNode* root, int value) {
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
            BSTreeNode* temp = root;
            root = root->rchild;
            free(temp);
            return root;
        } else if (root->rchild == NULL) {
            BSTreeNode* temp = root;
            root = root->lchild;
            free(temp);
            return root;
        } else {
            BSTreeNode* successor = root->lchild;
            while (successor->rchild != NULL) {
                successor = successor->rchild;
            }
            root->value = successor->value;
            root->lchild = deletemid(root->rchild, successor->value);
        }
    }
    return root;
}