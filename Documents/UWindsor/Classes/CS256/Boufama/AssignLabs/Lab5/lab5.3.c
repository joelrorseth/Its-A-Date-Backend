//
//  lab5.3.c
//  Created by Ryan Pearson on 2/25/2014.
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(void)
{
    int fd1, fd2, status, pid;
    char buff[256];
    
    if (((fd1=open("file.txt", O_RDONLY)))==-1 ||
          (fd2=open("newfile2.txt", O_CREAT|O_WRONLY|O_TRUNC, 0777))==-1) {
        printf("You have not opened the files correctly\n");
        return -1;
    }
    
    pid=fork();
    wait(&status);
    if (pid==0) {
        while ((read(fd1,buff,1))>0)
            write(fd2,buff,1);
        sleep(1);
        write(fd2,"Child terminating\n", 18);
        sleep(1);
        exit(20);
    }
    else{
        if (WIFEXITED(status)) {
            printf("exit good with status %d\n", WEXITSTATUS(status));
            write(fd2,"My child has terminated", 24);
        }
    }
    
    close(fd1);
    close(fd2);
    return 0;
}