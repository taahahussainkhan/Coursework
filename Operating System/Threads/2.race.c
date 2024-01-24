#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int mail = 1;
void* routine()
{
    for (int i = 0; i < 100000; i++)
    {
        /* code */
        mail++;
        //Read
        //Increament
        //Write
    }
}
int main()
{
    pthread_t tid1,tid2;
    if(pthread_create(&tid1,NULL,&routine,NULL))return 1;
    if(pthread_create(&tid2,NULL,&routine,NULL)) return 2;
    if(pthread_join(tid1,NULL))return 3;
    if(pthread_join(tid2,NULL)) return 4;
    printf("Mails: %d \n",mail); // Output should be 200000
    // But it is not 200000
    // This is called Race Condition.
    // Two threads are trying to access the same variable at the same time.
    // This is a problem.
    // We will solve this in the next file.
    
}