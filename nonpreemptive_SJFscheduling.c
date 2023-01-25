#include <stdio.h> 
#include <stdlib.h> 

struct Process { 
    int pid; // Process ID 
    int bt; // Burst Time 
}; 


int shortestJob(struct Process proc[], int n, int curr_time) { 
    int i, short_bt = INT_MAX, loc = -1; 
    for (i = 0; i < n; i++) { 
        if (proc[i].bt < short_bt && proc[i].bt != 0) { 
            short_bt = proc[i].bt; 
            loc = i; 
        } 
    } 
    return loc; 
} 


void findWaitingTime(struct Process proc[], int n, int wt[]) { 
    int i, j, total_time = 0, loc; 

    // Finding the waiting time
    for (i = 0; i < n; i++) { 
        loc = shortestJob(proc, n, total_time); 
        total_time += proc[loc].bt; 
        wt[loc] = total_time - proc[loc].bt; 
    } 
} 

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) { 
    int i; 
    for (i = 0; i < n; i++) { 
        tat[i] = proc[i].bt + wt[i]; 
    } 
} 
 
void nonPreemptiveSJF(struct Process proc[], int n) { 
    int i, wt[n], tat[n], total_wt = 0, total_tat = 0; 


    findWaitingTime(proc, n, wt); 
    findTurnAroundTime(proc, n, wt, tat); 

   
    printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\n"); 
    for (i = 0; i < n; i++) { 
        total_wt += wt[i]; 
        total_tat += tat[i]; 
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]); 
    } 

    printf("Average Waiting Time: %f\n", (float)total_wt / (float)n); 
    printf("Average Turn Around Time: %f\n", (float)total_tat / (float)n); 
} 


int main() { 
    int n, i; 


    printf("Enter the number of processes: "); 
    scanf("%d", &n); 

    struct Process proc[n]; 

   
