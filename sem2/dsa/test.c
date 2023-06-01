#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

int G[MAX][MAX];

int main(void){
    int n=0;
    int x, y;
    int edges=0; 
    
    printf("Number of vertices in graph: ");
    scanf("%d", &n);
    
    bool visited[n];
    int mst[n];
    mst[0] = -1;

    memset(visited, false, sizeof(visited));
    visited[0] = true; 

    printf("Enter matrix: \n");
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &G[i][j]);
        }
    }

    while(edges < n-1){
        int min = 99999;
        x = 0; y = 0;
        for (int i = 0; i < n; i++){
            if (visited[i]) {
                for (int j = 0; j < n; j++){
                    if (!visited[j] && G[i][j] != 0){
                        if (min > G[i][j]){
                            min = G[i][j];
                            x = i; y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d: %d\n", x, y, G[x][y]);
        visited[y] = true;
        mst[y] = x;
        edges++;
    }

    for (int i = 0; i < n; i++){
        printf("%d ", mst[i]);
    }
}