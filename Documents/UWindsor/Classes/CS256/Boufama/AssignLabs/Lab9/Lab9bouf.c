#include <wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readerChild(int fd);

int main(int argc, char *argv[]){
    int fd1, fd2, status;
    char ch, fifoName1[100]="/tmp/", fifoName2[100]="/tmp/";
    
    if(argc != 2){
        printf("Call model: %s <FiFO_Name>\n", argv[0]);
        printf("example: %s tata1299\n", argv[0]);
        exit(0);
    }
    strcat(fifoName1, argv[1]);
    strcat(fifoName1, "1");
    strcat(fifoName2, argv[1]);
    strcat(fifoName2, "2");
    
    while((fd1=open(fifoName1, O_WRONLY))==-1){
        fprintf(stderr, "trying to connect\n");
        sleep(1);
    }
    
    while((fd2=open(fifoName2, O_RDONLY))==-1){
        fprintf(stderr, "trying to connect\n");
        sleep(1);
    }
    
    printf("Connected, let's chat\n");
    fprintf(stderr, "    Your messages                                   Friend messages\n");
    fprintf(stderr, "-------------------------------------------------------------------------------\n");
    
    while(1){
        if (!fork())
            readerChild(fd2);
        
        while(read(0, &ch, 1) == 1)
            write(fd1,&ch,1);
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
}