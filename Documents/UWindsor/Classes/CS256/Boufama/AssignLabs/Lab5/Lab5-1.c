//
//  Lab5-1.c
//  
//
//  Created by Ryan Pearson on 2/24/2014.
//
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    
    int pid=0, pid2=0, val, val2;
    printf("\nI am parent and only process PID: %d\n\n", getpid());
    pid=fork();
    wait(&val);
    if(pid== -1){
        perror("Impossible to fork\n");
        _exit(1);
    }
    
    if(pid>0){
        pid2=fork();
        wait(&val2);
        if (pid2==0){
            printf("I am child 2 process id:%d\n", getpid());
            printf("Now My parent is still process id:%d\n\n", getppid());
            exit(2);
        }
    }
    else{
        if (pid==0) {
            printf("I am child 1 process id:%d\n", getpid());
            printf("My parent is process in 1 is id:%d\n\n", getppid());
			exit(1);
        }
    }

    if(pid>0 && pid2>0){
        printf("I am parent of both processes with PID %d\n", getpid());
        printf("My first Child is %d and my second is %d\n", pid, pid2);
        printf("Exit value of child process' 1 & 2 was %d & %d\n\n", val, val2);
        if (WIFEXITED(val)) {
            printf("%d\n", WEXITSTATUS(val));
        }
        if (WIFEXITED(val2)) {
            printf("%d\n", WEXITSTATUS(val2));
        }
        exit(0);
    }
    
    return 0;
}