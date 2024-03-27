#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc,char const * argv[])
{
	int fd[2],fd1[2];
	pipe(fd);
	pipe(fd1);
	pid_t id = fork();
	if (id == 0){
		char arr[10];
		read(fd[0],(void*)arr,10);
		printf("\nChild1 proccess: %d\n",id);
		printf("\nMessage from parent in child1: %s\n",arr);
	}
	else{
		write(fd[1],"Taaha\0",6);
		write(fd1[1],"Hussain\0",8);
		pid_t id1 = fork();
		if(id1 == 0){
			char pak[10];
			read(fd1[0],(void*)pak,10);
			printf("\nChild2 proccess: %d\n",id1);
			printf("\nMessage from parent in child2: %s\n",pak);
		}
		
	}
	
	
	
}
