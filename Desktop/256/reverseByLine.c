//
//  reverseByLine.c
//  
//
//  Created by Ryan Pearson on 05-05-2016.
//
//

//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char *argv[]){
    
    int fd1, fd2, fileSize=0, i=0, x=0;
    char string[256];
    
    if(((fd1=open(argv[1], O_RDONLY))==-1) || ((fd2 = open (argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0755)) == -1))
    {
        write(STDERR_FILENO, "Error opening files\n", 20);
        write(STDERR_FILENO, "usage: program <inputFile> <outputFile>\n", 40);
        return -1;
    }
    
    fileSize=lseek(fd1, 0, SEEK_END);   //get size of file
    lseek(fd2, fileSize-1, SEEK_SET);   //offset output file
    lseek(fd1, 0, SEEK_SET);            // rewind fd1
    while (++i < 256 && (read(fd1, &string[x++], 1))>0)
        if(string[x-1]=='\n'){
            lseek(fd2, -i, SEEK_END);
            write(fd2, string, x);
            x=0;
        }
    
    close(fd1);
    close(fd2);
    return 0;
}
