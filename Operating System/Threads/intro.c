#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void* routine()
{
    printf("Hi I am Thread! \n");
    sleep(3);
    printf("Thread ended! \n");


}
int main()
{
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,&routine,NULL);
    pthread_create(&tid2,NULL,&routine,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}