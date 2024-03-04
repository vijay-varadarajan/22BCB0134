#include <stdio.h>
#define MAX 100

typedef struct Matrix {
    int r;
    int s;
} Matrix;

Matrix mats[MAX];
int minvalarray[MAX][MAX];
int karray[MAX][MAX];

int m(int i, int j, int n);
void printOptimalParenthesis(int i, int j);

int main(void){
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter the dimensions of matrix %d: ", i+1);
        scanf("%d %d", &mats[i].r, &mats[i].s);
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

    int arr_min = 0;
    for (int i = 1; i <= n; i++){
        for (int j = n; j > 0; j--){
            if (i-1 <= j-1){
                arr_min = m(i, j, n);
            }
        }
    }

    printf("\nMinimum number of multiplications: \n");
    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            printf("%d ", minvalarray[i-1][j-1]);
        }
        printf("\n");
    }

    printf("\nValues of k: \n");
    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            printf("%d ", karray[i-1][j-1]);
        }
        printf("\n");
    }

    printf("\nMinimum number of multiplications: %d\n", minvalarray[0][n-1]);

    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n);
    printf("\n");

    return 0;
}

int m(int i, int j, int n){
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
            min = m(i, k, n) + m(k+1, j, n) + (mats[i-1].r) * (mats[k].r) * (mats[j].r);
        } else {
            min = m(i, k, n) + m(k+1, j, n) + (mats[i-1].r) * (mats[k].r) * (mats[j-1].s);
        }
        k++;

        while (k < j){
            if (j < n){
                temp = m(i, k, n) + m(k+1, j, n) + (mats[i-1].r) * (mats[k].r) * (mats[j].r);
            } else {
                temp = m(i, k, n) + m(k+1, j, n) + (mats[i-1].r) * (mats[k].r) * (mats[j-1].s);
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

void printOptimalParenthesis(int i, int j) {
    if (i == j) {
        printf("A%d ", i);
    } else {
        printf("(");
        printOptimalParenthesis(i, karray[i-1][j-1]);
        printOptimalParenthesis(karray[i-1][j-1] + 1, j);
        printf(")");
    }
}
