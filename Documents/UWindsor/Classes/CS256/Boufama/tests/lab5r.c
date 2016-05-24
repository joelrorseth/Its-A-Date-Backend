//
//  lab5r.c
//  
//
//  Created by Ryan Pearson on 03-05-2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>

void myAlarm(){
    printf("caught!\n");
}

int
main(void)
{
    pid_t child1, child2;
    int status, status2;
    signal(SIGALRM, myAlarm);
    if ((child1=fork())==-1) {
        perror("Didn't Fork1");
        exit(1);
    }
    waitpid(child1, &status, 0);
    if (child1>0) {
        printf("Parent Child1 is %d\n", getpid());
        if((child2=fork())==-1){
            perror("Didn't Fork2");
            exit(2);
        }
        waitpid(child2, &status2, 0);
        if (child2==0) {
            printf("Child2 %d\n", getpid());
            printf("Parent Child2 is %d\n", getppid());
            alarm(1);
            sleep(2);
        }
        if (child2==0 || child1==0){
            sleep(1);
            exit(0);
        }
    }
    else
        printf("Child1 %d\n", getpid());
    
    if (child1 > 0 && child2 > 0)
        printf("I am original parent %d, and c1-%d and c2-%d\n", getpid(), child1, child2);
    return 0;
}