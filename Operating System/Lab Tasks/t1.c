#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char const * argv[])
{
    int size = argc - 1;
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }
    for(int i = 0 ; i < size ; i++)
    {
       printf(" %d",arr[i]);
    }
    pid_t pid = fork();
    if(pid == 0)
    {
        printf ( "Child process 1 : \n" );
        int sum = 0,avg = 0;
        for(int i = 0 ;i < size ; i++ ){
            sum += arr[i];
        }    
        avg = sum / size;
        printf("\nAvg = %d\n",avg);
    }
    else {
        pid_t pid2 = fork();
        if( pid2 == 0)
        {
        printf ( "Child process 2: \n" );
        int sum = 0,avg = 0;
        for(int i = 0 ;i < size ; i++ ){
            sum += arr[i];
        }    
        printf("\nSum = %d\n",sum);
        }
    }
}