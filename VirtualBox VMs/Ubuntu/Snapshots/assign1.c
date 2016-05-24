//
//  assign1.c
//  
//
//  Created by Ryan Pearson on 05-12-2016.
//  to use dtrace to scan system calls invoke sudo dtrace -c ./a.out -l | grep 'syscall'
//


#include "assign1.h"
int copy(char *input, char *output);


int
main(void){
    
    char input[SIZE];
    char output[SIZE];
    size_t length;
    DIR *dp;
    printf("%d", getpid());
    printf("Please enter input file location$$: ");
    fgets(input, SIZE, stdin);
    length = strlen(input);
    input[length-1]='\0';   //remove \n character
    // look up fts for directory searching.
    dp = opendir(input);
    if(dp!=NULL){
        printf("You have provided a directory, this program does not contain that functionality\n");
        closedir(dp);
        return -3;
    }
    
    
    if(access(input, R_OK) < 0)
    {
        printf("Invalid file \"%s\" for reading. Process terminating.\n", input);
        return -1;
    }
    printf("\"%s\" is your input and has been accepted.\n", input);
    printf("Please enter output file location$$: ");
    fgets(output, SIZE, stdin);
    length = strlen(output);
    output[length-1]='\0';  // remove \n character
    if(access(output, R_OK) == 0 ){
        printf("Invalid, file with \"%s\" exists. Process terminating.\n", output);
        return -2;
    }
    printf("\"%s\" is your output and has been accepted.\n", output);
    for(int x=0; x < 3; x++){
        if(x==0)
            if(copy(input, output)<0){
                printf("Invalid parameters");
                exit(1);
            }
        sleep(1);
        write(STDERR_FILENO, ".", 1);
    }
    printf("\nBooyah! Your file has been copied to \"%s\"\n", output);
    
    
}




int copy(char *input, char *output){
    
    int fd1, fd2, i = 0, fileSize = 0;
    char buff;
    
    if ((( fd1 = open (input, O_RDONLY)) == -1) ||
        ((fd2 = open (output, O_CREAT|O_WRONLY|O_EXCL, 0755)) == -1)){
        printf("Invalid file open\n");
        return -1;
    }
    
    int x = 0, y = 0;
    // lseek returns offset location measured in bytes(use to set filesize)
    fileSize = lseek(fd1, 0, SEEK_END);
    lseek(fd2, fileSize, SEEK_SET);                   // offset output file
    lseek(fd1, 0, SEEK_SET);                            // rewind input file
    lseek(fd2, 0, SEEK_SET);
    while (++i < fileSize+1 && (read(fd1, &buff, 1) > 0)){
        //lseek(fd2, -i, SEEK_END);
        write(fd2, &buff, 1);
    }
    close(fd1);
    close(fd2);
    return 0;
    
    
}

