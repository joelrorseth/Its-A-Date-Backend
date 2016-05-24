//
//  test2.c
//  
//
//  Created by Ryan Pearson on 04-10-2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int
main(int argc, char*argv[])
{
    pid_t pid1, pid2;
    int fd1, fd2;
    int status;
    char c;
    
    if (argc<3 || argc>5) {
        printf("Call model: %s <InputFile> <InputFile2> (command)\n", argv[0]);
        exit(1);
    }
    
    if ((fd1=open(argv[1], O_RDONLY))==-1 || ((fd2=open(argv[2], O_RDONLY))==-1)) {
        perror("No open las files\n");
        exit(1);
    }
    printf("Parent PID: %d\n", getpid());
    if ((pid1=fork())>0) {
        wait(&status);
        printf("Parent: %d terminated with status=%d\n", pid1, WEXITSTATUS(status));
        if ((pid2=fork())>0) {
            wait(&status);
            printf("Parent: %d terminated with status=%d\n", pid2, WEXITSTATUS(status));
            printf("Parent Executing: %s\n", argv[3]);
//            if (!fork())
//                wait(&status);
//            else{
//                execlp(argv[3], argv[3], (char *)0);
//                printf("\n\n\n\n");
//                exit(1);
//            }
//            if (argv[4]) {
//                char *buffer;
//                buffer=argv[3];
//                strcat(buffer, " ");
//                strcat(buffer, argv[4]);
//                printf("%s\n", buffer);
//                printf("\n\n\n\n");
//                system(buffer);
//                printf("\n\n\n\n");
//                printf("Parent %d: Bye\n", getpid());
//                exit(0);
//            }
            //else{
                printf("\n\n\n\n");
                system(argv[3]);
                printf("\n\n\n\n");
                printf("Parent %d: Bye\n", getpid());
                exit(0);
            //}
        }
        else{
            printf("\n\nChild %d: display file contents\n", getpid());
            sleep(1);
            while (read(fd2, &c, 1)>0) {
                write(STDOUT_FILENO, &c, 1);
            }
            sleep(1);
            printf("\n\nChild Terminating with status 22\n");
            exit(22);
            
        }
        
    }
    else{
        printf("\n\nChild %d: display file contents\n", getpid());
        sleep(1);
        while (read(fd1, &c, 1)>0) {
            write(STDOUT_FILENO, &c, 1);
        }
        sleep(1);
        printf("\n\nChild terminating exit status 11\n");
        exit(11);
    }
    
    
    
    
}