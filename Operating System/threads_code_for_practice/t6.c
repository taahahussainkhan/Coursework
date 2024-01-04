/*
t6.c
main thread and child thread shares a global character array. The main thread creates a child thread and pass it the 
char array. The child thread displays that message, then changes that global char array and return a string. 
The main thread displays that string and also the changed contents of the global char array
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void * MyThreadFunc(void * arg);
char message[] = "Hello Students";
int main()
{
   pthread_t tid;
   void * thread_result;
   pthread_create(&tid, NULL, MyThreadFunc, (void*)message); 
   printf("I am main thread, waiting for child thread to finish...\n");
   void* exit_status;
   pthread_join(tid, &exit_status);


   printf("\nThe joined thread returned:  %s\n", (char*)exit_status);
   printf("Child Thread has also changed the message to %s\n",message);
   exit(EXIT_SUCCESS);
}

void * MyThreadFunc(void * arg)
{
   char * msg = (char *) arg;
   printf("I am child thread, and I received the message %s\n",msg);
   sleep(10);
   strcpy(message, "Bye Students");//changing the global variable
   pthread_exit("Thank you for the CPU time.\n");
}
