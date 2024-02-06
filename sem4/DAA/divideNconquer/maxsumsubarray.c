#include <stdio.h>

/*
int max2(int a, int b){
    return a > b ? a : b;
}

int max3(int a, int b, int c){
    return max2(max2(a, b), c);
}

int maxCrossingSum(int arr[], int l, int mid, int h){

    int leftsum = -1000;
    int sum = 0;

    for(int i = mid; i >= l; i--){
        sum += arr[i];
        if(sum > leftsum) leftsum = sum;
    }

    int rightsum = -1000;
    sum = 0;

    for(int i = mid; i <= h; i++){
        sum += arr[i];
        if(sum > rightsum) rightsum = sum;
    }

    return max3(leftsum + rightsum - arr[mid], leftsum, rightsum);
}   

int maxSubarraySum (int arr[], int l, int h){

    if (l > h) return 0;
    
    if (l == h) return arr[l];

    int mid = (l + h) / 2;

    return max3(maxSubarraySum(arr, l, mid-1), maxSubarraySum(arr, mid+1, h), maxCrossingSum(arr, l, mid, h));
}

int main(void){
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubarraySum(arr, 0, n-1);

    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
*/

// kadane's algorithm

int kadanes(int a[], int n){
    int curmax = a[0];
    int resultmax = a[0];

    for (int i = 1; i < n; i++){
        curmax = max(a[i], curmax + a[i]);

        if (curmax > resultmax) {
            resultmax = curmax;
        }   
    }

    return resultmax;
}

int main(void) {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    int maxsum = kadanes(a, n);

    printf("Maximum contiguous sum is %d\n", maxsum);
}

