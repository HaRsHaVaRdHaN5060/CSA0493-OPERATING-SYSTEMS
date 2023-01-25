#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
sem_t mutex;
sem_t S[N];

void *philosopher(void *num)
{
    while(1)
    {
        int i = (int)num;
        sleep(1);
        take_chopsticks(i);
        sleep(0);
        put_chopsticks(i);
    }
}

void take_chopsticks(int i)
{
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i+1);
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
}

void test(int i)
{
    if (state[i] == HUNGRY && state[(i + 4) % N] != EATING && state[(i + 1) % N] != EATING)
    {
        state[i] = EATING;
        sleep(2);
        printf("Philosopher %d takes chopstick %d and %d\n", i + 1, (i + 4) % N + 1, i + 1);
        printf("Philosopher %d is Eating\n", i + 1);
        sem_post(&S[i]);
    }
}

void put_chopsticks(int i)
{
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d putting chopstick %d and %d down\n", i + 1, (i + 4) % N + 1, i + 1);
    printf("Philosopher %d is thinking\n", i + 1);
    test((i + 4) % N);
    test((i + 1) % N);
    sem_post(&mutex);
}

int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);
    for (i = 0; i < N; i++)
    {
        pthread_create(&thread_id[i], NULL, philosopher, (void *)i);
        printf("Philosopher %d is thinking\n", i + 1);
    }
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}
