//
//  Assignment6
//  AssignClient.c
//  Ryan Pearson
//  SID: 103965059
//  Date: 03-23-2014
//

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

void readerChild(int fd);

int
main(int argc, char* argv[])
{
    int fd1, ff1, ff2, filemade, ch=0;
    char fifoName1[100]="./server5011", value[100]="", fileName[100];
    char fifoImport1[100]="./fifo", fifoImport2[100]="./fifo";
    pid_t pid;
    
    // open the initial fifo to the server for writing
    while((fd1 = open(fifoName1, O_WRONLY)) == -1) {
        fprintf(stderr, "Trying to connect\n");
        sleep(1);
    }

    // assign proper values to names of fifo's
    sprintf(value, "%d", getpid());
    strcat(fifoImport1, value);
    strcat(fifoImport1, "_1");
    strcat(fifoImport2, value);
    strcat(fifoImport2, "_2");
    printf("Opening as clientpid %d\n", getpid());
    write(fd1, value, sizeof(value));
    
    // give time to create fifo's on the server side
    sleep(1);
    
    while((ff2 = open(fifoImport2, O_WRONLY)) == -1) {
        fprintf(stderr, "Trying to connect %s\n", fifoImport2);
        sleep(1);
    }
    
    // get name of file and write it to the fifo
    printf("Please enter the name of the file you wish to receive: \n");
    scanf("%s", fileName);
    write(ff2, fileName, sizeof(fileName));
    
    while((ff1 = open(fifoImport1, O_RDONLY)) == -1) {
        fprintf(stderr, "Trying to connect %s\n", fifoImport1);
        sleep(1);
    }
    
    // check for invalid file name
    read(ff1, &ch, 1);
    if (ch=='\0') {
        printf("Invalid File Name, no transfer will occur.Bye\n");
        exit(1);
    }
    else{
        filemade = open("Newfile.txt", O_CREAT|O_WRONLY|O_TRUNC, 0777);
        write(filemade, &ch, 1);
    }
    
    // transfer file and exit.
    while(read(ff1, &ch, 1)==1)
        write(filemade, &ch, 1);
    printf("You have received your file. Please look on your Desktop.\nBye!\n\n");
    exit(1);
}
