//t3.c
/*
Main thread creates two child threads, both threads execute the same function, which receives a pointer to a structure containing the character to be displayed and the count i.e. the number of times to display the character 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
struct mystruct{
   char character;
   int count; 
};
void * MyThreadFunc(void *);

int main()
{
   pthread_t t1_id, t2_id;
   struct mystruct t1_args;
   struct mystruct t2_args;



//create a child thread to print 300 xs
   t1_args.character = 'x';
   t1_args.count = 300;
   int res1 = pthread_create(&t1_id, NULL, &MyThreadFunc, (void*)&t1_args);
   if (res1 != 0){
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
  }







//create a child thread to print 200 os
   t2_args.character = 'o';
   t2_args.count = 200;
   int res2 = pthread_create(&t2_id, NULL, &MyThreadFunc, (void*)&t2_args);
   if (res2 != 0){
      perror("Thread creation failed");
      exit(EXIT_FAILURE);
   }





   pthread_join(t1_id, NULL);
   pthread_join(t2_id, NULL);
   printf("\nI am main thread. Bye!\n");
   return 0;
}







void * MyThreadFunc(void * args)
{
   struct mystruct * p = (struct mystruct*)args;
   int i;
   for (i = 0; i < p->count; i++)
      putc(p->character,stdout);
   return NULL; //pthread_exit(NULL);
}






