// A C program to find minimum possible time by the car chassis to complete 
#include <stdio.h> 
  
// Utility function to find minimum of two numbers 
int min(int a, int b) { return a < b ? a : b; } 
  
int ALS(int n, int a[][n], int t[][n]) 
{ 
    int F1[n], F2[n], j; 
  
    F1[0] = a[0][0];
    F2[0] = a[1][0];
    printf("%d %d\n", F1[0], F2[0]);
  
    for (j = 1; j < n; j++) 
    { 
        F1[j] = min(F1[j-1] + a[0][j], F2[j-1] + t[1][j-1] + a[0][j]); 
        F2[j] = min(F2[j-1] + a[1][j], F1[j-1] + t[0][j-1] + a[1][j]); 
        printf("%d %d\n", F1[j], F2[j]);
    } 
  
    return min(F1[n-1], F2[n-1]); 
} 
  
int main() 
{ 
    int n;
    printf("Enter the number of stations: ");
    scanf("%d", &n);

    int a[2][n];
    int t[2][n];

    printf("Enter the time taken at each station in line 1: ");
    scanf("%d%d%d%d", &a[0][0], &a[0][1], &a[0][2], &a[0][3]);

    printf("Enter the time taken at each station in line 2: ");
    scanf("%d%d%d%d", &a[1][0], &a[1][1], &a[1][2], &a[1][3]);

    printf("Enter time taken to cross from line 1 to 2 for each station: ");
    scanf("%d%d%d", &t[0][0], &t[0][1], &t[0][2], &t[0][3]);

    printf("Enter time taken to cross from line 2 to 1 for each station: ");
    scanf("%d%d%d", &t[1][0], &t[1][1], &t[1][2], &t[1][3]);
    
    printf("Minimum: %d", ALS(n, a, t)); 
  
    return 0; 
} 



// Generalized: fi[j] = ---> a[i][1] if (j = 1)
//                      ---> min|(a<=k<=m)(f[k][j-1] + t[k][j-1][i] + a[i][j]) if (j > 1)