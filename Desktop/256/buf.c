//
//  buf.c
//  
//
//  Created by Ryan Pearson on 05-05-2016.
//
//

#include <stdio.h>


int
main(int argc, char *argv[]){
    FILE *fd;
    int ch;
    int fileSize=-1;
    
    fd = fopen (argv[1], "r");
    do{
        ch=getc(fd);
        fileSize++;
    }while(ch != EOF);
    
    printf("Size of %s is %d\n", argv[1], fileSize);
    
}