#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 128

struct message {
    long mtype;
    char mtext[MAX_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

  
    key = ftok(".", 'a');

    
  msgid = msgget(key, 0666 | IPC_CREAT);

  
  pid_t pid = fork();
    if (pid == 0) {
        msgrcv(msgid, &msg, MAX_SIZE, 1, 0);
        printf("Child received: %s\n", msg.mtext);
    } else {
        msg.mtype = 1;
        strcpy(msg.mtext, "Hello, World!");
        msgsnd(msgid, &msg, MAX_SIZE, 0);
        printf("Parent sent: %s\n", msg.mtext);
    }

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
