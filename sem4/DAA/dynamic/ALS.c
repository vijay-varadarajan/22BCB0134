// A C program to find minimum possible time by the car chassis to complete 
#include <stdio.h> 
#define NUM_STATION 4 
  
// Utility function to find minimum of two numbers 
int min(int a, int b) { return a < b ? a : b; } 
  
int ALS(int a[][NUM_STATION], int t[][NUM_STATION]) 
{ 
    int F1[NUM_STATION], F2[NUM_STATION], j; 
  
    F1[0] = a[0][0];
    F2[0] = a[1][0];
    printf("%d %d\n", F1[0], F2[0]);
  
    for (j = 1; j < NUM_STATION; j++) 
    { 
        F1[j] = min(F1[j-1] + a[0][j], F2[j-1] + t[1][j-1] + a[0][j]); 
        F2[j] = min(F2[j-1] + a[1][j], F1[j-1] + t[0][j-1] + a[1][j]); 
        printf("%d %d\n", F1[j], F2[j]);
    } 
  
    return min(F1[NUM_STATION-1], F2[NUM_STATION-1]); 
} 
  
int main() 
{ 
    int t[][NUM_STATION] = {{2, 3, 2}, {1, 2, 4}}; 
    int a[][NUM_STATION] = {{10, 20, 15, 15}, {10, 15, 20, 10}}; 
    
    printf("Minimum: %d", ALS(a, t)); 
  
    return 0; 
} 