//
//  Server10.c
//  Created by Dr Boufama on 03-30-2014/ modified by Ryan Pearson
//

#include <linux/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


void doClient(int);

int main(int argc, char *argv[]){
    int sd, portNumber, client;
    socklen_t len;
    struct sockaddr_in servAdd;
    
    if(argc != 2){
        printf("Call model: %s <Port Number>\n", argv[0]);
        exit(0);
    }
    
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        fprintf(stderr, "Cannot create socket\n");
        exit(1);
    }
    servAdd.sin_family = AF_INET;
    servAdd.sin_addr.s_addr = htonl(INADDR_ANY);
    sscanf(argv[1], "%d", &portNumber);
    servAdd.sin_port = htons((uint16_t)portNumber);
    
    bind(sd, (struct sockaddr *) &servAdd, sizeof(servAdd));
    listen(sd, 5);
    
    while(1){
        printf("Waiting for next client...\n");
        //doClient(accept(sd,NULL, NULL));
        client=accept(sd, (struct sockaddr*)NULL, NULL);
        printf("Client received.\n");
        if(!fork())
            doClient(client);
        close(client);
    }
}
void doClient(int fd){
    char name[100], end='\0', com[100];
    int backup, i=0;
    while(i<100)
        name[i++]='\0';
    i=0;
    
    backup=dup(STDOUT_FILENO);  // save STDOUT
    // redirect STDOUT to fd
    dup2(fd, STDOUT_FILENO);
    while(1){
        do{
            read(fd, &name[i++], 1);
        }while(name[i-1] != '\0');
        if(strcmp(name, "bye\n") == 0){
            fprintf(stderr, "Thanks for playing\n");
            close(fd);
            dup2(backup, STDOUT_FILENO);
            return;
        }
        fprintf(stderr, "Executing for client: %s", name);
        // system allows u to use a command string within program
        if(system(name)==127)
            write(fd, "Invalid command\n", 17);
        // indicate end of file
        write(fd, &end, 1);
        while(i!=0)
            name[i--]='\0';
        i=0;
    }
    close(fd);
    dup2(backup, STDOUT_FILENO); // restore
}
