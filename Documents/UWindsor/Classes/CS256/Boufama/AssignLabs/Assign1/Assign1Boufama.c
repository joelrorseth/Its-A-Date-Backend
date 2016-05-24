//
//  Assign1Boufama.c
//  
//
//  Created by Ryan Pearson on 2/2/2014.
//
//

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

long int getSize(char *fName){
    FILE *fp;
    long int size=0;
    
    if((fp=fopen(fName, "r")))
        while(fgetc(fp) != EOF)
            size++;
    
    return(size);
}

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    
    if(argc==1)
        dp = opendir("./");
    else
        dp = opendir(argv[1]);
    
    while ( (dirp=readdir(dp)) != NULL)
    if (strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, ".."))
        if (opendir(dirp->d_name))
            printf("%s Directory\n", dirp->d_name);
    else
        printf("%s File, Size %ld\n", dirp->d_name, getSize(dirp->d_name));
    
    closedir(dp);
    return(0);
}