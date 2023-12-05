#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char const * argv[])
{
    int fd[2];
    pipe(fd);
    if(fork() == 0)
    {
        char arr[10];
        read(fd[0],arr,10);
        printf("%s",arr);
    }
    else {
        write(fd[1],"Taaha\0",5);
        wait(NULL);
    }
}