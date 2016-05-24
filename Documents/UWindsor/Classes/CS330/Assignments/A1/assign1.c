//
//  assign1.c
//  
//
//  Created by Ryan Pearson on 05-12-2016.
//  to use dtrace to scan system calls invoke sudo dtrace -c ./a.out -l | grep 'syscall'
//  sudo dtrace -n 'syscall:::entry { @assign1 = count(); }' --> counts total system calls for program.
//  sudo dtruss -n assign1  --> use to trace code with name assign 1. (uses dtrace)
//


#define SIZE 1000
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
int copy(char *input, char *output);
int mydirectory(char *input, char *output);


int
main(void){
    
    char input[SIZE];
    char output[SIZE];
    size_t length;
    DIR *dp;
    
    // gather input
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*This program will copy files and directory's 1 layer deep.*\n");
    printf("*Subdirectories will not be copied.                        *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("\nPlease enter input file location$$: ");
    fgets(input, SIZE, stdin);
    length = strlen(input);
    input[length-1]='\0';   //remove \n character
    if(access(input, R_OK) < 0)
    {
        printf("Invalid data \"%s\" for reading. Process terminating.\n", input);
        return -1;
    }
    printf("\"%s\" is your input value and has been accepted.\n", input);
    
    // gather output
    printf("Please enter output file location$$: ");
    fgets(output, SIZE, stdin);
    length = strlen(output);
    output[length-1]='\0';  // remove \n character
    if( strcmp(output, "")==0 ){
        printf("Invalid entry. Process terminating.\n");
        return -2;
    }
    else if(access(output, R_OK) == 0 && (strcmp(output, "./")!=0)){
        printf("Invalid, file/directory \"%s\" exists. Process terminating.\n", output);
        return -2;
    }
    else;
    printf("\"%s\" is your output value and has been accepted.\n", output);
    
    // filter directory or file selection.
    dp = opendir(input);
    if(dp!=NULL){
        closedir(dp);
        mydirectory(input, output);
    }
    else{
        if(copy(input, output)<0)
            exit(1);
    }
    
    printf("\nYour file(s)/directory has been copied to \"%s\"\n", output);
    
    return 0;
}

int mydirectory(char *input, char *output){

    DIR *dirp = opendir(input);
    struct dirent *dp=NULL;
    struct dirent *outdp=NULL;
    if (dirp == NULL)
        return (-5);
    //len = strlen(name);
    char name[1000];
    if(mkdir(output, 0777)!=0){
        printf("Directory creation failure\n");
        return -6;
    }
    char outputname[1000];
    while ((dp = readdir(dirp)) != NULL) {
        
        if(dp->d_name[0] != '.'){
            // set output path name for directory
            strcpy(outputname, output);
            if(strcmp(output, "./")!=0)
                strcat(outputname, "/");
            strcat(outputname, dp->d_name);
            // set input path name for directory
            strcpy(name, input);
            strcat(name, "/");
            strcat(name, dp->d_name);
            
            printf("\nreading file: %s\n", name);
            printf("writing file: %s\n", outputname);
            copy(name, outputname);
            // reset values
            memset(outputname, '\0', sizeof(outputname));
            memset(name, '\0', sizeof(name));
        }
    }
    closedir(dirp);
    return 0;
    
    
}



int copy(char *input, char *output){
    
    int fd1, fd2, i = 0, fileSize = 0;
    char buff;

    if ((( fd1 = open (input, O_RDONLY)) == -1) ||
        ((fd2 = open (output, O_CREAT|O_WRONLY|O_EXCL, 0755)) == -1)){
        printf("Invalid filenames/location.\n");
        return -1;
    }
    
    int x = 0, y = 0;
    // lseek returns offset location measured in bytes(use to set filesize)
    fileSize = lseek(fd1, 0, SEEK_END);
    lseek(fd2, fileSize, SEEK_SET);                   // offset output file to allocate space
    lseek(fd1, 0, SEEK_SET);                          // rewind input file
    lseek(fd2, 0, SEEK_SET);                          // rewind output file
    while (++i <= fileSize && (read(fd1, &buff, 1) > 0)){
        write(fd2, &buff, 1);
    }
    close(fd1);
    close(fd2);
    return 0;
    
    
}

