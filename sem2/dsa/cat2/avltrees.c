#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b){
    return a > b ? a : b;
}

int height(Node* node){
    if (node == NULL)
        return 0;
    
    int left = height(node -> left);
    int right = height(node -> right);

    return 1 + max(left, right);
}

int compute_balance(Node* node){
    return height(node -> left) - height(node -> right);
}

Node* rightRotate(Node* a){
    Node *b = a -> left;
    Node *b_orig_right = b -> right;

    b -> right = a;
    a -> left = b_orig_right;

    a -> height = 1 + max(height(a -> left), height(a -> right));
    b -> height = 1 + max(height(b -> left), height(b -> right));

    return b;
}

Node* leftRotate(Node* a){
    Node* b = a -> right;
    Node* b_orig_left = b -> left;

    b -> left = a;
    a -> right = b_orig_left;

    a -> height = 1 + max(height(a -> left), height(a -> right));
    b -> height = 1 + max(height(b -> left), height(b -> right));

    return b;
}

Node* balance(Node* node, int key){
    int balance = compute_balance(node);

    if (balance > 1){
        if (node -> left -> key > key){
            // LL rotation
            return rightRotate(node);
        } else {
            // LR rotation
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        }

    } else if (balance < -1) {
        if (node -> right -> key < key){
            // RR rotation
            return leftRotate(node);
        } else {
            // RL rotation
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        }
    }
    return node;
}

Node* insert(Node* node, int key){
    if (node == NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode -> left = NULL;
        newNode -> right = NULL;
        newNode -> height = 1;
        newNode -> key = key;
        printf("New node added successfully\n");
        return newNode;
    }
    if (node -> key > key){
        node -> left = insert(node -> left, key);
    } else if (node -> key < key) {
        node -> right = insert(node -> right, key);
    } else {
        printf("Already exists\n");
        return node;
    }

    node -> height = 1 + max(height(node -> left), height(node -> right));

    return balance(node, key);
}

Node* findMin(Node* node){
    if (node -> left == NULL && node -> right == NULL){
        return node;
    } else {
        return findMin(node -> left);
    }
}

Node* delete(Node* node, int key){
    if (node == NULL){
        printf("Element not found\n");
        return node;
    } 

    else if (key < node -> key){
        node -> left = delete(node -> left, key);
    } 
    
    else if (key > node -> key){
        node -> right = delete(node -> right, key);
    }
    
    else {
        printf("\nDeleted successfully\n");

        if (node -> left == NULL){
            Node *temp = node -> right;
            free(node);
            return temp;

        } else if (node -> right == NULL) {
            Node* temp = node -> left;
            free(node);
            return temp;

        } else {
            Node* temp = findMin(node -> right);
            node -> key = temp -> key;
            node -> right = delete(node -> right, temp -> key);
        }
    }

    node = balance(node, key);
}

void inorder(Node* node){
    if (node != NULL){
        inorder(node -> left);
        printf("%d ", node -> key);
        inorder(node -> right);
    }
}

int main(void){
    Node* root = NULL;

    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 10);

    inorder(root);

    root = delete(root, 8);

    inorder(root);

    return 0;
}
