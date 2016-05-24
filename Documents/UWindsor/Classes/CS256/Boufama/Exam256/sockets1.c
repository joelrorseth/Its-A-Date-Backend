//
//  sockets1.c
//  Created by Ryan Pearson on 04-09-2014.
//

#include <stdio.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int
main(int argc, char *argv[]){
    
    char * myTime;
    time_t currentUnixTime;
    int sd, client, portNumber;
    socklen_t len;
    struct sockaddr_in6 servAdd;
    
    if (argc!=2){
        fprintf(stderr, "Call model: %s <Port#>\n", argv[0]);
        exit(0);
    }
    if ((sd=socket(AF_INET6, SOCK_STREAM, 0))<0) {
        fprintf(stderr, "Could not create socket\n");
        exit(1);
    }
    
    servAdd.sin6_family=AF_INET6;
    //servAdd.sin6_addr.s6_addr= htonl(INADDR_ANY);
    inet_pton(AF_INET6, INADDR_ANY, &servAdd.sin6_addr);
    sscanf(argv[1], "%d", &portNumber);
    servAdd.sin6_port=htons((uint16_t)portNumber);
    
    bind(sd, (struct sockaddr *) &servAdd, sizeof(servAdd));
    listen(sd, 5);
    
    while(1){
        client=accept(sd, (struct sockaddr*)NULL, NULL);
        printf("Got a date/time request\n");
        currentUnixTime = time(NULL);
        myTime = ctime(&currentUnixTime);
        write(client, myTime, strlen(myTime) +1);
        close(client);
        printf("Message sent\n");
    }
    
    return 0;
}