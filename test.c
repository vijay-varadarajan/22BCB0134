#include <stdio.h>

int main(void){
    int n;              		// number of nodes in binary tree
    int array[100];     	// input array form of binary tree
    int heights[100];   	// stores heights of each node in the tree

    // if two nodes of a tree are directly linked then they must be present in consecutive heights (one odd and one even).
    // So, the nodes present in even heights are not directly linked so are the nodes present in odd heights
    // keeping track of the sum of money in nodes of even heights and odd heights separately
    
    int sumodds = 0, sumevens = 0;  

    printf("Enter maximum number of nodes in binary tree (array size): ");
    scanf("%d", &n);

    // get user input array
    printf("Enter elements heightwise (root to leaf) from left to right\n");
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1); scanf("%d", &array[i]);
    }


    // generate an array containing the heights of each node of the tree (i.e [0,1,1,2,2,2,2,...])
    
    heights[0] = 0;
    for(int i = 1; i < n; i++){
        if (i % 2 == 0)
            heights[i] = heights[(i/2) - 1] + 1;
        else
            heights[i] = heights[(i/2)] + 1;
    }

    // calculate the sum of nodes in even heights and odd heights, store them separately    
    for (int i = 0; i < n; i++){
        if (heights[i] % 2 == 0)
            sumevens += array[i];
        else
            sumodds += array[i];
    }

    // output the maximum of the calculated sum values
    printf("Maximum amount of money the thief can rob: %d", sumodds > sumevens ? sumodds : sumevens);
}
