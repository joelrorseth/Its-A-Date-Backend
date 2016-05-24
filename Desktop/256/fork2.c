//
//  fork2.c
//  
//
//  Created by Ryan Pearson on 2016-04-29.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[]){
    int pid;
    
    pid=fork();
    if(pid){
        printf("parent process, pid %d\n", getpid());
        while(1)
            sleep(5);
    }
    
    printf("child process, pid=%d\n", getpid());
    exit(0);
}
