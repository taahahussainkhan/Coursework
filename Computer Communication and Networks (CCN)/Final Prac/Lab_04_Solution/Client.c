// Client side implementation of TCP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8092
#define MAXLINE 1024 

// Driver code 
int main() 
{ 
	int sockfd; 
	char buffer[MAXLINE]; 
	char hello[50] = "Hello from client"; 
	struct sockaddr_in	 servaddr; 

	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET,SOCK_STREAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	
	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == 0) 
	{
       	printf("connected with the server...\n");
   	}
	else
	{
		printf("connected with the server failed...\n");
		exit(0);
	}
	char clistr[100]={};
	char serverstr[100]={};
	//printf("Connection accepted from port: %d\n", ntohs(servaddr.sin_port));
	while(1)
    {
        printf("\n Enter the string:");
        scanf("%s",clistr);
        write(sockfd,(void*)clistr,strlen(clistr));
        if(strcmp(clistr,"exit")==0)
			break;
        read(sockfd,(void*)serverstr,sizeof(serverstr));
		printf("server with port: %d ", ntohs(servaddr.sin_port));
        printf("%s\n",serverstr);
    }
	close(sockfd); 
	return 0; 
} 

