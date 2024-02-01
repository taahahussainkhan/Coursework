#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* sum(void* arg)
{
    int sum = 0;
    int index = *(int*)arg;
    for(int i = 0 ; i < 5  ; i++)
    {
        sum += primes[index + i];
    }
    *(int*)arg = sum;
    return arg;
}

int main()
{
    pthread_t th[2];
    for(int  i = 0 ; i < 2 ; i++)
    {
        int* a = malloc(sizeof(int));
        *a = i * 5;
        pthread_create(&th[i],NULL,&sum,a);
    }

    int globalSum = 0;
    for(int i = 0 ; i < 2 ;i++)
    {
        int* r;
        pthread_join(th[i],(void**)&r);
        globalSum += *r;
        free(r);
    }
    printf("Sum is %d\n",globalSum);

}