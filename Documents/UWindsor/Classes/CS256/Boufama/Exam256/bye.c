//
//  bye.c
//  
//
//  Created by Ryan Pearson on 04-10-2014.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>

void action(int n){
    printf("10 20");
}

int
main(void)
{
//    for (int i =0; i < 4; i++){
//        printf("Bye\n");
//        printf("-------Group-------\n");
//        if (fork()) {
//            printf("Hi\n");
//        }
//    }
    
    if(!fork()){
        signal(SIGALRM, action);
        alarm(1);
        sleep(100);
    }
    else
        printf("A B ");
    
   // exit(0);
}