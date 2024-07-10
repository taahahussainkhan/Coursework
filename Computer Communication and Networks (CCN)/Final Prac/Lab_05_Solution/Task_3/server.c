#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <pthread.h>
#include <netinet/in.h> 

#define PORT 8381
#define MAXLINE 1024

struct Detail
{
	char ip[INET_ADDRSTRLEN];
	int port_num;	
	int new_socket;
};

void *temp(void *param)
{	
	struct Detail *ptr;
	int new_socket, valread ;
	char buffer[MAXLINE];
	char file_Detail[MAXLINE];
	ptr = (struct Detail *)param;
	char file_name[30];
	printf("IP Address: %s Port: %d\n", ptr->ip,ptr->port_num);
	FILE *fptr;
	if ((fptr = fopen("filenames.txt","r")) == NULL)
	{
       printf("Error! opening file");
   	}
   	else
   	{
   		int file_count;
   		file_count=4;
   		for(int i=0;i<file_count;i++)
   		{
   			fgets(file_name,20,fptr);
   			send(ptr->new_socket , file_name , strlen(file_name) , 0 );
   		}
   		fclose(fptr);
   	}
   		valread = recv( ptr->new_socket ,(char * )buffer,MAXLINE,0);
		buffer[valread] = '\0';
		printf("File name Received from client: %s\n",buffer);
		FILE *fptr2 = fopen(buffer,"r");
		int counter=0;
		char ch;
		while((ch=fgetc(fptr2))!=EOF)
    	{
    		file_Detail[counter] =  ch;
    		counter++;
    	}
    	file_Detail[counter] = '\0';
    	send(ptr->new_socket , file_Detail , strlen(file_Detail) , 0 );
    	fclose(fptr2);
   		char *mes = "\nDo you need to download more files (yes/no)";
   		send(ptr->new_socket , mes , strlen(mes) , 0 );
   		valread = recv( ptr->new_socket ,(char * )buffer,MAXLINE,0);
		buffer[valread] = '\0';
		char Q1[10]={"yes"};
        char Q2[10]={"no"};
        if(strcmp(buffer,Q2)==0)
        {
        	close(ptr->new_socket);
        	pthread_exit(NULL);
        }
}
int main() { 
	int sockfd,new_socket;
	char *hello = "Message Received"; 
	struct sockaddr_in servaddr, cliaddr; 
	
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	if ((listen(sockfd, 5)) != 0)
	{ 
        	printf("Listen failed...\n"); 
        	exit(0); 
    	} 
	else
	{
        	printf("Server listening..\n");
	}
	  

	while(1)
	{
	// Accept the Detail packet from client and verification 
	int len=sizeof(cliaddr), n;
    	new_socket = accept(sockfd, (struct sockaddr *)&cliaddr,&len);
    	if (new_socket < 0)
    	{ 
			printf("Connection failed...\n"); 
			exit(0); 
	    } 
	    else
	    {
	    	pthread_t t_id;
	    	struct Detail my_Detail;
	    	char ip[INET_ADDRSTRLEN];
	    	inet_ntop(AF_INET, &(cliaddr.sin_addr), ip, INET_ADDRSTRLEN); 
			strcpy(my_Detail.ip,ip);
			my_Detail.port_num = ntohs(cliaddr.sin_port);
	    	my_Detail.new_socket = new_socket;
	    	pthread_create(&t_id,NULL,temp,(void *)&my_Detail);
		}

	}
	pthread_exit(NULL); 
} 

