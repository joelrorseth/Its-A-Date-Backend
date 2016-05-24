//
//  Server.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void readerChild(int fd);

int main(int argc, char *argv[]){
    
    int fd1, fd2;
    char ch;
    
    unlink("./tmp/rahmanq1");  /* delete any previous FIFO */
    unlink("./tmp/rahmanq2");
    
    if(mkfifo("./tmp/rahmanq1", 0777)){ //use your user ID
        perror("main");
        exit(1);
    }
    
    if(mkfifo("./tmp/rahmanq2", 0777)){
        perror("main");
        exit(1);
    }
    
    fprintf(stderr, "Waiting for a friend to chat\n");
    
    fd1 = open("./tmp/rahmanq1", O_RDONLY);
    if (!fork())
        readerChild(fd1);
    
    fprintf(stderr, "You have got a friend:\n");
    fprintf(stderr, "    Your messages                                   Friend messages\n");
    fprintf(stderr, "-------------------------------------------------------------------------------\n");
    
    while(1) {
        
        fd2 = open("./tmp/rahmanq2", O_WRONLY);
        
        while(read(0, &ch, 1) == 1)
            write(fd2, &ch, 1);
        
        fd1 = open("./tmp/rahmanq1", O_RDONLY);
        if (!fork())
            readerChild(fd1);
    }
    
}

void readerChild(int fd){
    char  ch, blanks[55]="                                               |  ";
    int flag = 1;
    
    while(read(fd, &ch, 1) == 1){
        if(flag){
            flag = 0;
            write(1, blanks, sizeof(blanks));
        }
        write(1, &ch, 1);
        if(ch == '\n') flag = 1;
    }
    
    close(fd);
}