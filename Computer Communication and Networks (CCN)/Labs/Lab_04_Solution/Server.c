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

#define PORT 8092
#define MAXLINE 1024 

// Driver code 
int main() 
{ 
	int sockfd; 
	char hello[50] = "Hello from server side"; 
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
	if ((listen(sockfd, 5)) == 0) 
	{
	        printf("Listen accept...\n");
    	}
	else
	{
        printf("Server listening failed..\n");
		exit(0);
	}
  
    // Accept the data packet from client and verification
	char clistr[100]={};
	char genericstr[30]="message: ";
	char waiting[30]="Waiting for new client.... ";
	while(1)
	{
				int len = sizeof(cliaddr);
				int newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
				int x=fork();
				if(x==0)
				{
					close(sockfd);
					while(1)
					{
							printf("Client with Port: %d\n", ntohs(cliaddr.sin_port));
							write(1,(void *)genericstr,sizeof(genericstr));
							bzero(clistr,100);
							read(newsockfd, (void *)clistr,sizeof(clistr)); 
							write(1,(void *)clistr,sizeof(clistr));
							printf("\n");
							write(newsockfd,(void *)hello,sizeof(hello));
							if(strcmp(clistr,"exit")==0)
							{
								close(newsockfd);
								break;
							}
							else
								continue;
					}
					exit(1);
				}
	}
	printf("Client ended chat\n");
	return 0;
} 
