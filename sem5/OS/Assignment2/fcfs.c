#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct {
    int value, arrival, burst, startTime, completionTime, waitTime, turnaroundTime;
} typedef Node;

int comparator(const void* a, const void* b) {
    Node *processA = (Node *)a;
    Node *processB = (Node *)b;

    // First compare by arrival time
    if (processA->arrival != processB->arrival)
        return processA->arrival - processB->arrival;

    // If arrival times are the same, compare by process index (value)
    return processA->value - processB->value;
}

int main() {
    int n;

    printf("Enter the Number Of Processes: ");
    scanf("%d", &n);

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

    // Sort processes by arrival time (FCFS runs based on the order of arrival)
    qsort(arrProcess, n, sizeof(Node), comparator);

    int currentTime = 0;
    float totalWaitTime = 0;
    float totalTurnaroundTime = 0;

    printf("\nExecution Order:\n");

    for (int i = 0; i < n; i++) {
        // If the current time is less than the process's arrival time, wait for the process to arrive
        if (currentTime < arrProcess[i].arrival) {
            currentTime = arrProcess[i].arrival;
        }

        // Process start time is the current time
        arrProcess[i].startTime = currentTime;

        // Process completion time is start time + burst time
        arrProcess[i].completionTime = arrProcess[i].startTime + arrProcess[i].burst;

        // Wait time is start time - arrival time
        arrProcess[i].waitTime = arrProcess[i].startTime - arrProcess[i].arrival;

        // Turnaround time is completion time - arrival time
        arrProcess[i].turnaroundTime = arrProcess[i].completionTime - arrProcess[i].arrival;

        totalWaitTime += arrProcess[i].waitTime;
        totalTurnaroundTime += arrProcess[i].turnaroundTime;

        printf("Process %d executed from %d to %d\n", arrProcess[i].value, arrProcess[i].startTime, arrProcess[i].completionTime);

        // Update current time
        currentTime = arrProcess[i].completionTime;
    }

    // Calculate average wait time and average turnaround time
    float avgWaitTime = totalWaitTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Wait Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
