//
//  lab4a.c
//  
//  print entire file backwards
//  Created by Ryan Pearson on 2/9/2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int fd1, fd2, i = 0, fileSize = 0;
    char buff;
    
    if ((( fd1 = open (argv[1], O_RDONLY)) == -1) ||
        ((fd2 = open (argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0755)) == -1)){
        printf("Invalid file open\n");
        return -1;
    }
    
    int x = 0, y = 0;
    // lseek returns offset location measured in bytes(use to set filesize)
    fileSize = lseek(fd1, 0, SEEK_END);
    lseek(fd2, fileSize-1, SEEK_SET);                   // offset output file
    lseek(fd1, 0, SEEK_SET);                            // rewind input file
    while (++i < fileSize && (read(fd1, &buff, 1) > 0)){
        lseek(fd2, -i, SEEK_END);
        write(fd2, &buff, 1);
    }
    close(fd1);
    close(fd2);
    return 0;
}