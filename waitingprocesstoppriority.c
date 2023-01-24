#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int execution_time;
};

int compare(const void* a, const void* b) {
    struct Process* p1 = (struct Process*) a;
    struct Process* p2 = (struct Process*) b;
    return p1->execution_time - p2->execution_time;
}

int main() {
    struct Process processes[] = {
        {1, 5},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 1}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    qsort(processes, n, sizeof(struct Process), compare);
    for (int i = 0; i < n; i++) {
        printf("Process %d, execution time: %d\n", processes[i].id, processes[i].execution_time);
    }
    return 0;
}
