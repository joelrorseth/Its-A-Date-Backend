d//
//  clientF2.c
//  
//
//  Created by Ryan Pearson on 04-12-2014.
//
//

#include <stdio.h>

int
main(int argc, char *argv[])
{
    int server, portNumber;
    struct sockaddr_in servAdd;
    
    
    // check for proper args
    if (argc!=3) {
        fprintf(stderr, "Call model: %s <IP> <Port>\n", argv[0]);
        exit(1);
    }
    
    // check if can create socket
    if (server=socket(AF_INET, SOCK_STREAM, 0)) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }
    
    // set struct variables
    servAdd.sin_family=AF_INET;
    sscanf(argv[2], "%d", &portNumber);
    servAdd.sin_port = htons((uint16_t)portNumber);
    if (inet_pton(AF_INET, argv[1], &servAdd.sin_addr)<0) {
        fprintf(stderr, "Address failure\n");
        exit(2);
    }
    
    // connect to server
    if (connect(server, (struct sockaddr*)&servAdd, sizeof(servAdd))<0) {
        fprintf(stderr, "Connection error\n");
        exit(1);
    }
    char *fileName;
    printf("Enter file for upload\n");
    scanf("%s", fileName);
    
    
    
}
