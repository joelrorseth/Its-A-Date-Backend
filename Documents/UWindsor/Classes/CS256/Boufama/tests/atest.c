//
//  atest.c
//  
//
//  Created by Ryan Pearson on 2014-02-27.
//
//

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

void myAlarm(){
    printf("i have an alarm, taken care of\n");
    //sleep(3);
    alarm(5);
}

int
main(void)
{
    int status;
    pid_t pid;
    signal(SIGALRM, myAlarm);
    alarm(3);
    pid=fork();
    wait(&status);
    
    if(pid==0){
        
        // why would it not execute below this commented block?
        //sleep(1);
        if(execlp("ls", "ls", (char *)0)==-1){
            perror("Child Error");
            exit(22);
        }
        //sleep(1);
        fwrite("You are in here\n", 16, 1, stdout);
        while (1) {
            printf("Going to sleep\n");
            sleep(1);
            //fflush(stdout);
        }
    }
    else
        while (1){
            printf("in here\n");
            sleep(1);
        }
    sleep(5);
    printf("exiting\n");
    
    return 0;
}