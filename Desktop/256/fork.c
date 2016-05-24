//
//  fork.c
//  
//
//  Created by Ryan Pearson on 2016-04-29.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int
main(int argc, char *argv[]){
    int pid;
    
    printf("only one process\n");
    pid= fork();
    
    if(pid==-1){
        perror("impossible to fork");
        exit(1);
    }
    // fork returns PID to parent, returns 0 to child.
    // returns twice, very strange.
    if(pid > 0)
        printf("I am the parent, PID=%d\n", getpid());
    else
        if(pid==0)
            printf("I am the child, PID=%d\n", getpid());
    
    exit(0);
    
}