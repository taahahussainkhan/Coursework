// Client side implementation of TCP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT     8080
#define MAXLINE 1024

// Driver code
int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    int n;
    send(sockfd, hello, strlen(hello), 0);
    printf("Hello message sent.\n");

    n = recv(sockfd, buffer, MAXLINE, 0);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);

    close(sockfd);

    return 0;
}
