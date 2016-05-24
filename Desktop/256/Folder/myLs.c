//
//  myLs.c
//  
//
//  Created by Ryan Pearson on 05-05-2016.
//
//

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

long int getSize(char *name){
    FILE *fp;
    long int size=0;
    
    if((fp=fopen(name, "r")))
        while(fgetc(fp) != EOF)
            size++;
    
    return (size);
}

int
main(int argc, char *argv[]){
    DIR *dp;
    //char *path=argv[1];
    struct dirent *dirp = NULL;
    
    if(argc == 1){
        dp=opendir("./");
    }
    else{
        dp=opendir(argv[1]);
    }
    
    
    while ((dirp=readdir(dp)) != NULL){
        if(opendir(dirp->d_name) != NULL){
            if(dirp->d_name[0] == '.');
            else{
                printf("%25s Directory\n", dirp->d_name);
            }
        }
        else{
            printf("%25s File, Size %ld\n", dirp->d_name, getSize(dirp->d_name));
        }
        
    }
    
//    while ((dirp = readdir(dp)) != NULL) {
//        // check if file name opens to another DIR
//        // check if you can open the file, if so, it is directory.
//        if((opendir(dirp->d_name)) != NULL)
//        if(dirp->d_name[0] == '.');
//        else
//        printf("%25s %10s\n", dirp->d_name, "Directory");
//        // else print file and size
//        else
//        printf("%25s %10s%10ld Bytes\n", dirp->d_name, "File", getSize(dirp->d_name));
//    }
    
//    while ( (dirp=readdir(dp)) != NULL)
//        if (strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, ".."))
//            if (opendir(dirp->d_name))
//                printf("%s Directory\n", dirp->d_name);
//            else
//                printf("%s File, Size %ld\n", dirp->d_name, getSize(dirp->d_name));
    
    closedir(dp);
    exit(0);
    
}
















