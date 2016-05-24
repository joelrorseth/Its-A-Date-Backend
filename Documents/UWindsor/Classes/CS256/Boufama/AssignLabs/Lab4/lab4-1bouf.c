//
//  lab4-1bouf.c
//  
//
//  Created by Ryan Pearson on 2/20/2014.
//
//

#include <stdio.h>          //Reverse the contents of a text file line-by-line
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    char buffer[256];
    int fd1, fd2, i=0, end;
    long int fileSize, lineSize;
    
    if(argc != 3){
        printf("Call model: %s <inputFileName>  <outputFileName>\n", argv[0]);
        return(0);
    }
    
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0777);
    
    if( fd1==-1 || fd2==-1){
        perror("File opening problem ");
        return(0);
    }
    
    fileSize = lseek(fd1, 0L, SEEK_END);
    lseek(fd1, 0L, SEEK_SET);
    
    lseek(fd2, fileSize, SEEK_SET);
    
    while((end=read(fd1, &(buffer[i]), 1)) == 1){
        if(buffer[i] == '\n'){
            i++;                          // number of characters read so far
            lseek(fd2, -i, SEEK_CUR);     // go back size-of-line
            if(write(fd2, buffer, i) !=i){
                perror("Wrinting to output ");
                return(0);
            }
            lseek(fd2, -i, SEEK_CUR);
            i=0;
        }else
            i++;
    }
    if(end==-1){
        perror("Reading from input ");
        return(1);
    }
    close(fd2);
    close(fd1);
}