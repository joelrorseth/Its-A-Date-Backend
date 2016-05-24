//
//  lab4_sol.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BIFSIZE 256

int main(int argc, char *argv[]) {
    
    FILE *fpr, *fpw;
    int fileSize, lineSize = 0;
    char line[BIFSIZE];
    
    if((fpr = fopen (argv[1], "r")) == NULL ||
       (fpw = fopen (argv[2], "w")) == NULL )
    {
        printf("File openning error\n");
        exit (0);
    }
    
    fseek( fpr, 0, SEEK_END );
    
    fileSize = ftell( fpr );
    
    rewind( fpr );
    
    fseek( fpw, fileSize, SEEK_SET );
    
    while( fgets( line, BIFSIZE, fpr ) != NULL )
    {
        lineSize = strlen( line );
        fseek( fpw, -lineSize, SEEK_CUR );
        fputs( line, fpw );
        fseek( fpw, -lineSize, SEEK_CUR );
    }
}