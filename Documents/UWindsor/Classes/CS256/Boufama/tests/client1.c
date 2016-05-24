//
//  client1.c
//  Created by Ryan Pearson on 04-09-2014.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

int
main(int argc, char *argv[])
{
    char message[100];
    int server, portNumber;
    socklen_t len;
    struct sockaddr_in6 servAdd;
    
    if (argc!=3) {
        printf("Call Model: %s <IP> <Port#>\n", argv[0]);
        exit(0);
    }
    if ((server=socket(AF_INET6, SOCK_STREAM, 0))<0) {
        fprintf(stderr, "Can't create socket\n");
        exit(1);
    }
    
    servAdd.sin6_family= AF_INET6;
    sscanf(argv[2], "%d", &portNumber);
    servAdd.sin6_port = htons((uint16_t)portNumber);
    inet_pton(AF_INET6, "fe80::218:51ff:fef0:7d46", &servAdd.sin6_addr);
    
//    if (inet_pton(AF_INET6, argv[1], &servAdd.sin6_addr)<0) {
//        fprintf(stderr, " inet_pton() has failed\n");
//        exit(2);
//    }
    
    if (connect(server, (struct sockaddr *) &servAdd, sizeof(servAdd)) <0) {
        fprintf(stderr, "connect() failed, exiting\n");
        exit(3);
    }
    
    if (read(server, message, 100)<0) {
        fprintf(stderr, "read() error\n");
        exit(3);
    }
    
    fprintf(stderr, "%s\n", message);
    exit(0);
}
