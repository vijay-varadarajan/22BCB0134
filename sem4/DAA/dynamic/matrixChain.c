#include <stdio.h>

typedef struct Matrix {
    int r;
    int s;
} Matrix;

int n = 5;
Matrix mats[5];
int minvalarray[5][5];
int karray[5][5];

int m(int i, int j);

int main(void){
    for(int i = 0; i < n; i++){
        printf("Enter the dimensions of matrix %d: ", i+1);
        scanf("%d %d", &mats[i].r, &mats[i].s);
    }

    for(int i = 0; i < n; i++){
        printf("%d %d", mats[i].r, mats[i].s);
        printf("\n");
    }

    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            if(i-1 == j-1){
                minvalarray[i-1][j-1] = 0;
                karray[i-1][j-1] = 0;
            } else {
                minvalarray[i-1][j-1] = -1;
                karray[i-1][j-1] = -1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            printf("%d ", minvalarray[i-1][j-1]);
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            printf("%d ", karray[i-1][j-1]);
        }
        printf("\n");
    }

    int arr_min = 0;
    for (int i = 1; i <= n; i++){
        for (int j = n; j > 0; j--){
            if (i-1 <= j-1){
                arr_min = m(i, j);
                printf("arr_min: %d\n", arr_min);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            printf("%d ", minvalarray[i-1][j-1]);
        }
        printf("\n");
    }
    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            printf("%d ", karray[i-1][j-1]);
        }
        printf("\n");
    }

    printf("Minimum number of multiplications: %d\n", minvalarray[0][n-1]);

    return 0;
}

int m(int i, int j){
    int min, mink;

    if(i == j) {
        min = 0;
        mink = 0;
    } else {
        int temp = 0;
        int k = i;
        min = 0;
        mink = k;

        if (j < n){
            min = m(i, k) + m(k+1, j) + (mats[i-1].r) * (mats[k].r) * (mats[j].r);
        } else {
            min = m(i, k) + m(k+1, j) + (mats[i-1].r) * (mats[k].r) * (mats[j-1].s);
        }
        k++;

        while (k < j){
            if (j < n){
                temp = m(i, k) + m(k+1, j) + (mats[i-1].r) * (mats[k].r) * (mats[j].r);
            } else {
                temp = m(i, k) + m(k+1, j) + (mats[i-1].r) * (mats[k].r) * (mats[j-1].s);
            }

            if (temp < min){
                min = temp;
                mink = k;
            }
            k++;
        }
    }

    minvalarray[i-1][j-1] = min;
    karray[i-1][j-1] = mink;

    return min;
}
