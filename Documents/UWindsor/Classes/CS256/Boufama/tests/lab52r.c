//
//  lab52r.c
//  
//
//  Created by Ryan Pearson on 03-05-2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int
main(void){
    
    int fd, pid, i, status;
    char ch[1];

    if ((fd=open("test.txt", O_RDONLY))==-1) {
        perror("Invalid open");
        exit(1);
    }
    
    if ((pid=fork())==-1){
        perror("invalid Fork");
        exit(2);
    }
    wait(&status);
    
    if (pid==0) {
        alarm(1);
        while (read(fd, ch, 1)>0){
            write(STDOUT_FILENO, ch, 1);
        }
        sleep(2);
        printf("Child Terminating\n");
        sleep(2);
        exit(20);
    }
    else
        if(WIFEXITED(status))
            printf("My child has terminated, %d\n", WEXITSTATUS(status));
    
    
    return 0;
}