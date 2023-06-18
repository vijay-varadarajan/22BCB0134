#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
};

struct stack{
    int top;
    struct node* arr[100];
};

struct node* create_node(char val){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct stack* create_stack(){
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    new->top = -1;
    return new;
}

void push(struct stack* stk, struct node* t){
    stk->top++;
    stk->arr[stk->top] = t;
}

struct node* pop(struct stack* stk){
    struct node* temp = stk->arr[stk->top];
    stk->top--;
    return temp;
}

struct node* create_expression_tree(char exp[]){
    struct stack *stk = create_stack();
    int len = strlen(exp);
    for(int i=0; i<len; i++){
        if(isalnum(exp[i])){
            struct node* new = create_node(exp[i]);
            push(stk, new);
        }
        else{
            struct node* t1 = pop(stk);
            struct node* t2 = pop(stk);
            struct node* new = create_node(exp[i]);
            new->left = t2;
            new->right = t1;
            push(stk, new);
        }
    }
    return pop(stk);
}

void inorder_traversal(struct node* root){
    if(root!=NULL){
        inorder_traversal(root->left);
        printf("%c ", root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    struct node* root = create_expression_tree(exp);
    printf("Inorder traversal of expression tree: ");
    inorder_traversal(root);
    return 0;
}
