//
//  reverse.c
//  
//
//  Created by Ryan Pearson on 05-05-2016.
//
//

#include <stdio.h>
#include <stdlib.h>


int
main(int argc,char *argv[]){
    FILE *fpin;
    FILE *fpout;
    char entries[50];
    char ch;
    int x=0, y=0;
    
    if(argc != 3){
        printf("Usage: reverse <inputFileName> <outputFileName>\n");
        return -1;
    }
    
    if(!(fpin=fopen(argv[1], "r"))){
        printf("No open read file\n");
        return -2;
    }
    
    if(!(fpout=fopen(argv[2], "w"))){
        printf("No open write file\n");
        return -3;
    }
    
    while((entries[x++]=fgetc(fpin))!=EOF){
        if (x > 49 || entries[x-1]=='\n' || entries[x-1]==EOF) {
            while(x-- != 0){
                if(entries[x]!=EOF)
                    printf("%c", entries[x]);
            }
            if(x==-1)
                x=0;
        }
    }
    printf("\n");
    
}