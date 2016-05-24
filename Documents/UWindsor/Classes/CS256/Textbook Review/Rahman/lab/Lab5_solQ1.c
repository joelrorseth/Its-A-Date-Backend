//
//  Lab5_solQ1.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, status;
    pid_t pid;
    
    printf("Original process: pid = %d, ppid = %d\n", getpid(), getppid());
    
    if( (pid = fork()) == -1 )
    {
        perror("fork 1 error");
        exit(EXIT_FAILURE);
    }
    
    else if( pid == 0 ) // child process
    {
        printf("Child 1 process: pid = %d, ppid = %d\n", getpid(), getppid());
        if( (pid = fork()) == -1 )
        {
            perror("fork 1 error");
            exit(EXIT_FAILURE);
        }
        
        else if( pid == 0 ) // child process
        {
            printf("Child 11 process: pid = %d, ppid = %d\n", getpid(), getppid());
        }
        else                // parent process
        {
            if( (pid = fork()) == -1 )
            {
                perror("fork 1 error");
                exit(EXIT_FAILURE);
            }
            
            else if( pid == 0 ) // child process
            {
                printf("Child 12 process: pid = %d, ppid = %d\n", getpid(), getppid());
            }
            else                // parent process
            {
                wait(&status);
                exit(EXIT_SUCCESS);
            }
        }
    }
    else                // parent process
    {
        if( (pid = fork()) == -1 )
        {
            perror("fork 1 error");
            exit(EXIT_FAILURE);
        }
        
        else if( pid == 0 ) // child process
        {
            printf("Child 2 process: pid = %d, ppid = %d\n", getpid(), getppid());
            if( (pid = fork()) == -1 )
            {
                perror("fork 1 error");
                exit(EXIT_FAILURE);
            }
            
            else if( pid == 0 ) // child process
            {
                printf("Child 21 process: pid = %d, ppid = %d\n",  getpid(), getppid());
            }
            else                // parent process
            {
                if( (pid = fork()) == -1 )
                {
                    perror("fork 1 error");
                    exit(EXIT_FAILURE);
                }
                
                else if( pid == 0 ) // child process
                {
                    printf("Child 22 process: pid = %d, ppid = %d\n",  getpid(), getppid());
                }
                else                // parent process
                {
                    wait(&status);
                    exit(EXIT_SUCCESS);
                }
            }
        }
        else                // parent process
        {
            wait(&status);
            exit(EXIT_SUCCESS);
        }
    }
}
