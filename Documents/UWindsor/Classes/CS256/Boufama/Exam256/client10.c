//  client10.c
//  Created by Ryan Pearson on 03-30-2014.

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]){
    char ch, name[100];
    int sd, i=0, portNumber;
    struct sockaddr_in servAdd;
    
    if(argc != 3){
        printf("Call model: %s <IP Address> <Port Number>\n", argv[0]);
        exit(0);
    }
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        fprintf(stderr, "Cannot create socket\n");
        exit(1);
    }
    servAdd.sin_family = AF_INET;
    sscanf(argv[2], "%d", &portNumber);
    servAdd.sin_port = htons((uint16_t)portNumber);
    
    inet_pton(AF_INET, argv[1], &servAdd.sin_addr);
    
    connect(sd,(struct sockaddr *)&servAdd, sizeof(servAdd));
    
    do{
        fprintf(stderr, "Enter the unix command to execute(\"bye\" to exit)> ");
        // allows you to get command with options
        fgets(name, 100, stdin);
        //scanf("%s", name);
        write(sd, name, strlen(name)+1); // send to the server the fileName
        if (strcmp(name, "bye\n")==0) {
            printf("Thanks for playing\n");
            exit(0);
        }
        do{                // reads the contents of the file and displays it
            read(sd, &ch, 1);
            fprintf(stderr, "%c", ch);
        }while(ch != '\0');
        i = strlen(name);
        while(i>=0)
            name[i--]='\0';
    }    while (strcmp(name, "exit")!=0);
    
    close(sd);
    exit(0);
}
