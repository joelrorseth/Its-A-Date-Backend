//
//  ServerClass.c
//  
//
//  Created by Ryan Pearson on 03-23-2014.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int
main(int argc, char* argv[])
{
    int fd;
    char ch;
    
    unlink("./server");
    if(mkfifo("./server", 0777)!=0)
        exit(1);
    chmod("./server", 0777);
    while (1) {
        fprintf(stderr, "Waiting for a client\n");
        fd = open("./server", O_RDONLY);
        fprintf(stderr, "Got a client: ");
        while (read(fd, &ch, 1)==1) {
            fprintf(stderr, "%c", ch);
        }
    }
}
