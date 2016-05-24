//
//  Server.c
//  Provided by Dr. Boufama
//  Date: 03-23-2014
//

//#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>


void readerChild(int fd);


int main(int argc, char *argv[]){
    int fd1, fd2, status;
    char ch, fifoName1[100]="./", fifoName2[100]="./";
    pid_t pid;
    
    if(argc != 2){
        printf("Call model: %s <FIFO_Name>\n", argv[0]);
        printf("example: %s tata1299\n", argv[0]);
        exit(0);
    }
    strcat(fifoName1, argv[1]);
    strcat(fifoName1, "1");
    strcat(fifoName2, argv[1]);
    strcat(fifoName2, "2");
    
    unlink(fifoName1);
    unlink(fifoName2);
    
    if(mkfifo(fifoName1, 0777)){
        perror("main could not create fifo");
        exit(1);
    }
    
    if(mkfifo(fifoName2, 0777)){
        perror("main could not create fifo");
        exit(1);
    }
    
    chmod(fifoName1, 0777);
    chmod(fifoName2, 0777);
    
    while(1){
        fprintf(stderr, "Waiting for a friend to chat\n");
        fd1= open(fifoName1, O_RDONLY);
        if (!fork())
            readerChild(fd1);
        
        fprintf(stderr, "Got a friend:\n");
        fprintf(stderr, "    Your messages                                   Friend messages\n");
        
        fprintf(stderr, "-------------------------------------------------------------------------------\n");
        
        fd2= open(fifoName2, O_WRONLY);
        
        while(read(0, &ch, 1) == 1)
            write(fd2,&ch,1);
    }
}

void readerChild(int fd){
    char  ch, blanks[55]="                                               |  ";
    int flag=1;
    int fdryan;
    
    fdryan = open("Ryan.txt", O_CREAT|O_WRONLY|O_TRUNC, 0777);
    
    while(read(fd, &ch, 1) == 1){
        if(flag){
            flag=0;
            write(1, blanks, sizeof(blanks));
        }
        write(1, &ch, 1);
        write(fdryan, &ch, 1);
        if(ch=='\n') flag=1;
    }
}