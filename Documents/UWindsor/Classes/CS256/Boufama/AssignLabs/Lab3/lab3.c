//
//  lab3.c
//  
//
//  Created by Ryan Pearson on 2/2/2014.
//
//

#include <stdio.h>


int
main(int argc, char *argv[])
{
    FILE *fpin;
    FILE *fpout;
    char entries[40];
    int x = 0, y = 0;
    char ch;
    
    if (argc != 3) {
        printf("Usage: reverseFile <inputFileName> <ouputFileName>\n");
        return -1;
    }
    
    if((fpin=fopen(argv[1], "rb")) == NULL) ||
        ((fpout=fopen(argv[2], "wb")) == NULL){
        printf("Could not open file\n");
        return -2;
    }
    
    while (!feof(fpin)){
        do{
            ch=fgetc(fpin);
            printf("%c", ch);
            //entries[x][y++]=ch;
            printf("%s\n", entries[x]);
        }while (ch != '\n' || ch != EOF);
        //entries[x][y]='\n';
        x++;
        y=0;
    }
    
    
    return 0;
}