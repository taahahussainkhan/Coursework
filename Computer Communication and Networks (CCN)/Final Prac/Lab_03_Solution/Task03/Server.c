// Server side implementation of TCP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <netdb.h>
#include<sys/file.h>
#include<fcntl.h>

#define PORT 8015
#define MAXLINE 1024 

// Driver code 
int main() 
{ 
	int sockfd; 
	char buffer[MAXLINE]; 
	char *hello = "Hello from server"; 
	struct sockaddr_in servaddr, cliaddr; 
	
	// Creating socket file descriptor 
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
	if ( bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	}
	else
 	       printf("Socket successfully binded..\n");
	if ((listen(sockfd, 1)) == 0) 
	{
	        printf("Listen accept...\n");
    	}
	else
	{
        printf("Server listening failed..\n");
		exit(0);
	}
	   int len = sizeof(cliaddr);
  
    // Accept the data packet from client and verification
	while(1)
	{
				int connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
				if(connfd<0)
				{
					break;
					close(sockfd);
				}
				int n=0;
				bzero(buffer,255);
				n = recvfrom(connfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *) &servaddr, &len); 
				buffer[n] = '\0';
				char filedata[MAXLINE];
				FILE *fin=fopen(buffer,"r");
				if(fin!=NULL)
				{
					fgets(filedata,MAXLINE,fin);
					hello=filedata;
				}
				else
				{
					printf("File not there !");
				}
				send(connfd, (const char *)hello, strlen(hello), 0);
	}
	printf("Client ended chat\n");
	return 0;
} 
