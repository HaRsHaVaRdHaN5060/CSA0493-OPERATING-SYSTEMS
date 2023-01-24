#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, ppid;
    pid = fork();

    if (pid == 0) {
        // Child process
        pid = getpid();
        ppid = getppid();
        printf("Child Process:\n");
        printf("PID: %d\n", pid);
        printf("Parent PID: %d\n", ppid);
    } else {
        // Parent process
        pid = getpid();
        printf("Parent Process:\n");
        printf("PID: %d\n", pid);
    }

    return 0;
}
