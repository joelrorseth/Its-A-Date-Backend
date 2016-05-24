//
//  Client.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include <wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void readerChild(int fd);

int main(int argc, char *argv[]) {
    
    int fd1, fd2;
    char ch;
    
    while(fd2 = open("./tmp/fifo1", O_WRONLY) == -1) {
        
        fprintf(stderr, "Trying to connect\n");
        sleep(1);
    }
    
    fprintf(stderr, "Connected to a friend:\n");
    fprintf(stderr, "    Your messages                                   Friend messages\n");
    fprintf(stderr, "-------------------------------------------------------------------------------\n");
    
    while(1) {
        
        fd1 = open("./tmp/fifo2", O_RDONLY);
        if (!fork())
            readerChild(fd1);
        
        fd2 = open("./tmp/fifo1", O_WRONLY);
        while(read(0, &ch, 1) == 1)
            write(fd2, &ch, 1);
    }
    
}

void readerChild(int fd) {
    
    char  ch, blanks[55]="                                               |  ";
    int flag = 1;
    
    while(read(fd, &ch, 1) == 1) {
        
        if(flag) {
            flag = 0;
            write(1, blanks, sizeof(blanks));
        }
        write(1, &ch, 1);
        if(ch == '\n') flag = 1;
    }
    
    close(fd);
}
