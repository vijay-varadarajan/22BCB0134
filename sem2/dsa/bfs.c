#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int queue[1000];
    int front; 
    int rear;
} Queue;

void init_queue(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q){
    return q->front == q->rear;
}

int is_full(Queue *q){
    return q->rear == 1000 - 1;
}

void enqueue(Queue *q, int vertex){
    if (is_full(q)){
        printf("Queue is full\n");
        exit(1);
    }
    q->queue[q->rear++] = vertex;
}

int dequeue(Queue *q){
    if (is_empty(q)){
        printf("Queue is empty\n");
        exit(1);
    }
    return q->queue[q->front++];
}

void bfs(int **graph, int n, int start){
    int *visited = calloc(n, sizeof(int));
    Queue q;
    init_queue(&q);
    visited[start] = 1;
    enqueue(&q, start);

    while(!is_empty(&q)){
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        for (int i = 0; i < n; i++){
            if (graph[vertex][i] && !visited[i]){
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }

    free(visited);
}

int main(){
    int n, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **graph = calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++){
        graph[i] = calloc(n, sizeof(int));
    }

    printf("Enter %d vertices into the matrix: ", n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(graph, n, start);

    for (int i = 0; i < n; i++){
        free(graph[i]);
    }
    free(graph);

    return 0;
}