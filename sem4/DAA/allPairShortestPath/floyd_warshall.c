#include <stdio.h>
#include <stdlib.h> // Add the missing header file

#define V 100
#define INF 9999

void floydWarshall(int graph[V][V], int vertices) {
    int d[vertices][vertices];
    int i, j, k;

    // Initialize the d array
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] == 0 && i != j) {
                d[i][j] = INF;
            } else {
                d[i][j] = graph[i][j];
            }
        }
    }

    // Find shortest path for all pairs of vertices
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (d[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", d[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, vertices);

    return 0;
}