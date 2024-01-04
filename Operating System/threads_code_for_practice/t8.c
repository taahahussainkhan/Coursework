//t9.c (creat a child thread and pass it n that is received via cmd line
// the thread compute nth prime number and returns it to main
// main thread displays the result)
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
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
   unsigned long long *thread_result = (unsigned long long*)exit_status;
   printf("\nI am main thread. The %dth prime number as returned by child thread is: %d\n",args,thread_result);
   return 0;
}

void * MyThreadFunc(void * args)
{
   int n = *((int*)args);
   unsigned long *candidate = (unsigned long*)malloc(sizeof(unsigned long));
   *candidate = 2;
  // int candidate = 2;
   while(1){
      unsigned long long factor;
      unsigned long is_prime = 1;
//test primality by successive division
      for (factor = 2; factor < *candidate ; ++factor){
         if((*candidate)%2 == 0){is_prime=0; break;}
         if((*candidate) % factor == 0){
            is_prime = 0;
            break;
         }
      }
         //is this the prime number we are looking for?
         if(is_prime){
            if(--n == 0){
             //    printf("%d\n",*candidate); 
                // return (void*)*candidate;
                pthread_exit((void*)(*candidate));
                }
         }
         ++(*candidate);
      }
return NULL;
}

