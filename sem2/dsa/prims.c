#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int G[5][5] = {
    {0, 2, 0, 4, 0},
    {2, 0, 5, 3, 8},
    {0, 5, 0, 0, 0},
    {0, 3, 0, 0, 5},
    {0, 0, 0, 5, 0}
};
int parent[100];
int key[100];
bool mstset[100];

int main(void){
    int v = 5;
    int x, y, no_edge = 0; bool visited[v];
    memset(visited, false, sizeof(visited));
    visited[0] = true;

    while (no_edge < v-1){
        int min = 999999;
        x = 0; y = 0;
        for (int i = 0; i < v; i++){
            if (visited[i]){
                for (int j = 0; j < v; j++){
                    if (!visited[j] && G[i][j]){
                        if (min > G[i][j]){
                            min = G[i][j];
                            x= i; y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d: %d\n", x, y, G[x][y]);
        visited[y] = true;
        no_edge++;
    }

}