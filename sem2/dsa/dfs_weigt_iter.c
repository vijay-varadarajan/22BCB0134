#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 4

void iterativeDFS(int graph[MAX_NODES][MAX_NODES], int startNode) {
    bool visited[MAX_NODES] = { false };
    int stack[MAX_NODES];
    int top = -1;

    int shortestPath[MAX_NODES];
    int minDist[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        shortestPath[i] = -1;
        minDist[i] = INT_MAX;
    }

    stack[++top] = startNode;
    visited[startNode] = true;
    minDist[startNode] = 0;

    while (top != -1) {
        int currentNode = stack[top--];
        printf("%d ", currentNode); // Process the current node

        for (int i = 0; i < MAX_NODES; i++) {
            if (graph[currentNode][i] > 0) {
                int weight = graph[currentNode][i];
                int newDist = minDist[currentNode] + weight;
                if (newDist < minDist[i]) {
                    minDist[i] = newDist;
                    shortestPath[i] = currentNode;
                }
                if (!visited[i]) {
                    stack[++top] = i;
                    visited[i] = true;
                }
            }
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 2, 3, 0},
        {0, 0, 0, 2},
        {4, 0, 0, 0},
        {0, 1, 0, 0}
    };

    int startNode = 0;

    printf("Iterative DFS traversal with shortest path selection starting from node %d:\n", startNode);
    iterativeDFS(graph, startNode);

    return 0;
}
