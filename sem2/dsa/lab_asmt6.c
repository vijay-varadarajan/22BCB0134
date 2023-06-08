#include<stdio.h>
#include<stdlib.h>

int sumodd = 0, sumeven = 0;

typedef struct btreeNode{
    struct btreeNode *lchild;
    int money;
    struct btreeNode *rchild;
    int height;
}btreeNode;


btreeNode* createbtree(int *rootarr, int start, int n, int ht);
void inorder(btreeNode* root);
void preorder(btreeNode* root);
void sumoddsevens(btreeNode* root);
int max(int a, int b);


int main(void){
    int n, arr[100];
    btreeNode* root;

    printf("Enter maximum number of nodes in binary tree (array size): ");
    scanf("%d", &n);

    printf("Enter elements heightwise (root to leaf) from left to right\n");
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1); scanf("%d", &arr[i]);
    }

    root = createbtree(arr, 0, n, 0);
    sumoddsevens(root);
    printf("Maximum amount of money that can be robbed: %d", max(sumodd, sumeven));
    return 0;
}


btreeNode* createbtree(int *rootarr, int start, int n, int ht){
    if (start >= n || rootarr[start] == 0){
        return NULL;
    }

    btreeNode *root = (btreeNode*)malloc(sizeof(btreeNode));
    root -> money = rootarr[start];
    root -> lchild = createbtree(rootarr, 2*start + 1, n, ht+1);
    root -> rchild = createbtree(rootarr, 2*start + 2, n, ht+1);
    root -> height = ht;

    return root;
}

// traversals - recursive
void sumoddsevens(btreeNode* root){
    if (root == NULL)
        return;
    
    sumoddsevens(root -> lchild);
    if (root -> height % 2 != 0)
        sumodd += root -> money;
    else
        sumeven += root -> money;
    sumoddsevens(root -> rchild);
}

int max(int a, int b){
    if (a < b)
        return b;
    else
        return a;
}
