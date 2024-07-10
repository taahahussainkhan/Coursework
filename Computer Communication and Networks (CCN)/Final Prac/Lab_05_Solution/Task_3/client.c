// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT 8381
#define MAXLINE 1024
// Driver code 
int main() 
{ 
	int sockfd,valread; 
	char buffer[MAXLINE]; 
	char input[20];
	struct sockaddr_in servaddr; 

	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	
	int n, len; 
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    while(1)
    {
    valread = recv( sockfd , buffer, 1024,0);
    buffer[valread] = '\0'; 
    printf("%s\n", buffer);
    printf("Enter file name from above shown files you want to open\n");
   	scanf("%[^\n]",input);
	send(sockfd , input , strlen(input) , 0 ); 
   	printf("File Name sent\n"); 
   	valread = recv( sockfd , buffer, 1024,0);
    buffer[valread] = '\0';
	printf("File data received from server: %s\n", buffer);
	//char data[30];
	//strcpy(data,buffer);
	FILE *fptr;
	//data[valread] = '\0';
	fptr = fopen("serverData.txt","w");
	fputs(buffer,fptr);
	fputs("\n",fptr);
	fclose(fptr);
	char  choice[20]={0};
    scanf("%s",choice);
    char C1[10]={"yes"};
    char C2[10]={"no"};  
    if(strcmp(choice,C1)==0)
    {
       send(sockfd , choice , strlen(choice) , 0 );      
    }
    if(strcmp(choice,C2)==0)
   	{
       send(sockfd , choice , strlen(choice) , 0 );
       break;
    }
}
close(sockfd);
return 0;
	//char ch;
	/*while(ch!='n')
	{
		valread = recv( sockfd , buffer, 1024,0);
    	buffer[valread] = '\0';
    	//printf("%s\n",buffer);
    	scanf("%c",&ch);
   printf("%c\n", ch);
    	if(ch=='y')
    	{
    		printf("Enter file name to download\n");
    		scanf("%[^\n]",input);
    		send(sockfd , input , strlen(input) , 0 );
    		valread = recv( sockfd , buffer, 1024,0);
    		buffer[valread] = '\0';
			printf("File data received from server: %s\n", buffer);
			FILE *fptr;
			fptr = fopen("serverData.txt","w");
			fputs(buffer,fptr);
			fputs("\n",fptr);
			fclose(fptr);
    	}
    	else
    	{
    		break;
    	}
	}*/
	 
	return 0; 
} 
