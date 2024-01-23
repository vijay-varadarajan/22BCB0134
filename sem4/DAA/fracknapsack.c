#include <stdio.h>

typedef struct Item
{
    int benefit;
    int weight;
    double ratio;
} Item;

/// quicksort to sort arr[] in descending order based on ratio
void quicksort(Item arr[], int low, int high){
    if(low < high){
        double pivot = arr[high].ratio;
        int i = low - 1;

        for(int j = low; j <= high - 1; j++){
            if(arr[j].ratio > pivot){
                i++;
                Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        Item temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        quicksort(arr, low, i);
        quicksort(arr, i+2, high);
    }
}

double fracKnapsack(Item arr[], int n, int W){
    quicksort(arr, 0, n-1);

    int curWeight = 0;

    double finalvalue = 0.0;

    for(int i = 0; i < n; i++){
        if (arr[i].weight <= W){
            W -= arr[i].weight;
            finalvalue += arr[i].benefit;

            printf("Added object %d completely in the knapsack\n", i+1);
        }

        else {
            finalvalue += arr[i].ratio * W;
            printf("Added object %d partially in the knapsack\n", i+1);
            break;
        }
    }

    return finalvalue;
}

int main(void){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the benefit and weight of item %d: ", i+1);
        scanf("%d %d", &arr[i].benefit, &arr[i].weight);
        arr[i].ratio = (double) arr[i].benefit / arr[i].weight;
    }

    int W;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    double maxBenefit = fracKnapsack(arr, n, W);

    printf("Maximum benefit is %lf\n", maxBenefit);
}