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
    pthread_t th[4];
    pthread_mutex_init(&mutex,NULL); // Initialize mutex
    for (int i = 0; i < 4; i++)
    {
        if(pthread_create(th + i,NULL,&routine,NULL)){return 1;}
        printf("Thread %d created \n",i);
    }
    for (int i = 0; i < 4; i++)
    {
        if(pthread_join(th[i],NULL)){
        printf("Error in joining thread %d \n",i) ;
        return 2;
        }
        printf("Thread %d joined \n",i);
    }
    // Now the mail will give the correct value
    printf("Mails: %d \n",mail); // Output should be 200000
        // Destroy mutex
    pthread_mutex_destroy(&mutex);
}