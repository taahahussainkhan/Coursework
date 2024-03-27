#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc,char const *argv[]){
	int size = argc-1;
	int *arr = (int*)malloc(size*sizeof(int));
	for(int i = 0 ; i < size ;i++ ){
	arr[i] = atoi(argv[i+1]);
	}
	for(int i = 0 ; i < size ;i++ ){
	printf(" %d",arr[i]);
	}
	printf("\n");
	pid_t pid = fork();
	if(pid == 0) {
	int sum = 0,avg=0;
	for(int i=0 ; i< size; i++)
	{
	sum += arr[i];
	}	
	avg=sum/size;
	printf("Child 1: %d \n",pid);
	printf("Average from Child 1: %d",avg);
	printf("\n");
	}
	
  	else {
  	pid_t pid2 = fork();
  	if(pid2 == 0){
  	int sum = 0;
  	for(int i=0 ; i< size; i++)
	{
	sum += arr[i];
	}
	printf("Child 2: %d \n",pid2);
	printf("Average from Child 2: %d",sum);
	printf("\n");
	}
	if(pid2 != 0){
	printf("Parent 2: %d \n",pid2);
  	wait(NULL);
  	}
  	}
  	if(pid != 0){
  	printf("Parent 1: %d \n",pid);
  	wait(NULL);
  	}
}


























