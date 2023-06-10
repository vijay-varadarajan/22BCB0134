#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 4

void iterativeDFS(int graph[MAX_NODES][MAX_NODES], int startNode) {
    bool visited[MAX_NODES] = { false };
    int stack[MAX_NODES];
    int top = -1;
    
    stack[++top] = startNode;
    visited[startNode] = true;
    
    while (top != -1) {
        int currentNode = stack[top--];
        printf("%d ", currentNode); // Process the current node
        
        for (int i = 0; i < MAX_NODES; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };
    
    int startNode = 0;
    
    printf("Iterative DFS traversal starting from node %d:\n", startNode);
    iterativeDFS(graph, startNode);
    
    return 0;
}
