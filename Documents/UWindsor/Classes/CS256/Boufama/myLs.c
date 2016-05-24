//
//  myLs.c
//  Created by Ryan Pearson on 1.5.13.


#include <stdio.h>
#include <dirent.h>

long getSize (struct dirent *, char *);

int
main(int argc, char *argv[]){
    // declare variables- pointer to directory and direcotry structure pointer
    DIR *dp = NULL;
    struct dirent *dirp = NULL;
    char *path = argv[1];
    // if no arguments in command line, set current directory as path
    if(argc == 1){
        dp = opendir("./");
        path = "./";
    }
    else
        dp = opendir(argv[1]);

    while ((dirp = readdir(dp)) != NULL) {
        // check if file name opens to another DIR
        // check if you can open the file, if so, it is directory.
        if((opendir(dirp->d_name)) != NULL)
            if(dirp->d_name[0] == '.');
            else
                printf("%25s %10s\n", dirp->d_name, "Directory");
        // else print file and size
        else
            printf("%25s %10s%10ld Bytes\n", dirp->d_name, "File", getSize(dirp, path));
    }
    return 0;
}

// function for returning the size of the file
// input: directory structure
// output: long integer
long getSize(struct dirent *dirp, char *path){
    // set correct path for looking into folders.
    char buffer[100];
    int i = 0, x = 0;

    while((buffer[i++] = *path++) != '\0');
    i--;
    if(buffer[i-1] != '/'){
        buffer[i++] = '/';
        buffer[i] = '\0';
    }
    while((buffer[i++] = dirp->d_name[x++]) != '\0');

    FILE * fp = fopen(buffer, "r");
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
}