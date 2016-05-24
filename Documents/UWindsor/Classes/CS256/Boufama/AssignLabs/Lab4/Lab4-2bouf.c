//
//  Lab4-2bouf.c
//  
//
//  Created by Ryan Pearson on 2/20/2014.
//
//

#include <stdio.h>      //Reverse the contents of a text file byte-by-byte
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    char buffer;
    int fd1, fd2, end;
    long int fileSize;
    
    if(argc != 3){
        printf("Call model: %s <inputFileName>  <outputFileName>\n", argv[0]);
        return(0);
    }
    
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC, 0777);
    
    if( fd1==-1 || fd2==-1){
        perror("File opening problem ");
        return(1);
    }
    
    fileSize =lseek(fd1, 0L, SEEK_END);
    lseek(fd1, 0L, SEEK_SET);
    
    lseek(fd2, fileSize, SEEK_SET);
    
    while((end=read(fd1, &buffer, 1))==1){
        lseek(fd2, -1, SEEK_CUR);           // go back 1 byte
        if(write(fd2, &buffer, 1) != 1){
            perror("Wrinting to output ");
            return(1);
        }
        lseek(fd2, -1, SEEK_CUR);
    }
    if(end==-1){
        perror("Reading from input ");
        return(1);
    }
    close(fd2);
    close(fd1);
    return(0);
}
