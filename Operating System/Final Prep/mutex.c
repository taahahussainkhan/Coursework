#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int  count = 0;
pthread_mutex_t mutex;
void* routine()
{
    for(int i = 0 ;i < 9000000 ; i++)
    {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,&routine,NULL);
    pthread_create(&t2,NULL,&routine,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Count = %d\n",count);
    pthread_mutex_destroy(&mutex);
}