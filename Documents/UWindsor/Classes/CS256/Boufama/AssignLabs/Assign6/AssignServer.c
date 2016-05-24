,//
//  Assignment6
//  AssignServer.c
//  Ryan Pearson
//  SID: 103965059
//  Date: 03-23-2014
//

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void readerChild(int fd, char pid[50]);
void myaction();

int main(int argc, char *argv[]){
    int fd1, fd2, status;
    char ch, fifoName1[100]="./server", clientPID[50], name[50], str[50], junk[50];
    pid_t pid;
    struct sigaction sa;
    sa.sa_handler
    
    //establish server name via UID and create fifo
    sprintf(str, "%d" , getuid());
    strcat(fifoName1, str);
    strcat(fifoName1, "1");

    unlink(fifoName1);

    if(mkfifo(fifoName1, 0777)){
        perror("main could not create fifo");
        exit(1);
    }
    
    while(1){
        sleep(1);   // use this to stall process to let child exit after client found initially
        printf("\nUserID: %u\n", getuid());
        fprintf(stderr, "Waiting for client\n\n");
        fd1= open(fifoName1, O_RDONLY);
        read(fd1,&clientPID,50);
        //gather blank junk entry?
        read(fd1, &junk, 50);
        if (!(pid=fork())){
            fprintf(stderr, "clientPID %s received.\n", clientPID);
            fprintf(stderr, "Awaiting fileName for transfer...");
            readerChild(fd1, clientPID);
        }
        close(fd1);
        waitpid(fd1, &status, WNOHANG);
    }
}

void readerChild(int fd, char *pid){
    
    char cfifo1[50]="fifo", cfifo2[50]="fifo", name[50]="";
    int fdfile, ff1, ff2, value;
    
    // create fifo's for reading and writing between client and server.
    strcat(cfifo1, pid);
    strcat(cfifo1, "_1");
    strcat(cfifo2, pid);
    strcat(cfifo2, "_2");
    
    unlink(cfifo1);
    unlink(cfifo2);
    
    if (mkfifo(cfifo1, 0777)){
        perror("child could not create fifo1");
        exit(1);
    }
    
    if (mkfifo(cfifo2, 0777)){
        perror("child could not create fifo2");
        exit(1);
    }
    ff2=open(cfifo2, O_RDONLY);
    ff1=open(cfifo1, O_WRONLY);
    
    while(strlen(name)==0){
        fflush(stdout);
        read(ff2, name, 50);
        sleep(2);
    }

    // display name of file to transfer, then open file for reading
    // else exit child.
    printf("\nFile to transfer: %s\n", name);
    if((fdfile = open(name, O_RDONLY, 0777))==-1){
        //char invalid[100]="You have requested an invalid file.\nPlease try again.\n";
        printf("Invalid file name, no transfer will occur.\n");
        char invalid='\0';
        write(ff1, &invalid, 1);
        unlink(cfifo1);
        unlink(cfifo2);
        exit(1);
    }
    
    // read from open file and write to fifo
    fprintf(stderr, "Initiating transfer...\n");
    while(read(fdfile, &value, 1)==1)
        write(ff1, &value, 1);

    // remove link to client after transfer
    unlink(cfifo1);
    unlink(cfifo2);
    
    // give time for client to exit so does not register another client.
    sleep(1);
    printf("File Transfer Complete for client %s. Bye", pid);
    exit(1);
    
}