//t9.c (Get an integer size via cmd line argument 
//then create two integer arrays of that size and 
//get input in those arrays from user
//finally create size number of threads for addition of two location of the arrays

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
#include <unistd.h>

void * MyThreadFunc(void *);
int *arr1;
int *arr2;
int *result;
int main(int argc, char* argv[])
{
   if(argc != 2){
      printf("Invalid arguments, must pass one integer value...\n");
      exit(1);
   }
   int ctr = atoi(argv[1]);
   //create two integer arrays each of size ctr
   arr1   = (int*)malloc(sizeof(int)*ctr);
   arr2   = (int*)malloc(sizeof(int)*ctr);
   result = (int*)malloc(sizeof(int)*ctr);
   int i;






   //get input from user
   printf("\nEnter  %d values for array1\n",ctr);
   for(i=0;i<ctr;i++)
      scanf("%d",&arr1[i]);

   printf("\nEnter  %d values for array2\n",ctr);
   for(i=0;i<ctr;i++)
      scanf("%d",&arr2[i]);








   pthread_t* tid =  (pthread_t*)malloc(sizeof(pthread_t)*ctr);
   for(i=0;i<ctr;i++){

      int res = pthread_create(&tid[i], NULL, &MyThreadFunc, (void*)i);
      if (res != 0){
         perror("Thread creation failed");
         exit(EXIT_FAILURE);
      }
   }






   for(i=0;i<ctr;i++)
      pthread_join(tid[i], NULL);





   
   printf("\nI am main thread. All child threads have completed their computation.\nNow I will diaplay the results: \n");
   sleep(5);
   printf("Sum of the two arrays = \n");

   for(i=0; i<ctr; i++)
	printf("%d\n",result[i]);
   return 0;
}

void * MyThreadFunc(void * args)
{
   int n = (int)args;
   result[n] = arr1[n] + arr2[n];
   pthread_exit(NULL);
}
