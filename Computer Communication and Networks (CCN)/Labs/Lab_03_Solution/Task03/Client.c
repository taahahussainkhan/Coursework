// Client side implementation of TCP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8015
#define MAXLINE 1024 

// Driver code 
int main() 
{ 
	int sockfd; 
	char buffer[MAXLINE]; 
	char *filename = "text.txt"; 
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
       	printf("Connected with the server...\n");
		printf("Port number is: %d\n",PORT);
		printf("Process id is: %d\n",getpid());
   	}
	else
	{
		printf("connection with the server failed...\n");
		exit(0);
	}
	
	int n, len=sizeof(servaddr); 
	
	sendto(sockfd, (const char *)filename, strlen(filename), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
	printf("filename message sent.\n"); 
		
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *) &servaddr, &len); 
	buffer[n] = '\0'; 
	write(1,buffer,strlen(buffer)); 
	close(sockfd); 
	return 0; 
} 

