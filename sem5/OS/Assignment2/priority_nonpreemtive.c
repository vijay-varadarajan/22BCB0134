#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Structure for a process
struct {
    int value, arrival, burst, priority, startTime, completionTime, waitTime, turnaroundTime;
} typedef Node;

// Comparator function to sort by priority first, then arrival time
int comparator(const void* a, const void* b) {
    Node *processA = (Node *)a;
    Node *processB = (Node *)b;

    if (processA->priority == processB->priority) {
        return processA->arrival - processB->arrival;  // Sort by arrival time if priorities are the same
    }
    return processA->priority - processB->priority;    // Sort by priority (lower priority number is higher priority)
}

int main() {
    int n;

    printf("Enter the Number Of Processes: ");
    scanf("%d", &n);

    bool arrBool[n];  // To track completed processes
    memset(arrBool, false, sizeof(arrBool));  // Initialize to false (none completed)

    Node arrProcess[n];

    printf("Enter Arrival Time and Priority: \n");
    for (int i = 0; i < n; i++) {
        arrProcess[i].value = i + 1;
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrProcess[i].arrival);
        printf("Process %d priority (lower number = higher priority): ", i + 1);
        scanf("%d", &arrProcess[i].priority);
    }

    printf("Enter Burst Time: \n");
    for (int i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &arrProcess[i].burst);
    }

    // Sort Processes According to priority (and arrival time if needed)
    qsort(arrProcess, n, sizeof(Node), comparator);

    int currentTime = arrProcess[0].arrival;  // Start from the first process's arrival time
    int completed = 0;

    float totalWaitTime = 0;
    float totalTurnaroundTime = 0;

    while (completed < n) {
        int nextProcess = -1;

        // Select process with the highest priority that has arrived
        for (int i = 0; i < n; i++) {
            if (!arrBool[i] && arrProcess[i].arrival <= currentTime) {
                nextProcess = i;
                break;  // As the processes are already sorted by priority, take the first available
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
            arrProcess[nextProcess].waitTime = arrProcess[nextProcess].startTime - arrProcess[nextProcess].arrival;

            // Accumulate total waiting time and turnaround time
            totalWaitTime += arrProcess[nextProcess].waitTime;
            totalTurnaroundTime += arrProcess[nextProcess].turnaroundTime;

            printf("Process %d executed from %d to %d with priority %d\n", arrProcess[nextProcess].value, arrProcess[nextProcess].startTime, currentTime, arrProcess[nextProcess].priority);

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
