// Dynamic Programming C++ implementation
// of LCS problem
#include <stdio.h>
 
// Returns length of LCS for X[0..m-1],
// Y[0..n-1]

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char* X, char* Y, int m, int n)
{
    int C[m + 1][n + 1];
    int ipos[m];
    int k = 0;
 
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                C[i][j] = 0;
            }
 
            else if (X[i - 1] == Y[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
            }
 
            else {
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
            }
        }
    }

    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    int i = m, j = n;
    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            ipos[k] = i-1;
            k++;
            i--;
            j--;
        } else if(C[i-1][j] > C[i][j-1]){
            i--;
        } else {
            j--;
        }
    }

    for(int i = k-1; i >= 0; i--){
        printf("%c ", X[ipos[i]]);
    }
    printf("\n");

    return C[m][n];
}

int main()
{
    char* S1 = "ABCDGHKL";
    char* S2 = "AEDFHRKL";
    int m = sizeof(S1) / sizeof(S1[0]);
    int n = sizeof(S2) / sizeof(S2[0]);
 
    printf("Length of LCS is %d\n", lcs(S1, S2, m, n));
 
    return 0;
}