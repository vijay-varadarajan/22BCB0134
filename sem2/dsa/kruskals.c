#include <stdio.h>
#include <stdlib.h>

// Number of vertices in the graph
#define V 6

// Number of edges in the graph
#define E 9

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to compare two edges based on their weights (used for sorting)
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Find the parent of a vertex in the disjoint set
int findParent(int parent[], int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

// Merge two disjoint sets
void mergeSets(int parent[], int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[xParent] = yParent;
}

// Function to perform Kruskal's algorithm to find the minimum spanning tree
void kruskalMST(int graph[][V]) {
    struct Edge result[V - 1]; // Stores the edges of the minimum spanning tree
    int parent[V]; // Stores the parent of each vertex in the disjoint set

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    int edgeCount = 0; // Counter for the edges included in the result

    // Step 1: Sort all the edges in non-decreasing order of weights
    struct Edge edges[E] = {
        {0, 1, 4}, {0, 2, 2}, {1, 2, 3}, {1, 3, 1},
        {1, 4, 6}, {2, 3, 5}, {2, 4, 7}, {3, 4, 8},
        {4, 5, 9}
    };

    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Step 2: Iterate through each edge in the sorted order
    for (int i = 0; i < E; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        // Step 3: Check if adding the edge creates a cycle
        if (findParent(parent, src) != findParent(parent, dest)) {
            // Add the edge to the result list
            result[edgeCount++] = edges[i];

            // Step 4: Merge the disjoint sets of the endpoints
            mergeSets(parent, src, dest);
        }
    }

    // Step 5: Print the edges of the minimum spanning tree
    printf("Edges of the minimum spanning tree:\n");
    for (int i = 0; i < V - 1; i++)
        printf("%d -- %d\tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    // Sample graph representation using a 2D array
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 3, 1, 6, 0},
        {2, 3, 0, 5, 7, 0},
        {0, 1, 5, 0, 8, 0},
        {0, 6, 7, 8, 0, 9},
        {0, 0, 0, 0, 9, 0}
    };

    kruskalMST(graph);

    return 0;
}
