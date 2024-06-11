#include<stdio.h>
#define NUM_LINE 2  
#define NUM_STATION 4  
  
// Utility function to find a minimum of two numbers  
int min(int a, int b) 
{  
    return a < b ? a : b;  
}  
  
int carAssembly(int a[][NUM_STATION],  
                int t[][NUM_STATION])  
{  
    int T1[NUM_STATION], T2[NUM_STATION], i;  
  
    // time taken to leave first station in line 1  
    T1[0] = a[0][0];  
      
    // time taken to leave first station in line 2  
    T2[0] = a[1][0];  
  
    // Fill tables T1[] and T2[] using the  
    // above given recursive relations  
    for (i = 1; i < NUM_STATION; ++i)  
    {  
        T1[i] = min(T1[i - 1] + a[0][i],  
                    T2[i - 1] + t[1][i] + a[0][i]);  
        T2[i] = min(T2[i - 1] + a[1][i], 
                    T1[i - 1] + t[0][i] + a[1][i]);  
    }  
  
    // Consider exit times and return minimum  
    return min(T1[NUM_STATION - 1],  
               T2[NUM_STATION - 1]);  
}  
  
// Driver Code 
int main()  
{  
    int a[NUM_LINE][NUM_STATION];
    int t[NUM_LINE][NUM_STATION];
    int e[NUM_LINE];
    int x[NUM_LINE];

    printf("Enter the values for array a:\n");
    for (int i = 0; i < NUM_LINE; i++) {
        for (int j = 0; j < NUM_STATION; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the values for array t:\n");
    for (int i = 0; i < NUM_LINE; i++) {
        for (int j = 0; j < NUM_STATION; j++) {
            printf("t[%d][%d]: ", i, j);
            scanf("%d", &t[i][j]);
        }
    }
  
    printf("%d", carAssembly(a, t)); 
  
    return 0;  
}  