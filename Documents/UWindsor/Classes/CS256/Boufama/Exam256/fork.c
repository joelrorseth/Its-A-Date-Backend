//
//  fork.c
//  
//
//  Created by Ryan Pearson on 04-04-2014.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <signal.h>

void fork2();
void six();

int
main(void)
{
//    fork2();
    six();
//    if (1){
//    int x=5;
//    
//    if(fork()>0){
//        sleep(1);
//        x++;
//        if (!fork()) {
//            x++;
//        }
//        else
//            sleep(1);
//    }
//    else
//        x--;
//    printf("%d ", x);
//    }
    
    
    
    
}

void fork2(){
    fork();
    if(fork()){
        if(fork())
            fprintf(stderr, "Hello\n");
        fprintf(stderr, "Hello\n");
    }
}

void six(){
    int i=1;
    while(i<=19){
        if(!(i%10))
            fputc('\n', stdout);
        else
            fputc('*', stdout);
        i++;
        if(i==15)
            kill(getpid(), SIGINT);
        sleep(1);
    }
}