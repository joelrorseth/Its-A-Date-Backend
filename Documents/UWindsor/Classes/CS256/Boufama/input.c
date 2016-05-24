//
//  input.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <unistd.h>


int
main(int argc, char *argv[]){
    FILE * fd;
    char c;
    
    if (argc == 1)
        fd = stdin;
    else
        if((fd = fopen(argv[1], "r")) == NULL){
            int x = fprintf(stderr, "Error opening %s, exiting.\n", argv[1]);
            printf("%d\n", x);
            return(0);
        }
    while( (c=getc(fd)) != EOF)
        putc(c,stdout);
    
    return(0);
}