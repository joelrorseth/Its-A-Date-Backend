#include <linux/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int
main(int argc, char *argv[])
{
    char message[255];
    int  server, portNumber;
    socklen_t len;
    struct sockaddr_in servAdd;
    
    // check for proper function engage
    if(argc!=3){
        printf("call model: %s <IP> <Port #>\n", argv[0]);
        exit(0);
    }
    
    // ensure you can create socket
    if((server=socket(AF_INET, SOCK_STREAM, 0))<0){
        fprintf(stderr, "Can't create socket\n");
        exit(1);
    }
    
    // assign values to struct sockaddr_in
    servAdd.sin_family=AF_INET;
    sscanf(argv[2], "%d", &portNumber);
    servAdd.sin_port = htons((uint16_t)portNumber);
    
    // assign internet address to structure
    if (inet_pton(AF_INET, argv[1], &servAdd.sin_addr)<0){
        fprintf(stderr, "inet_pton fail\n");
        exit(2);
    }
    
    // initiate the connection to the server
    if(connect(server, (struct sockaddr *) &servAdd, sizeof(servAdd))<0){
        fprintf(stderr, "connect fail\n");
        exit(3);
    }
    
    while(1){
        if(read(server, message, 255)<0){
            fprintf(stderr, "read error\n");
            exit(3);
        }
        fprintf(stderr, "Server's message: %s\n", message);
        fprintf(stderr, "Enter $ to quit, or type message: ");
        fgets(message, 254, stdin);
        if(message[0] == '$'){
            close(server);
            exit(0);
        }
        write(server, message, strlen(message)+1);
    }
}