#include <stdio.h>

int max2(int a, int b){
    return a > b ? a : b;
}

int max3(int a, int b, int c){
    return max2(max2(a, b), c);
}

int maxCrossingSum(int arr[], int l, int mid, int h, int* start, int* end){

    int leftsum = -1000;
    int sum = 0;
    int max_left = mid, max_right = mid;

    for(int i = mid; i >= l; i--){
        sum += arr[i];
        if(sum > leftsum){
            leftsum = sum;
            max_left = i;
        }
    }

    int rightsum = -1000;
    sum = 0;

    for(int i = mid + 1; i <= h; i++){
        sum += arr[i];
        if(sum > rightsum){
            rightsum = sum;
            max_right = i;
        }
    }

    *start = max_left;
    *end = max_right;

    return max3(leftsum + rightsum, leftsum, rightsum);
}   

int maxSubarraySum (int arr[], int l, int h, int* start, int* end){

    if (l == h){
        *start = *end = l;
        return arr[l];
    }

    int mid = (l + h) / 2;
    int left_start = mid, left_end = mid, right_start = mid, right_end = mid, cross_start = mid, cross_end = mid;

    int left_sum = maxSubarraySum(arr, l, mid, &left_start, &left_end);
    int right_sum = maxSubarraySum(arr, mid + 1, h, &right_start, &right_end);
    int cross_sum = maxCrossingSum(arr, l, mid, h, &cross_start, &cross_end);

    if (left_sum >= right_sum && left_sum >= cross_sum){
        *start = left_start;
        *end = left_end;
        return left_sum;
    }
    else if (right_sum >= left_sum && right_sum >= cross_sum){
        *start = right_start;
        *end = right_end;
        return right_sum;
    }
    else {
        *start = cross_start;
        *end = cross_end;
        return cross_sum;
    }
}

int main(void){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int start = 0, end = 0;
    int max_sum = maxSubarraySum(arr, 0, n-1, &start, &end);

    printf("Maximum contiguous sum is %d\n", max_sum);
    printf("The subarray is: ");
    for(int i = start; i <= end; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


// // kadane's algorithm

// int kadanes(int a[], int n){
//     int curmax = a[0];
//     int resultmax = a[0];

//     for (int i = 1; i < n; i++){
//         curmax = max(a[i], curmax + a[i]);

//         if (curmax > resultmax) {
//             resultmax = curmax;
//         }   
//     }

//     return resultmax;
// }

// int main(void) {
//     int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
//     int n = sizeof(a) / sizeof(a[0]);

//     int maxsum = kadanes(a, n);

//     printf("Maximum contiguous sum is %d\n", maxsum);
// }

