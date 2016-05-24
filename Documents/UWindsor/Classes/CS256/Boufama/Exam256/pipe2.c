//
//  pipe2.c
//  
//
//  Created by Ryan Pearson on 04-12-2014.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void child (int *);
void parent (int *);

int
main(int argc, char *argv[])
{
    int fd[2];
    
    if(pipe(fd)==-1)
        exit(1);
    
    if (fork() ==0) {
        sleep(1);
        child(fd);
    }
    else
        parent(fd);
    exit(0);
}

void parent(int *fd){
    char ch;
    
    close(fd[1]);
    printf("Child has sent the message:\n");
    do{
        read(fd[0], &ch, 1);
        printf("%c", ch);
        if(ch=='\n')
            break;
    }while (1);
}

void child(int *fd){
    char message[255]="Hello, here is my data...\n";
    close(fd[0]);
    write(fd[1], message, 26);
}