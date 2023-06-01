#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj_matrix[MAX][MAX];
int nodes, start;

void DFS(int vertex);

int main()
{
    int i,j;
    printf("Enter number of nodes: ");
    scanf("%d",&nodes);

    printf("Enter adjacency matrix : \n");

    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            scanf("%d",&adj_matrix[i][j]);
        }
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    for(i=0;i<nodes;i++){
        visited[i]=0;
    }

    printf("The Depth First Search Traversal of the Graph is: \n");

    // Starting DFS from the specified vertex
    DFS(start);

    return 0;
}

void DFS(int vertex)
{
    int i;

    printf("%d ",vertex);
    visited[vertex]=1;

    for(i=0;i<nodes;i++){
        if(adj_matrix[vertex][i] && !visited[i]){
            DFS(i);
        }
    }
}
