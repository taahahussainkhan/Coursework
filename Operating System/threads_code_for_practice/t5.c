//t5.c (Returning data to main thread)
/*
Program receives an integer via command line. The main thread creates a child thread and pass n to it.
 The child thread computes the sum of first n integers and return the value to the main thread
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit

void * MyThreadFunc(void *);

int main(int argc, char* argv[])
{
   if (argc != 2){
      printf("Invalid arguments. Pl enter a single integer value to compute the sum...\n");
      exit(1);
   }
   pthread_t tid;
   int args = atoi(argv[1]);
   int res = pthread_create(&tid, NULL, &MyThreadFunc, (void*)&args);
   if (res != 0){
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }
   void* exit_status;
   pthread_join(tid, &exit_status);
   int thread_result = *((int*)exit_status);
   printf("\nI am main thread. The sum computed and returned by child thread is: %d\n",thread_result);
   return 0;
}

void * MyThreadFunc(void * args)
{
   int n = *((int*)args);
   int i;
   int *result = (int*)malloc(sizeof(int));
  // for (i = 1; i <= n ; i++)
  //   *result = *result + i;
   *result = n * (n + 1)/2;
   //return (void*)result; 
   pthread_exit((void*)result);
}
