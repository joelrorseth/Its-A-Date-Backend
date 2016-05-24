//
//  Lab3Boufama.c
//  
//
//  Created by Ryan Pearson on 2/8/2014.
//
//

#include <stdio.h>          Reverse the contents of a text file line-by-line
#include <string.h>

int main(int argc, char *argv[]){
    char buffer[256];
    FILE *fp1, *fp2;
    long int fileSize, lineSize;
    
    if(argc != 3){
        printf("Call model: %s <inputFileName>  <outputFileName>\n", argv[0]);
        exit(0);
    }
    
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    if(!fp1 || !fp2){
        printf("File oupening problem\n");
        exit(0);
    }
    
    fseek(fp1, 0L, SEEK_END);
    fileSize = ftell(fp1);
    rewind(fp1);
    
    fseek(fp2, fileSize, SEEK_SET);
    
    while(fgets(buffer, 256, fp1)){
        lineSize = strlen(buffer);
        fseek(fp2, -lineSize, SEEK_CUR);
        fputs(buffer, fp2);
        fseek(fp2, -lineSize, SEEK_CUR);
    }
    fclose(fp2);
    fclose(fp1);
}