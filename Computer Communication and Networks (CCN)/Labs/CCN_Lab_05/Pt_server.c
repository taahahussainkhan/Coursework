// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <pthread.h>
#include <netinet/in.h> 

#define PORT	 5010
#define MAXLINE 1024

char* wait_new_client = "\nWaiting for Client\n";


char buffer[MAXLINE];
int Index=0;
//char buffer1[MAXLINE];


struct Data
{
	int NewFD;
	int ClientPort;
	char* ClientIP;
	//int curret_newfd;
};

struct Data ClientList[50];

void * Broadcast_Message(void * ptr){

	struct Data *ClientInfo = (struct Data *)ptr;
	int port=ClientInfo->ClientPort;
	char buf[1024];
	strcpy(buf,buffer);
	//sprintf(buf,"Client with %d : %s",port,buffer);
	send(ClientInfo->NewFD, (const char *)buf, strlen(buf), 0); 
}

void* Communication(void* Info)
{
	struct Data *ClientInfo = (struct Data *)Info;
	
	while(1){
		memset(&buffer, 0, sizeof(buffer)); 
		int n = recv(ClientInfo->NewFD, buffer, MAXLINE, 0);
		buffer[n] = '\0';
		char buffer1[1024];
		if(strcmp(buffer, "exit") == 0){

			for(int i = 0; i < Index; i++){

				if(ClientList[i].NewFD == ClientInfo->NewFD){
					close(ClientList[i].NewFD);
					ClientList[i].NewFD = -1;
					break;
				}

			}
			
			break;
		}
		sprintf(buffer1,"Client with %d : %s",ClientInfo->ClientPort,buffer);
		strcpy(buffer,buffer1);
		//printf("%s",buffer);
		for(int i = 0; i < Index; i++){

			if(ClientList[i].NewFD != -1 && ClientList[i].NewFD != ClientInfo->NewFD){
				pthread_t th;
				pthread_create(&th, NULL, Broadcast_Message, (void *)&ClientList[i]);
				pthread_join(th, NULL);
			}

		}


	}

	
	
}

int main() { 
	int sockfd;
	struct sockaddr_in servaddr, cliaddr; 
	int new_sockfd;
	pthread_t tid;
	
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
	
	listen(sockfd,5);	// set a backlog for server

	while(1)
	{
		int len, n; 
		write(1,wait_new_client,strlen(wait_new_client));
		int clientLength = sizeof(cliaddr);
		new_sockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clientLength);	// accept request from TCP client		
		int port = ntohs(cliaddr.sin_port);
		char* cIP = inet_ntoa(cliaddr.sin_addr);
		
		char buf[100];

		sprintf(buf, "New Client connected with IP %s and Port %d", cIP, port);

		for(int i = 0; i < Index; i++){

			send(ClientList[i].NewFD, buf, strlen(buf), 0);

		}


		ClientList[Index].NewFD = new_sockfd;
		ClientList[Index].ClientPort = port;
		ClientList[Index].ClientIP = cIP;
		
		pthread_create(&tid,NULL,Communication,(void*)&ClientList[Index]);
		Index++;
		
	}
	
	pthread_exit(NULL);
	return 0; 
} 

