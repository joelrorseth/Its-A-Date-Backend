//
//  Assign5Server.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

/****
 This C program is for a server in a
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
    int fd;
    int client;
    int status;
    
    unlink("/home/rahmanq/test/server_rahmanq"); /* delete any previous FIFO */
    if(mkfifo("/home/rahmanq/test/server_rahmanq", 0777)) /*create a new FIFO*/
    {
        perror("FIFO, main");
        exit(1);
    }
    
    while(1) //wait for a client to be connected
    {
        fd = open("/home/rahmanq/test/server_rahmanq", O_RDONLY);
        if(read(fd, &client, sizeof(int))) //a client is connected
        {
            printf("Client %d connected...\n", client);
            int cpid;
            if((cpid = fork()) < 0) //create a child process
            {
                perror("fork");
                exit(1);
            }
            if(!cpid) //this is the child
            {
                char ch, fifo1[125], fifo2[125];
                sprintf(fifo1, "/home/rahmanq/test/fifo_%d_1",  client);
                sprintf(fifo2, "/home/rahmanq/test/fifo_%d_2",  client);
                
                if(mkfifo(fifo1, 0777) || mkfifo(fifo2, 0777)) //make two fifo's
                {
                    perror("fifo in main");
                    exit(1);
                }
                
                int rfd, wfd, fSize;
                char fName[125], buffer[256];
                FILE *fp;
                
                rfd = open(fifo2, O_RDONLY);
				read(rfd, buffer, 255); // read the file name and size
                
				sscanf(buffer, "%s%d", fName, &fSize); //separate file name and its size
                
				if((fp = fopen(fName, "w")) == NULL) //create a new file with the file name
				{
					perror("open file");
					exit(2);
				}
                
				wfd = open(fifo1, O_WRONLY);
				write(wfd, fName, strlen(fName)+1); //send file creation confirmation
				close(wfd);
                
				rfd = open(fifo2, O_RDONLY); //read the file contents and write it into the new file
				while(read(rfd, &ch, 1) == 1)
					fputc(ch, fp);
				fclose(fp);
                
				char message[] = "Upload complete!";
				wfd = open(fifo1, O_WRONLY);
				write(wfd, message, strlen(message)+1); //send upload confirmation message
				close(wfd);
            }
            
            else //this is the parent
            {
				waitpid(cpid, &status, WNOHANG); //wait for this child to be terminated.
				printf("Client %d disconnected\n", client);
			}
            
        }
        
        
    }
    
}
