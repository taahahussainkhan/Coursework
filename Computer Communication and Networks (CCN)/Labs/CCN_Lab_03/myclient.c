#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main(){
    int sockfd;
    if((sockfd = sock(AF_INET, SOCK_STREAM, 0)) < 0)
    {    perror("FAILED");
        exit(EXIT_FAILURE);
    }
    char buffer[MAXLINE];

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin.addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 

    int n = recv(sockfd, (char*)buffer, MAXLINE, 0);

    



}