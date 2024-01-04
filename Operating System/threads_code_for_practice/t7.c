/*
t7.c

*/
#include <sys/types.h>
#include <linux/unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define NUM_THREADS 5

void * MyThreadFunc(void * arg);
int main()
{
   
   pthread_t tid[NUM_THREADS];
   int i;

   for(i=0; i < NUM_THREADS; i++){
      pthread_create(&tid[i], NULL, MyThreadFunc, (void *)&i); 
      pthread_join(tid[i], NULL); 
}
   printf("main(): Reporting that all child threads have termineted\n");
   exit(0);
}

void * MyThreadFunc(void * arg)
{
   int i = *((int*)arg);
   printf("I am child thread number %d \n", i);
   pthread_exit(NULL);
}
