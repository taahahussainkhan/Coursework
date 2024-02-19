#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

#define NO_OF_PHILOSOPHERS 5
sem_t forks[NO_OF_PHILOSOPHERS];

void* philosopher(void* arg){
    int index = *(int*)arg;
    int leftFork = index;
    int rightFork = (index+1) % NO_OF_PHILOSOPHERS;
    while(1)
    {
        printf("Philosopher %d is thinking! \n",index);
        sleep(1);
        printf("Philosopher %d is hungry! \n",index);
        sleep(1);
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);
        sleep(1);
        printf("Philosopher %d is eating! \n",index);
        sleep(1);
        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
        printf("Philosopher %d is thinking again! \n",index);
    }
}
int main()
{
    pthread_t phi[NO_OF_PHILOSOPHERS];
    int indexes[NO_OF_PHILOSOPHERS];
    for (int i = 0; i < NO_OF_PHILOSOPHERS; i++)
    {
        sem_init(&forks[i],0,1);
    }
    for (int i = 0; i < NO_OF_PHILOSOPHERS; i++)
    {
        indexes[i] = i;
        pthread_create(&phi[i],NULL,&philosopher,&indexes[i]);
    }
    for (int i = 0; i < NO_OF_PHILOSOPHERS; i++)
    {
        pthread_join(phi[i],NULL);
    }
   for (int i = 0; i < NO_OF_PHILOSOPHERS; i++)
    {
        sem_destroy(&forks[i]);
    }

}