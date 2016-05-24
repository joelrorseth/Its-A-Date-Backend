//
//  finalclient.c
//  
//
//  Created by Ryan Pearson on 04-09-2014.
//
//

#include <stdio.h>

int
main(int argc, char *argv[])
{
    int server, portNumber,n, fd;
    struct sockaddr_in servAdd;
    char fileName[255];
    
    
    server = socket(AF_INET, SOCK_STREAM, 0);
    servAdd.sin_family=AF_INET;
    sscanf(argv[2], "%d", &portNumber);
    servAdd.sin_port= htons((uint16_t)portNumber);
    
    if(inet_pton(AF_INET, argv[1], &servAdd.sin_addr) < 0){
        fprintf(stderr, "inet_pton fail\n");
        exit(1);
    }
    
    if ((connect(server, (struct sockaddr*) &servAdd, sizeof(servAdd)))< 0) {
        fprintf(stderr, "connection fail\n");
        exit(2);
    }
    
//    printf("Please enter file to create: ");
//    scanf("%s", fileName);
//    strcat(fileName, "\n");
//    write(server, filename, sizeof(filename));
//    while (fileName[0]!='$') {
//        fgets(fileName, 254, stdin);
//        strcat(fileName, "\n");
//        write(server, fileName, sizeof(fileName));
//    }
    
    printf("Please enter file to upload: ");
    scanf("%s", file);
    strcat(file, "\n");
    
    write(server, file, strlen(file));
    
    fd=open(file, O_RDONLY);
    while (n=read(fd, file, 255)<0) {
        write(fd, file, n);
    }
    return 0;
}
