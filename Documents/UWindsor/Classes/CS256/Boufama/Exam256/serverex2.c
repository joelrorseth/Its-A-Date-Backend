#include <linux/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

void child(int sd);

int
main(int argc, char *argv[])
{
    int sd, client=0, portNumber;
    socklen_t len;
    // create socket structure to assign variables to socket with bind
    struct sockaddr_in servAdd;
    
    if (argc !=2){
        printf("Call Model: %s <Port#>\n", argv[0]);
        exit(0);
    }
    // create the socket- has no info
    if ((sd=socket(AF_INET, SOCK_STREAM, 0)<0)){
        fprintf(stderr, "Cannot Create socket\n");
        exit(1);
    }
    // give socket structure values
    servAdd.sin_family=AF_INET;
    servAdd.sin_addr.s_addr=htonl(INADDR_ANY);
    sscanf(argv[1], "%d", &portNumber);
    servAdd.sin_port = htons((uint16_t)portNumber);
    // assign the structure values to the socket
    bind(sd, (struct sockaddr*)&servAdd, sizeof(servAdd));
    listen(sd, 5);
    
    while(1){
        printf("Waiting for next client...\n");
        client = accept(sd,NULL, NULL);
        printf("Got a client\n");
        if(!fork())
            child(client);
        close(client);
        wait(&status);
    }
}


void child(int sd){
    char message[255];
    
    while(1){
        fprintf(stderr, "Enter line to send to client\n");
        fgets(message, 254, stdin);
        write(sd, message, strlen(message)+1);
        
        if(!read(sd, message, 255)){
            close(sd);
            fprintf(stderr, "Bye, client dead, wait for new client\n");
            exit(0);
        }
        fprintf(stderr, "Client sent back: %s\n", message);
    }
}
