//
//  Assign5Client.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

/****
 This C program is for a client in a
 client-server IPC using FIFO
 
 Written by: Quazi Rahman, Apr. 2013.
 ****/
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd, rfd, wfd;
    int fSize;
    int pid;
    FILE *fp;
    char ch, fName[100], buffer[256], fifo1[125], fifo2[125];;
    
    printf("Enter the name of the file to upload: ");
    scanf(" %s", fName); //get the file name to be uploaded, from the user
    
    if((fp = fopen(fName, "r+")) == NULL)
    {
        perror("File opening");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    fSize = ftell(fp);	//get the size of the file
    rewind(fp);
    sprintf(buffer, "%s\n%d", fName, fSize);
    
    pid = getpid();
    
    fd = open("/home/rahmanq/test/server_rahmanq", O_WRONLY);
    write(fd, &pid, sizeof(int)); //send pid to the server as a request to connect
    close(fd);
    
    sprintf(fifo1, "/home/rahmanq/test/fifo_%d_1",  pid);
    sprintf(fifo2, "/home/rahmanq/test/fifo_%d_2",  pid);
    
    sleep(1);	//To give the server time for creating FIFO's
    
    wfd = open(fifo2, O_WRONLY); //write file name to be uploaded
    write(wfd, buffer, strlen(buffer)+1);
    close(wfd);
    
    rfd = open(fifo1, O_RDONLY); //read file creation confirmation
    read(rfd, buffer, 255);
    
    if(!strcmp(fName, buffer))
    {
        printf("Sending file...\n");
        
        wfd = open(fifo2, O_WRONLY); //send the file contents
        while((ch = fgetc(fp)) != EOF)
            write(wfd, &ch, 1);
        close(wfd);
        
        rfd = open(fifo1, O_RDONLY); //read upload confirmation message
        read(rfd, buffer, 255);
        
        printf("%s\n", buffer); //print upload confirmation message
    }
}
