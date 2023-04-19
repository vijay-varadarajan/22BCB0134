#include <stdio.h>
#include <stdlib.h>

void countsort(int a[], int n);
int findmax(int a[], int n);

int main(void)
{
    int a[] = {2,1,5,3,4,4,12,3,7,9,8,8,2,8,1}, n = 15;
    
    countsort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}


void countsort(int a[], int n)
{
    int max = findmax(a, n);
    
    int *count = malloc((max + 1)*sizeof(int));
    int i = 0, j = 0;
    
    for (i = 0; i <= max; i++)
        count[i] = 0;
    
    for (i = 0; i < n; i++)
        count[a[i]]++;

    i = 0;
    while (j <= max){
        if (count[j] > 0){
            a[i] = j;
            i++; count[j]--;
        }
        else{
            j++;
        }
    }
}


int findmax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}
