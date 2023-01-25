#include <stdio.h> 
#include <stdlib.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/types.h> 
#include <unistd.h> 

#define SHM_SIZE 1024 

int main() { 
    int shmid; 
    key_t key; 
    char *shm, *s; 

    key = ftok("shmfile", 65); 

    
  shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); 

  
  shm = shmat(shmid, NULL, 0); 

  
  memcpy(shm, "Hello, World!", 13); 

  
  pid_t pid = fork(); 
    if (pid == 0) { 
        sleep(1); 
  
      printf("Child read: %s\n", shm); 

      
      shmdt(shm); 
    } else { 
      
      sleep(2); 
      
      shmdt(shm); 

      
      shmctl(shmid, IPC_RMID, NULL); 
    } 

    return 0; 
}
