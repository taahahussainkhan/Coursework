// Problem
// Create 10 threads each taking a unique 
// prime from the primes array and print it on the screen.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
void* routine(void* arg)
{
    int index = *(int*)arg;
    printf("%d ", primes[index]);
}
 
int main()
{
    pthread_t th[10];
    for(int i = 0; i < 10 ; i++)
    {
        int* ind = malloc(sizeof(int));
        *ind = i;
        if(pthread_create(&th[i], NULL, &routine, ind))
        {
            printf("Thread creation failed\n");
            exit(1);
        }
    }
    for( int  i = 0 ;i < 10 ;i++)
    {
        if(pthread_join(th[i],NULL))
        {
            printf("Thread join failed\n");
            exit(1);
        }
    }
}