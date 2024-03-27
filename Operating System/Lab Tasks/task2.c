#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc,char const* argv[])
{
int p1[2],c1[2],p2[2],c2[2];
	pipe(p1);
	pipe(c1);
	pipe(p2);
	pipe(c2);
	int size = argc-1;
	int* arr = (int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++){
	arr[i] = atoi(argv[i+1]);
	}
	
	pid_t sumC = fork();
	if( sumC == 0){
	int my[10];
		read(p1[0],my,sizeof(int)*size);
		printf("\nArray in child 1: \n");
		for(int i=0;i<size;i++){
			printf(" %d",my[i]);
		}
		int sum = 0;
		for(int i=0;i<size;i++){
			sum += my[i];
		}
		printf("\nSum in child1:  %d\n",sum);
		write(c1[1],&sum,sizeof(int));
	}
	else{
	int my1[10],location =0;
	int s,m;

	write(p1[1],arr,sizeof(int)*size);
	
	read(c1[0],&s,sizeof(int));
	
		printf("\nSum in parent:  %d\n",s);
		
		pid_t minC = fork();
		if( minC == 0){
		read(p2[0],my1,sizeof(int)*size);
		printf("\nArray in child 2: \n");
		for(int i=0;i<size;i++){
			printf(" %d",my1[i]);
		}
		  for (int c = 1; c < size; c++)
   			{ if (my1[c] < my1[location])
      				{location = c;}
      			}
      		int min = my1[location];
      		printf("\nMinimum in child2:  %d\n",min);
		write(c2[1],&min,sizeof(int));
		}
		else{
		write(p2[1],arr,sizeof(int)*size);
		read(c2[0],&m,sizeof(int));
		printf("\nMin in parent:  %d\n",m);
		}
	
	}
}

