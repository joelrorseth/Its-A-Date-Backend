//
//  fig1.3.c
//  
//
//  Created by Ryan Pearson on 2/13/2014.
//
//

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

long int getSize(char *);

int
main(int argc, char *argv[]){
    
    DIR *dp;
    struct dirent *dirp;
    
    if (argc != 2) {
        printf("Usage fig1.3 <directory>\n");
        return 1;
    }
    
    if ((dp = opendir(argv[1])) == NULL) {
        printf("can't open %s", argv[1]);
        return 2;
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (opendir(dirp->d_name) != NULL) {
            printf("%s%s\n", dirp->d_name, " directory!");
        }
        else
            printf("%s size- %ld\n", dirp->d_name, getSize(dirp->d_name));
    }
    return 0;
}

// this interpretation only works on current directory calls of the program.
long int getSize(char *file)
{
    long size = 0;
    FILE *fp;
    
    if ((fp=fopen(file, "r")))
        fseek(fp, 0, SEEK_END);
    return ftell(fp);
    
    //return size;
}