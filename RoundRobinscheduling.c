#include <stdio.h> 
#include <stdlib.h> 

struct Process { 
    int pid; 
    int bt; 
    int remaining_bt; 
    int waiting_time;  
}; 

void findWaitingTime(struct Process proc[], int n, int quantum, int wt[]) { 
    int i, total_time = 0, done = 0; 

    while (done != n) { 
        for (i = 0; i < n; i++) { 
            if (proc[i].remaining_bt > 0) { 
                if (proc[i].remaining_bt > quantum) { 
                    total_time += quantum; 
                    proc[i].remaining_bt -= quantum; 
                } else { 
                    total_time += proc[i].remaining_bt; 
                    proc[i].waiting_time = total_time - proc[i].bt; 
                    proc[i].remaining_bt = 0; 
                    done++; 
                } 
            } 
        } 
    } 
} 

void findTurnAroundTime(struct Process proc[], int n, int tat[]) { 
    int i; 
    for (i = 0; i < n; i++) { 
        tat[i] = proc[i].bt + proc[i].waiting_time; 
    } 
} 


void roundRobin(struct Process proc[], int n, int quantum) { 
    int i, total_wt = 0, total_tat = 0; 

    findWaitingTime(proc, n, quantum, wt); 
    findTurnAroundTime(proc, n, tat); 

    printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\n"); 
    for (i = 0; i < n; i++) { 
        total_wt += proc[i].waiting_time; 
        total_tat += tat[i]; 
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].waiting_time, tat[i]); 
    } 

    printf("Average Waiting Time: %f\n", (float)total_wt / (float)n); 
    printf("Average Turn Around Time: %f\n", (float)total_tat / (float)n); 
} 

int main() { 
    int n, quantum, i; 

    printf("Enter the number of processes: "); 
    scanf("%d", &n); 

    printf("Enter the time quantum: "); 
    scanf("%d", &quantum); 

    struct Process proc[n
