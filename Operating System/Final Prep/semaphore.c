#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>   
#define THREADS 5
sem_t semaphore;
void* routine(void* arg)
{
     int thread_num = *(int*)arg;
     sem_wait(&semaphore);
        printf("Thread %d is in critical section\n",thread_num);
        sem_post(&semaphore);
    free(arg);
    
}
int main()
{
    pthread_t th[THREADS];
     int* arg = malloc(sizeof(*arg));
    sem_init(&semaphore,0,1);
    for (int i = 0; i < THREADS; i++)
    {
        int* arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&th[i],NULL,&routine,arg);
    }
    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(th[i],NULL);
    }
}