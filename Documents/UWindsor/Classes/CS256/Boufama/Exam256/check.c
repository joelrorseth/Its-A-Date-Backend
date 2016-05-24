//
//  check.c
//  
//
//  Created by Ryan Pearson on 04-06-2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    int fd, i;
    char buffer = 'A';
    fd = open( "test2.txt", O_RDWR );
    i = lseek( fd, -1, SEEK_END );
    printf("%d", i);
    while( i-- >= 0 ){
        write( fd, &buffer, 1 );
        lseek( fd, -2, SEEK_CUR );
    }
    close( fd );
}