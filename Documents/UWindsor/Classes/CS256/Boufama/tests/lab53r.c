//
//  lab53r.c
//  
//
//  Created by Ryan Pearson on 03-05-2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <string.h>

int
main(void){
    
    int fd, value, fd2, pid, status;
    char buff[5];
    
    if ((fd=open("newFile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0700))==-1 ||
         (fd2=open("test.txt", O_RDONLY))==-1) {
        perror("Invalid open");
        exit(1);
    }
    
    if ((pid=fork())==-1) {
        perror("Invalid Fork");
        exit(2);
    }
    value=wait(&status);
    
    if (pid==0) {
        while (read(fd2, buff, 1)>0)
            write(fd, buff, 1);
        sleep(2);
        printf("Child Terminating %d\n", getpid());
        write(fd, "Child Terminating\n", 19);
        sleep(2);
        exit(20);
    }
    
    printf("My child has terminated.\n");
    write(fd, "My child has terminated status ", 30);
    sprintf(buff, "%d\n", WEXITSTATUS(status));
    write(fd, buff, strlen(buff));
    sprintf(buff, "%d" , value);
    write(fd, "PID- ", 6);
    write(fd, buff, strlen(buff));
    return 0;
}