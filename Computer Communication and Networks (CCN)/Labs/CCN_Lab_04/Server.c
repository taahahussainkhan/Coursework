// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() { 
	int sockfd; 
	char buffer[MAXLINE]; 
	char *hello = "Hello Client"; 
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
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	listen (sockfd,5);
	int newfd;
	while(1)
	{
		int len= sizeof(cliaddr), n; 
		newfd= accept(sockfd, (struct sockaddr*) &cliaddr, &len);
		
		int p_id;
		p_id= fork();

		if(p_id == 0)
		{
			close(sockfd);
			n = recv(newfd, (char *)buffer, MAXLINE,0); 
			buffer[n] = '\0'; 
			printf("Client with port %d: %s\n",ntohs(cliaddr.sin_port),  buffer); 
			send(newfd, (const char *)hello, strlen(hello),0); 
			//printf("Hello message sent.\n"); 
			close(newfd);
			exit(-1);
		}
		if(p_id > 0)
		{
			close(newfd);
			//exit();
		}
		else
		{
			printf("Fork call failed\n");
		}
	}
	return 0; 
} 

