#include <stdio.h>

#define N 1000
#define oo 1000000000

int n;
int e;
int capc[N][N];
int flow[N][N];
int color[N];
int pred[N];

int min (int x, int y) {
    return x<y ? x : y;
}

int head,tail;
int q[N+2];

void enqueue (int x) {
    q[tail] = x;
    tail++;
    color[x] = 1;
}

int dequeue () {
    int x = q[head];
    head++;
    color[x] = 2;
    return x;
}

int bfs (int start, int target) {
    int u,v;
    for (u=0; u<n; u++) {
        color[u] = 0;
    }   
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head!=tail) {
        u = dequeue();
        for (v=0; v<n; v++) {
            if (color[v]==0 && capc[u][v]-flow[u][v]>0) {
                enqueue(v);
                pred[v] = u;
            }
        }
    }
    return color[target]==2;
}

int max_flow (int src, int sink) {
    int i,j,u;
    int max_flow = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            flow[i][j] = 0;
        }
    }

    while (bfs(src,sink)) {
        int inc = oo;
        for (u=n-1; pred[u]>=0; u=pred[u]) {
            inc = min(inc,capc[pred[u]][u]-flow[pred[u]][u]);
        }
        for (u=n-1; pred[u]>=0; u=pred[u]) {
            flow[pred[u]][u] += inc;
            flow[u][pred[u]] -= inc;
        }
        max_flow += inc;
    }
    return max_flow;
}

int main () {
    printf("Enter the number of nodes and edges:\n");
    scanf("%d %d",&n,&e);
    
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            capc[i][j] = 0;
        }
    }

    printf("Enter the edges and their capacities:\n");
    for (i=0; i<e; i++) {
        int u,v,cap;
        scanf("%d %d %d",&u,&v,&cap);
        capc[u][v] = cap;
    }

    printf("\nPlease enter src(s) and Sink(t) :\n");
    int s=0,t=n-1;
    scanf("%d %d",&s,&t);
    
    printf("\nMax Flow : %d\n",max_flow(s,t));
    return 0;
}