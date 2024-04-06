// Server side implementation of TCP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <windows.h>


#define PORT     8080
#define MAXLINE 1024

// Driver code
int main() {
    int sockfd, newfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
    int len;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    len = sizeof(cliaddr);
    if ((newfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    int n;
    n = recv(newfd, buffer, MAXLINE, 0);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    send(newfd, hello, strlen(hello), 0);
    printf("Hello message sent.\n");
    close(newfd);
    close(sockfd);

    return 0;
}
