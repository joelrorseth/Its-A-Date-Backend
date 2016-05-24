//
//  fifocli.c
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

int
main(int argc, char *argv[])
{
    char fifoname[100];
    int fd;
    char ch;
    pid_t pid;
    char client[10];
    
    while ((fd=open("./server", O_WRONLY))==-1) {
        fprintf(stderr, "trying to connect\n");
        sleep(1);
    }
    
    pid = getpid();
    write(fd, &pid, sizeof(pid_t));
    close(fd);
    
    sprintf(fifoname, "./fifo%d", pid);
    sleep(2);
    
    fd=open(fifoname, O_RDONLY);
    while ((read(fd, &ch, 1))==1) {
        fprintf(stderr, "%c", ch);
    }
    close(fd);
}