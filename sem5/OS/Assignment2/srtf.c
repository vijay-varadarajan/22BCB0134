#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct {
    int value, arrival, burst, remainingBurst;
} typedef Node;

int comparator(const void* a, const void* b) {
    return ((Node *)a)->arrival - ((Node *)b)->arrival;
}

int main() {
    int n;

    printf("Enter the Number Of Processes: ");
    scanf("%d", &n);

    bool isCompleted[n];
    memset(isCompleted, false, sizeof(isCompleted));  // All processes are initially not completed

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
        arrProcess[i].remainingBurst = arrProcess[i].burst;  // Initialize remaining burst time
    }

    // Sort processes by arrival time
    qsort(arrProcess, n, sizeof(Node), comparator);

    int currentTime = 0;
    int completed = 0;
    int lastExecutedTime = -1;
    int totalWaitTime = 0;
    int totalTurnaroundTime = 0;

    while (completed < n) {
        int minRemainingBurst = 1000;  // Arbitrarily large value
        int nextProcess = -1;

        // Find the process with the smallest remaining burst time that has already arrived
        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && arrProcess[i].arrival <= currentTime && arrProcess[i].remainingBurst < minRemainingBurst) {
                minRemainingBurst = arrProcess[i].remainingBurst;
                nextProcess = i;
            }
        }

        if (nextProcess != -1) {
            // Execute the next process for 1 time unit (preemptive)
            if (lastExecutedTime != currentTime) {
                printf("Process %d executed from %d to %d\n", arrProcess[nextProcess].value, currentTime, currentTime + 1);
                lastExecutedTime = currentTime;
            }

            arrProcess[nextProcess].remainingBurst--;
            currentTime++;

            // If the process is completed
            if (arrProcess[nextProcess].remainingBurst == 0) {
                isCompleted[nextProcess] = true;
                completed++;

                int turnaroundTime = currentTime - arrProcess[nextProcess].arrival;
                int waitTime = turnaroundTime - arrProcess[nextProcess].burst;
                
                totalWaitTime += waitTime;
                totalTurnaroundTime += turnaroundTime;

                printf("Process %d completed at time %d\n", arrProcess[nextProcess].value, currentTime);
                printf("Turnaround time for Process %d: %d, Wait time: %d\n", arrProcess[nextProcess].value, turnaroundTime, waitTime);
            }
        } else {
            // No process is available to execute, move forward in time
            currentTime++;
        }
    }

    float avgWaitTime = (float)totalWaitTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nAverage Wait Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}


