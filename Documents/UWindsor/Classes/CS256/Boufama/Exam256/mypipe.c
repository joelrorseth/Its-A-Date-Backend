//
//  mypipe.c
//  
//
//  Created by Ryan Pearson on 04-14-2014.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


int
main(int argc, char *argv[])
{
    int fd;
    unlink("myfifo");
    mkfifo("myfifo", 0777);
    
    if (!fork()) {
        fd=open("myfifo", O_WRONLY);
        dup2(fd, 1);
        system(argv[1]);
        close(fd);
    }
    else{
        fd=open("myfifo", O_RDONLY);
        dup2(fd, 0);
        system(argv[2]);
        close(fd);
    }
    unlink("myfifo");
    return 0;
}