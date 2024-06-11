#include <stdio.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int max(int a, int b) { return a > b ? a : b; }

void LCS(char* a, char* b){
    int i, j;

    int m = 8, n = 8;

    int C[m+1][n+1];

    for (int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++){
            if (i == 0 || j == 0){
                C[i][j] = 0;
            }
            else if (a[i-1] == b[j-1]){
                C[i][j] = C[i-1][j-1] + 1;
            }
            else {
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            }
        }
    }

    for (int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++){
            printf("%d ", C[i][j]);
        } printf("\n");
    }

    i = m, j = n;
    int k = 0;
    int ipos[n];

    while(i > 0 || j > 0){
        if (a[i-1] == b[j-1]){
            ipos[k] = i-1;
            i--;
            j--;
            k++;
        } else if (C[i][j-1] > C[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }

    for(int i = k-1; i >= 0; i--){
        printf("%c ", a[ipos[i]]);
    }
}

int main(void){
    char a[8] = "ABCDGHKL";
    char b[8] = "AEDFHRKL";

    LCS(a, b);

    return 0;
}