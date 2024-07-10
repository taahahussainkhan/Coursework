#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[]){
    int sockfd,length,fromlen,n;
    struct sockaddr_in server, from;
    char buffer[1024];

    if(argc < 2)
    {
        fprintf(stderr,"No Port Error\n");
        exit(0);
    }
    //AF Address Family
    if((sockfd = sock(AF_INET, SOCK_DGRAM,0)) < 0)
    {
        perror("Failed!");
    }
    length = sizeof(server);
    bzero(&server, length); // Makes the server empty and make it zero

    // Now Cleaning
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr*)&server, length) < 0)
    {
        perror("Binding Failed!");
    }

    fromlen = sizeof(sockaddr_in);

    while(1){
        n = recvfrom(sockfd, buffer, 1024,0,(struct sockaddr*)&from, &fromlen);
        if(n < 0){
            perror("Error");
        }
        write(1, "Recieved a datagram", 30);
        write(1, buffer,n);
        n = sendto(sockfd, "Recieved your message\n", 22,0,(struct sockaddr*)&from, &fromlen);
        if(n < 0){
            perror("Error");
        }
    }




}



