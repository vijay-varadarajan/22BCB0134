#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct {
    int value, arrival, burst, startTime, completionTime, waitTime, turnaroundTime;
} typedef Node;

int comparator(const void* a, const void* b) {
    return ((Node *)a)->arrival - ((Node *)b)->arrival;
}

int main() {
    int n;

    printf("Enter the Number Of Processes: ");
    scanf("%d", &n);

    bool arrBool[n];
    memset(arrBool, false, sizeof(arrBool));  // Corrected memset

    Node arrProcess[n];

    printf("Enter Arrival Time: \n");
    for (int i = 0; i < n; i++) {
        arrProcess[i].value = i + 1;
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrProcess[i].arrival);
    }

    printf("Enter Burst Time: \n");
    for (int i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &arrProcess[i].burst);
    }

    // Sort Processes According to their arrival time
    qsort(arrProcess, n, sizeof(Node), comparator);

    int currentTime = arrProcess[0].arrival;  // Start from the first process's arrival time
    int completed = 0;

    float totalWaitTime = 0;
    float totalTurnaroundTime = 0;

    while (completed < n) {
        int minBurst = 1000;  // Arbitrarily large value for initial comparison
        int nextProcess = -1;

        // Select process with the smallest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (!arrBool[i] && arrProcess[i].burst < minBurst && arrProcess[i].arrival <= currentTime) {
                minBurst = arrProcess[i].burst;
                nextProcess = i;
            }
        }

        if (nextProcess != -1) {
            // Set the start time for the process
            arrProcess[nextProcess].startTime = currentTime;

            // Execute the next process
            currentTime += arrProcess[nextProcess].burst;
            
            // Set the completion time
            arrProcess[nextProcess].completionTime = currentTime;

            // Calculate turnaround time and wait time
            arrProcess[nextProcess].turnaroundTime = arrProcess[nextProcess].completionTime - arrProcess[nextProcess].arrival;
            arrProcess[nextProcess].waitTime = arrProcess[nextProcess].turnaroundTime - arrProcess[nextProcess].burst;

            // Accumulate total waiting time and turnaround time
            totalWaitTime += arrProcess[nextProcess].waitTime;
            totalTurnaroundTime += arrProcess[nextProcess].turnaroundTime;

            printf("Process %d executed from %d to %d\n", arrProcess[nextProcess].value, arrProcess[nextProcess].startTime, currentTime);

            arrBool[nextProcess] = true;  // Mark the process as completed
            completed++;
        } else {
            // If no process is available, increment currentTime
            currentTime++;
        }
    }

    // Calculate average wait time and turnaround time
    float avgWaitTime = totalWaitTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
