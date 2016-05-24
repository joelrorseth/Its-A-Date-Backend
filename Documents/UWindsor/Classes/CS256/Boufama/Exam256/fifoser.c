//
//  fifoser.c
//  
//
//  Created by Ryan Pearson on 04-13-2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


void child(pid_t client);

int
main(int argc, char *argv[])
{
    int fd, status;
    char ch;
    pid_t pid;
    
    unlink("./server");
    if((mkfifo("./server", 0777))<0){
        fprintf(stderr, "fifo error\n");
        exit(1);
    }
    
    while (1) {
        fprintf(stderr, "Waiting for client\n");
        fd=open("./server", O_RDONLY);
        fprintf(stderr, "Have client!\n");
        read(fd, &pid, sizeof(pid_t));
        fprintf(stderr, "%d has arrived.\n", pid);
        if (fork()==0) {
            close(fd);
            child(pid);
        }
        else
            waitpid(0, &status, WNOHANG);
    }
}

void child(pid_t pid){
    char fifoname[100];
    char newline='\n';
    int fd, i;
    
    sprintf(fifoname, "./fifo%d", pid);
    mkfifo(fifoname, O_WRONLY);
    
    for(i=0;i<10;i++){
        write(fd, fifoname, strlen(fifoname));
        sleep(1);
        write(fd,&newline,1);
    }
    close(fd);
    unlink(fifoname);
    exit(0);
}