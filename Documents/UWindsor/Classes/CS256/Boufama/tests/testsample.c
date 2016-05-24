//
//  testsample.c
//  
//
//  Created by Ryan Pearson on 03-05-2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int fd, size, i=0;
    char ch[2];
    
    if ((fd=open(argv[1], O_RDWR))==-1){
        perror("invalid open");
        exit(1);
    }
    size=lseek(fd,0,SEEK_END);
    lseek(fd, 0, SEEK_SET);
    while (i<size) {
        lseek(fd, i, SEEK_SET);
        read(fd, ch, 1);
        lseek(fd, size+i, SEEK_SET);
        write(fd, ch, 1);
        i++;
    }
    
    return 0;
}