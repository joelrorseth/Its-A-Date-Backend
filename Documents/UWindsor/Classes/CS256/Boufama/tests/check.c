//
//  check.c
//  
//
//  Created by Ryan Pearson on 2014-03-01.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main()
{
    int pid;
    int status;
    if((pid=fork())==-1)
        perror("fork");
    else if (pid == 0){
        sleep(5);
        exit(3);
    }
    else{
        pid=wait(&status);
        printf("status %d\n", status);
        if (WIFEXITED(status)) {
            printf("%d-exit status\n", WEXITSTATUS(status));
        }
    }
    
    
}