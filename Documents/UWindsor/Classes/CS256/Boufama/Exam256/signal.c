//
//  signal.c
//  
//
//  Created by Ryan Pearson on 04-12-2014.
//
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/signal.h>

void nextAlarm(){
    kill(getpid(), SIGTERM);
}

void myAlarm(){
    printf("I got alarm\n");
    signal(SIGALRM, nextAlarm);
    alarm(3);
}

int
main(int argc, char *argv[]){
    signal(SIGALRM, myAlarm);
    alarm(3);
    
    while (1) {
        printf("I am working\n");
        sleep(1);
    }
}