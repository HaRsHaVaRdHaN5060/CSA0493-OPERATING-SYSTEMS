#include <stdio.h> 
#include <stdlib.h> 

struct Process { 
    int pid; // Process ID 
    int bt; // Burst Time 
    int priority; // Priority of this process 
    int waiting_time; // Waiting time of this process 
}; 

int highestPriority(struct Process proc[], int n, int curr_time) { 
    int i, high = -1, loc = -1; 
    for (i = 0; i < n; i++) { 
        if ((proc[i].priority < high || high == -1) && proc[i].bt != 0) { 
            high = proc[i].priority; 
            loc = i; 
        } 
    } 
    return loc; 
} 

void findWaitingTime(struct Process proc[], int n, int wt[]) { 
    int i, j, total_time = 0, loc; 

    // Finding the waiting time
    for (i = 0; i < n; i++) { 
        loc = highestPriority(proc, n, total_time); 
        total_time += proc[loc].bt; 
        wt[loc] = total_time - proc[loc].bt - proc[loc].priority; 
    } 
} 

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) { 
    int i; 
    for (i = 0; i < n; i++) { 
        tat[i] = proc[i].bt + wt[i]; 
    } 
} 

void preemtivePriority(struct Process proc[], int n) { 
    int i, wt[n], tat[n], total_wt = 0, total_tat = 0; 

   
    findWaitingTime(proc, n, wt); 
    findTurnAroundTime(proc, n, wt, tat); 
 
    printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\tPriority\n"); 
    for (i = 0; i < n; i++) { 
        total_wt += wt[i]; 
        total_tat += tat[i]; 
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i], proc[i].priority); 
    } 

    printf("Average Waiting Time: %f\n", (float)total_wt / (float)n); 
    printf("Average Turn Around Time: %f\n", (float)total_tat / (float)n); 
} 
