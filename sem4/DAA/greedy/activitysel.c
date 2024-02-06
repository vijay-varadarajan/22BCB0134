#include <stdio.h>

typedef struct data{
    char letter;
    int start;
    int finish;
} data;

void activitySelection(data arr[], int n){
    int i = 0;
    printf("%c", arr[i].letter);

    for (int j = 1; j < n; j++){
        if(arr[j].start >= arr[i].finish){
            printf("%c", arr[j].letter);
            i = j;
        }
    }
}

int main(void){

    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    data arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the start time and finish time of activity %d: ", i+1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
        arr[i].letter = 'p' + i;
    }

    activitySelection(arr, n);
}