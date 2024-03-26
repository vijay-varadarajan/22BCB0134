#include <stdio.h>
#include <limits.h>

#define V 100
#define INF 99999

void bellmanFord(int graph[V][V], int vertices, int source) {
    int d[V];
    int pred[V];

    for (int i = 0; i < vertices; i++) {
        d[i] = INF;
        pred[i] = -1;
    }
    d[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            for (int v = 0; v < vertices; v++) {
                if (graph[u][v] != 0 && d[u] != INF && d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    pred[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < vertices; u++) {
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0 && d[u] != INF && d[u] + graph[u][v] < d[v]) {
                printf("Graph contains negative-w cycle\n");
                return;
            }
        }
    }

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\t\t", i, d[i]);
        int j = i;
        while (j != source) {
            printf("%d <- ", j);
            j = pred[j];
        }
        printf("%d\n", source);
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

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, vertices, source);

    return 0;
}