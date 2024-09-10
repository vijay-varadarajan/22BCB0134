#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct {
    int value, arrival, burst, remainingTime, priority, completionTime, waitTime, turnaroundTime;
} typedef Node;

int comparator(const void* a, const void* b) {
    Node *processA = (Node *)a;
    Node *processB = (Node *)b;

    if (processA->arrival == processB->arrival) {
        return processA->priority - processB->priority;  // If arrival times are same, compare by priority
    }
    return processA->arrival - processB->arrival;  // Sort by arrival time
}

int main() {
    int n;
    
    printf("Enter the Number Of Processes: ");
    scanf("%d", &n);
    
    Node arrProcess[n];
    bool isCompleted[n];
    memset(isCompleted, false, sizeof(isCompleted));

    printf("Enter Arrival Time, Burst Time and Priority: \n");
    for (int i = 0; i < n; i++) {
        arrProcess[i].value = i + 1;
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &arrProcess[i].arrival);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &arrProcess[i].burst);
        printf("Process %d priority (lower number = higher priority): ", i + 1);
        scanf("%d", &arrProcess[i].priority);
        arrProcess[i].remainingTime = arrProcess[i].burst;  // Remaining time is initially the burst time
    }

    // Sort processes by arrival time
    qsort(arrProcess, n, sizeof(Node), comparator);
    
    int currentTime = 0, completed = 0;
    float totalWaitTime = 0, totalTurnaroundTime = 0;
    
    while (completed < n) {
        int idx = -1;
        int highestPriority = 1000;  // Initialize to a high value, since lower numbers indicate higher priority
        
        // Select the process with the highest priority that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (arrProcess[i].arrival <= currentTime && !isCompleted[i] && arrProcess[i].priority < highestPriority && arrProcess[i].remainingTime > 0) {
                highestPriority = arrProcess[i].priority;
                idx = i;
            }
        }
        
        if (idx != -1) {
            // Execute the selected process for 1 unit of time (preemption)
            currentTime++;
            arrProcess[idx].remainingTime--;
            
            // If process finishes
            if (arrProcess[idx].remainingTime == 0) {
                isCompleted[idx] = true;
                completed++;
                
                arrProcess[idx].completionTime = currentTime;
                arrProcess[idx].turnaroundTime = arrProcess[idx].completionTime - arrProcess[idx].arrival;
                arrProcess[idx].waitTime = arrProcess[idx].turnaroundTime - arrProcess[idx].burst;
                
                totalWaitTime += arrProcess[idx].waitTime;
                totalTurnaroundTime += arrProcess[idx].turnaroundTime;
                
                printf("Process %d completed at time %d\n", arrProcess[idx].value, currentTime);
            }
        } else {
            // No process available to run, increment time
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
