#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct {
    int value, arrival, burst, remainingTime, completionTime, waitTime, turnaroundTime;
} typedef Node;

int comparator(const void* a, const void* b) {
    return ((Node *)a)->arrival - ((Node *)b)->arrival;  // Sort by arrival time
}

int main() {
    int n, timeQuantum;
    
    printf("Enter the Number Of Processes: ");
    scanf("%d", &n);

    Node arrProcess[n];
    bool isCompleted[n];
    memset(isCompleted, false, sizeof(isCompleted));

    printf("Enter Arrival Time and Burst Time: \n");
    for (int i = 0; i < n; i++) {
        arrProcess[i].value = i + 1;
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrProcess[i].arrival);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &arrProcess[i].burst);
        arrProcess[i].remainingTime = arrProcess[i].burst;  // Initialize remaining time with burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    // Sort processes by arrival time
    qsort(arrProcess, n, sizeof(Node), comparator);

    int currentTime = 0, completed = 0;
    int totalWaitTime = 0, totalTurnaroundTime = 0;
    int queue[n], front = 0, rear = 0;  // Queue for Round Robin
    bool inQueue[n];
    memset(inQueue, false, sizeof(inQueue));

    // Start with the first process that arrives
    queue[rear++] = 0;  // Enqueue first process
    inQueue[0] = true;

    while (completed < n) {
        if (front == rear) {  // If no process is in the queue
            currentTime++;
            continue;
        }

        int idx = queue[front++];  // Dequeue process

        if (arrProcess[idx].remainingTime > timeQuantum) {
            // Execute the process for the time quantum
            currentTime += timeQuantum;
            arrProcess[idx].remainingTime -= timeQuantum;
        } else {
            // Process completes
            currentTime += arrProcess[idx].remainingTime;
            arrProcess[idx].remainingTime = 0;
            arrProcess[idx].completionTime = currentTime;
            arrProcess[idx].turnaroundTime = arrProcess[idx].completionTime - arrProcess[idx].arrival;
            arrProcess[idx].waitTime = arrProcess[idx].turnaroundTime - arrProcess[idx].burst;

            totalWaitTime += arrProcess[idx].waitTime;
            totalTurnaroundTime += arrProcess[idx].turnaroundTime;
            completed++;

            printf("Process %d completed at time %d\n", arrProcess[idx].value, currentTime);
        }

        // Enqueue any processes that have arrived by the current time
        for (int i = 0; i < n; i++) {
            if (arrProcess[i].arrival <= currentTime && arrProcess[i].remainingTime > 0 && !inQueue[i]) {
                queue[rear++] = i;  // Enqueue the process
                inQueue[i] = true;
            }
        }

        // If the current process is not finished, put it back in the queue
        if (arrProcess[idx].remainingTime > 0) {
            queue[rear++] = idx;  // Re-enqueue the process
        }

        // If there are no processes in the queue, increase time until one arrives
        if (front == rear) {
            for (int i = 0; i < n; i++) {
                if (arrProcess[i].remainingTime > 0) {
                    currentTime = arrProcess[i].arrival;
                    queue[rear++] = i;  // Enqueue the first available process
                    inQueue[i] = true;
                    break;
                }
            }
        }
    }

    // Calculate average wait time and turnaround time
    float avgWaitTime = (float)totalWaitTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
