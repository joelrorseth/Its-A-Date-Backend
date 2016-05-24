//
//  Lab5_solQ2.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc, int *argv[])
{
    int fd, status;
    char c;
    pid_t pid;
    
    if( (fd = open("file.txt", O_RDONLY)) == -1)
    {
        printf("File file.txt could not be opened\n");
        exit(0);
    }
    
    if( (pid = fork()) == -1 )
    {
        perror("fork 1 error");
        exit(EXIT_FAILURE);
    }
    
    else if( pid == 0 ) // child process
    {
        printf("\nChild: printing file contents:\n\n");
        while( read( fd, &c, 1 ) > 0 )
        {
            write( STDOUT_FILENO, &c, 1 );
        }
        printf("\n\nChild: sleeping 5 sec.\n");
        sleep(5);
        printf("\nChild: terminating\n");
        sleep(5);
        exit(20);
    }
    else                // parent process
    {
        wait(&status);
        printf("\nParent: My child has terminated\n");
        printf("Child return ststus = %d\n\n", WEXITSTATUS(status));
        exit(EXIT_SUCCESS);
    }
}