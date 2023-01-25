#include <pthread.h>
#include <stdio.h>

void *myThreadFun(void *vargp)
{
    printf("Printing from thread.\n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("Before thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After thread\n");
    return 0;
}
