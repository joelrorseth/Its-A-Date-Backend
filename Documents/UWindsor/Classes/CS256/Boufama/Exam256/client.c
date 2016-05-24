//
//  client.c
//  Ryan Pearson
//  SID: 103965059
//  Date: 03-23-2014
//

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


void readerChild(int fd);
int
main(int argc, char* argv[])
{
    int fd1, fd2, status;
    char ch, fifoName1[100]="./FIFO/", fifoName2[100]="./FIFO/", welcome[100]="";
    pid_t pid;
    
    if(argc !=2){
        printf("Call model: %s <FIFO_Name>\n", argv[0]);
        printf("example: %s smith101\n", argv[0]);
        exit(0);
    }
    
    strcat(fifoName1, argv[1]);
    strcat(fifoName1, "1");
    strcat(fifoName2, argv[1]);
    strcat(fifoName2, "2");
    
    while((fd2 = open(fifoName1, O_WRONLY)) == -1) {
        fprintf(stderr, "Trying to connect\n");
        sleep(1);
    }
    
    fprintf(stderr, "Connected to a friend:\n");
    fprintf(stderr, "    Your messages                                   Friend messages\n");
    fprintf(stderr, "-------------------------------------------------------------------------------\n");
    
    while(1) {
        
        fd1 = open(fifoName2, O_RDONLY);
        if (!fork())
            readerChild(fd1);
        
        fd2 = open(fifoName1, O_WRONLY);
        strcat(welcome, argv[1]);
        strcat(welcome, " is joining the party.\n");
        printf("is pid %d and this is size %lu\n", getpid(), sizeof(getpid()));
        write(fd2, welcome, sizeof(welcome));
        while(read(0, &ch, 1) == 1)
            write(fd2, &ch, 1);
    }
}

void readerChild(int fd){
    char  ch, blanks[55]="                                               |  ";
    int flag=1;
    
    while(read(fd, &ch, 1) == 1){
        if(flag){
            flag=0;
            write(1, blanks, sizeof(blanks));
        }
        write(1, &ch, 1);
        if(ch=='\n') flag=1;
    }
    //close(fd);
}