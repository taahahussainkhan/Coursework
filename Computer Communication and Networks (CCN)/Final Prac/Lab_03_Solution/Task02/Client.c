// Client side implementation of TCP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8018
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
       	printf("connected with the server...\n");
   	}
	else
	{
		printf("connection with the server failed...\n");
		exit(0);
	}
	char filedata[MAXLINE];
	FILE *fin=fopen(filename,"r");
	if(fin!=NULL)
	{
		fgets(filedata,MAXLINE,fin);
	}
	else
	{
		printf("File not there !");
	}
	for(int i=0;i<strlen(filedata);i++)
	{
		if (filedata[i] >= 'A' && filedata[i] <= 'Z')
		{
     		filedata[i]=filedata[i]+2;
  		} 
   		else if (filedata[i] >= 'a' && filedata[i] <= 'z') 
		{
      		filedata[i]=filedata[i]+3;
   		} 	
  		else if(filedata[i] >= '0' && filedata[i] <= '9')
		{
      		filedata[i]=filedata[i]+1;
		}
	}
	int n, len=sizeof(servaddr); 
	
	sendto(sockfd, (const char *)filedata, strlen(filedata), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
	printf("filename message encrypted sent is: %s\n",filedata); 
		
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *) &servaddr, &len); 
	buffer[n] = '\0'; 
	printf("filename message decrypted and recived from is: %s\n",buffer);
	write(1,buffer,strlen(buffer)); 
	close(sockfd); 
	return 0; 
} 

