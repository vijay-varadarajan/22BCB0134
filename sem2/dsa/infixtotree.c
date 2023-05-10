#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a node structure for the binary expression tree
typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

// Define a stack structure for storing nodes during the tree construction process
typedef struct stack {
    int top;
    Node* items[100];
} Stack;

// Function to create a new node with the given data and NULL left and right pointers
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if the given character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Function to push a node onto the stack
void push(Stack* stack, Node* node) {
    stack->top++;
    stack->items[stack->top] = node;
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    Node* node = stack->items[stack->top];
    stack->top--;
    return node;
}

// Function to get the precedence of the given operator
int getPrecedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to construct a binary expression tree from the given infix expression
Node* constructExpressionTree(char* infix) {
    // Create an empty stack for storing operators and operands
    Stack stack;
    stack.top = -1;
    
    Node* root = NULL;
    
    // Iterate through the infix expression one character at a time
    for(int i = 0; infix[i] != '\0'; i++) {
        // If the current character is an operand, create a new node and push it onto the stack
        if(isOperand(infix[i])) {
            Node* newNode = createNode(infix[i]);
            push(&stack, newNode);
        }
        // If the current character is an operator, pop two nodes from the stack and create a new node with the operator as the data
        // Set the left and right children of the new node to the two popped nodes, then push the new node onto the stack
        else {
            Node* newNode = createNode(infix[i]);
            newNode->right = pop(&stack);
            newNode->left = pop(&stack);
            push(&stack, newNode);
        }
    }
    
    // The root of the expression tree will be the last node remaining on the stack
    root = pop(&stack);
    
    return root;
}

// Function to traverse the expression tree in inorder fashion and print the infix expression
void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%c", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Example infix expression: (a+b)*c
    char infix[100] = "a+b*c";
    
    Node* root = constructExpressionTree(infix);
    
    // Traverse the expression tree in inorder fashion and print the infix expression
    printf("Infix expression: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}