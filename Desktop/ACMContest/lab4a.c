//
//  lab4b.c
//  
//  print file line by line backwards.
//  Created by Ryan Pearson on 2/8/2014.
//
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int fd1, fd2, i = 0, fileSize = 0;
    char string[256];
    
    if ((( fd1 = open (argv[1], O_RDONLY)) == -1) ||
        ((fd2 = open (argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0755)) == -1)){
        //((fd2 = creat (argv[2], O_RDWR)) == -1)){
        printf("Invalid file open\n");
        return -1;
    }
    
    int x = 0, y = 0;
    fileSize = lseek (fd1, 0, SEEK_END);
    lseek(fd2, fileSize-1, SEEK_SET);                   // offset output file
    lseek(fd1, 0, SEEK_SET);                            // rewind input file
    while (++i < 256 && (read(fd1, &string[x++], 1) > 0))// does not catch \n, so read into string and check for \n char
        if (string[x-1] == '\n') {                      // if \n offset pointer in file and write new line
            lseek(fd2, -i, SEEK_END);
            write(fd2, string, x);
            x=0;
        }
    close(fd1);
    close(fd2);
    return 0;
}