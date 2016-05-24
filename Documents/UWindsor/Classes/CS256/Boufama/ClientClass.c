//
//  ClientClasss.c
//  
//
//  Created by Ryan Pearson on 03-23-2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
    int fd;
    char ch;
    
    while ((fd=open("./server", O_WRONLY))==-1) {
        fprintf(stderr, "trying to connect\n");
        sleep(1);
    }
    printf("Connected: Type data to be sent\n");
    
    while((ch=getchar()) != -1)
        write(fd, &ch, 1);
    close(fd);
}
