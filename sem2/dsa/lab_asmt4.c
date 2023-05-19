#include <stdio.h>
#include <stdlib.h>

int temp;

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* insertandupdate(struct Node* root, int value);

int main() {
    int N, num;

    printf("Enter number of integers: ");
    scanf("%d", &N);

    int list[N];

    // get input list
    for (int i = 0; i < N; i++) {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &list[i]);
    }

    printf("\nInput list: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", list[i]);
    }
    
    // initialise root node of tree to null
    struct Node* root = NULL;

    // loop through list to find the replacement value for every element
    for (int i = 0; i < N; i++) {

        // set replacement value 'temp' to 0
        temp = 0;

        // update value of temp while inserting new element
        root = insertandupdate(root, list[i]);

        // replace list value with temp value
        list[i] = temp;
    }
    
    printf("\n\nOutput list: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", list[i]);
    }
    
    free(root);
    
    return 0;
}

// updates the replacement value while inserting the new node, recursively
struct Node* insertandupdate(struct Node* root, int value) {
    if (root == NULL){
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }

    // insert normally if value is lesser than root
    if (value < root->value) {
        root->left = insertandupdate(root->left, value);
        // temp is not updated when insertion is to the left
    }

    // keep moving to right if value is greater than root
    else if (value > root->value) {
        // keep track of the parent node value in temp for each step to the right (as this is the greatest smaller number) until new node is inserted
        temp = root->value;
        root->right = insertandupdate(root->right, value);
    }

    return root;
}
