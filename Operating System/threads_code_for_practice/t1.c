//t1.c
/*main thread creates a child threadthat prints Xs in an infinite loop, while the main thread prints Os in an infinite loop. Both executes concurrently. Press <CTRL+C> to quit
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <errno.h> 
void * MyThreadFunc(void *);

int main()
{
   pthread_t tid;
  int error = pthread_create(&tid, NULL, &MyThreadFunc, NULL);
  if (error != 0){
        printf("Error in creating thread\n"); 
        exit(1);
  }
   while(1)
     putchar('o');// putc('o',stdout);
   return 0;
}

void * MyThreadFunc(void * nothing)
{
   
   while (1)
      putc('x',stdout);// putchar('x');
   pthread_exit(NULL);//return NULL;

}
