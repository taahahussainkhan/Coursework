//t4.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

void * MyThreadFunc(void *);

int main()
{
  int sleepTime = 10;
   pthread_t tid;
   pthread_create(&tid, NULL, &MyThreadFunc, (void*)&sleepTime); 
   sleep(5);
   printf("Concurrent executing; inside main thread...\n");
   pthread_join(tid, NULL);
   printf("I am main thread Bye...\n");
   return 0;

}

void * MyThreadFunc(void * args)
{
   int sTime = *((int*) args);
   printf("I am child thread and I will sleep for %i seconds\n", sTime);
   printf("Sleeping.... zeeeeeeeeeeeeeeeeeeee\n");
   sleep(sTime);
   printf("I am child thread and I am awake now .... Good Bye!\n");
   return NULL;
}
