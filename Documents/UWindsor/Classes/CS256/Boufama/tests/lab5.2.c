//
//  lab5.2.c
//  Created by Ryan Pearson on 2/25/2014.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int
main(void)
{
    int fd1, fd2, pid, value, pidtest=0;
//    chdir("./junk");
    if(((fd1 = open("test.txt", O_RDONLY)))==-1){
        printf("Invalid open\n");
        return -1;
    }
//    chdir("..");
//    if(((fd2=open("newFile.txt", O_CREAT|O_WRONLY|O_TRUNC, 0777)) == -1)){
//        printf("Invalid open write file\n");
//        return -1;
//    }
    
    pid=fork();
    pidtest=wait(&value);
    
    if (pid==0) {
        char buff[1];
        alarm(1);
        while (read(fd1, buff, 1)>0)
            write(STDOUT_FILENO, buff, 1);
        
        sleep(1);
        printf("child terminating & PID %d\n", getpid());
        sleep(1);
        exit(20);
    }
    else{
        if(WIFEXITED(value))
            printf("Normal exit %d\n", WEXITSTATUS(value));
        if (WIFSIGNALED(value))
            printf("What just happend! Death by %d\n", WTERMSIG(value));
        if(WCOREDUMP(value))
            printf("Core generated\n");
        
        printf("My child has terminated\n");
        sleep(1);
        printf("parent %d has lost it's child ", getpid());
        sleep(1);
        printf("with exit status %d\n", value/256);
        sleep(1);
        printf("and the parent process of this parent is %d\n", getppid());
        sleep(1);
        printf("My PID test is %d and is my terminated child\n", pidtest);
        
    }
    
    close(fd1);
    exit(0);
}
