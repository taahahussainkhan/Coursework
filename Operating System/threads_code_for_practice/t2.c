//t2.c
/*
Main thread pass a string to the thread which displays that string and returns
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * MyThreadFunc(void *);

int main()
{
  char * msg = "Hello Students...";
   pthread_t tid;
   int error = pthread_create(&tid, NULL, &MyThreadFunc, (void*)msg);
   if (error != 0 ){
      printf("Thread creation error\n");
      exit(1);
   }
   //sleep(2);
   pthread_join(tid, NULL);
   printf("Exiting the main function...\n");
   return 0;

}

void * MyThreadFunc(void * args)
{
   char * message = (char*) args;
   printf("I am child thread, and the message passed to me is: %s\n", message);
   pthread_exit(NULL);//return NULL;
}
