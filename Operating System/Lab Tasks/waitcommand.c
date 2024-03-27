#include<stdio.h>  
#include<unistd.h> // fork() is defined here
#include<sys/types.h> // pid_t is defined here
#include<stdlib.h> // exit() is defined here
#include<wait.h> // wait() is defined here
int main(int argc,char const * argv[])
{
    int id = fork();
    int n = 0;
    if (id == 0)
    {
      //  printf("Child process! \n");
      n=1;
    }
    else{
       // printf("Parent process! \n");
       n = 6;
    }
    if(id != 0)
    {
        wait(NULL); // wait for child process to finish
    }
    for(int i = n;i< n +5;i++)
    {
        printf(" %d",i); // print 1 to 5 if child process
        // print 6 to 10 if parent process
    }
    
}