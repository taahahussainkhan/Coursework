#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int mail = 0;
// Solution to Race Condition
pthread_mutex_t mutex; // Declare mutex
void* routine()
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        mail++;
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t tid1,tid2;
    pthread_mutex_init(&mutex,NULL); // Initialize mutex
    if(pthread_create(&tid1,NULL,&routine,NULL))return 1;
    if(pthread_create(&tid2,NULL,&routine,NULL)) return 2;
    if(pthread_join(tid1,NULL))return 3;
    if(pthread_join(tid2,NULL)) return 4;
    // Now the mail will give the correct value
    printf("Mails: %d \n",mail); // Output should be 200000
        // Destroy mutex
    pthread_mutex_destroy(&mutex);
}