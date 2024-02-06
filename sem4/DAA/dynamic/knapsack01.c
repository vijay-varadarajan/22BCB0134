#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(void) {
    int W = 18;
    int v[] = {12,10,8,11,14,7,9};
    int w[] = {4, 6, 5, 7, 3, 1, 6};
    int n = sizeof(v)/sizeof(v[0]);

    int arr[n+1][W+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < W+1; j++){
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++){
        for(int j = 1; j < W + 1; j++){
            if (j > w[i-1])
                arr[i][j] = max(arr[i-1][j], v[i-1] + arr[i-1][j-w[i-1]]);
            else
                arr[i][j] = arr[i-1][j];
        }
    }

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < W+1; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Max weight: %d", arr[n][W]);

    return 0;
}